#include <dos.h>
#include <string.h>

// przykładowy kolor tekstu zegara, możesz się pobawić z innymi
#define COLORS 0x2f
// pozycja w której ma być wyświetlany
const int POSITION = 12*80 + 36;

void interrupt (*KeyboardOldInt)(...);
void interrupt (*ClockOldInt)(...);


static int show_clock = 0;

// 2*3 for hh, mm, ss + 2 for colons + 1 for 0x00
// oldText -- żeby przechować poprzednie znaki i wartości kolorów
static char oldText[8*2];
static char newClock[9];


void interrupt KeyboardInt(...)
{
  {
    int c = inportb(0x60);
    if (c == 59) { // if F1 pressed
      show_clock = (show_clock?0:1);

      int i = 0;
      if (show_clock) {
        // copy previous text and colors
        // it will work only during showing clock, not if text will change
        // when clock is already shown
        for (i = 0; i < 8; ++i) {
          // peekb to funkcja odwrotna do pokeb; pobiera wartość danego bajtu
          // sprawdź poprzedni znak
          char currentByteChar = peekb(0xb800,  i * 2 + POSITION * 2);
          // sprawdź poprzedni kolor
          char currentByteColor = peekb(0xb800,  i * 2 + POSITION * 2 + 1);

          oldText[i*2] = currentByteChar;
          oldText[i*2 + 1] = currentByteColor;
        }
      }
      else {
        // if clock is hided restore previous text and colors
        for (i = 0; i < 8 * 2; ++i) {
          pokeb(0xb800,  POSITION * 2 + i, oldText[i]);
        }
      }
    }
  }
  // execute default keyboard interrupt
  KeyboardOldInt();
}

void interrupt ClockInt(...)
{

  // to jest po porostu przepisane z przykładowych kodów, nie zastanawiałem
  // się zbytnio co się tu dzieje
  signed char hour, minute, second; // bcd values, read them from CMOS clock
  outport(0x70, 4);
  hour = inportb(0x71);
  outport(0x70, 2);
  minute = inportb(0x71);
  outport(0x70, 0);
  second = inportb(0x71);

  // numbers are stored in format 01010101
  //                  first digit ^^^^
  //                     second digit ^^^^

  // przesunięcie o 4 bity w prawo, żeby wydobyć pierwszą cyfrę
  // następnie, żeby otrzymać kod ASCII odpowiadający cyfrze dodaje się
  // wartość znaku '0'
  newClock[0] = (hour >> 4) + '0';
  // dzięki modulo odrzuci się pierwszą cyfrę, zostanie tylko druga
  newClock[1] = (hour % 16) + '0';
  newClock[2] = ':';
  newClock[3] = (minute >> 4) + '0';
  newClock[4] = (minute % 16) + '0';
  newClock[5] = ':';
  newClock[6] = (second >> 4) + '0';
  newClock[7] = (second % 16) + '0';
  newClock[8] = 0;

  int i = 0;


  if (show_clock) {
    for (i = 0; i < 8; i++) {
      // set new values
      pokeb(0xb800,  POSITION * 2 + i * 2, newClock[i]);
      pokeb(0xb800,  POSITION * 2 + i * 2 + 1, COLORS);
    }
  }

  ClockOldInt();
}

int main()
{
  ClockOldInt = getvect(0x08);
  KeyboardOldInt = getvect(0x09);

  setvect(0x09, KeyboardInt);
  setvect(0x08, ClockInt);


  // zachowuje program w pamięci i pozwala na uruchomienie innych programów
  keep(0, (_SS + (_SP / 16) - _psp));

  return 0;
}
