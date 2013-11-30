#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream.h>

#define CLOCK_INT 0x1C
#define KEYBOARD_INT 0x09
#define COLORS 0x13
const int START_X = 80 - 8;

void interrupt (*KeyboardOldInt)(...);
void interrupt (*ClockOldInt)(...);


static int show_clock = 0;

// 2*3 for hh, mm, ss + 2 for colons + 1 for 0x00
static char oldText[8*2];
static char newClock[9];
static char oldClock[9];


void interrupt KeyboardInt(...)
{
  {
    int c = inportb(0x60);
    if (c == 87) { // if F11 pressed
      show_clock = (show_clock?0:1);

      int i = 0;
      if (show_clock) {
        // copy previous text and colors
        // it will work only during showing clock, not if text will change
        // when clock is already shown
        for (i = 0; i < 8; ++i) {
          char currentByteChar = peekb(0xb800,  i * 2 + START_X * 2);
          char currentByteColor = peekb(0xb800,  i * 2 + START_X * 2 + 1);
          if (currentByteChar != oldText[i*2]) {
            oldText[i*2] = currentByteChar;
          }
          if (currentByteColor != COLORS)
            oldText[i*2 + 1] = currentByteColor;
        }
      }
      else {
        // if clock is hidded restore previous text and colors
        for (i = 0; i < 8 * 2; ++i) {
          pokeb(0xb800,  START_X * 2 + i, oldText[i]);
        }
      }
    }
  }
  // execute default keyboard interrupt
  KeyboardOldInt();
}

void interrupt ClockInt(...)
{

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

  newClock[0] = (hour >> 4) + '0';
  newClock[1] = (hour & 0x0f) + '0';
  newClock[2] = ':';
  newClock[3] = (minute >> 4) + '0';
  newClock[4] = (minute & 0x0f) + '0';
  newClock[5] = ':';
  newClock[6] = (second >> 4) + '0';
  newClock[7] = (second & 0x0f) + '0';
  newClock[8] = 0;

  int i = 0;

  if (show_clock) {
    // check if text have been changed form between executions of this function
    for (i = 0; i < strlen(newClock); ++i) {
      char currentByteChar = peekb(0xb800,  i * 2 + START_X * 2);
      char currentByteColor = peekb(0xb800,  i * 2 + START_X * 2 + 1);
      // compare with old clock values, not with old text
      if (currentByteChar != oldClock[i]) {
        oldText[i*2] = currentByteChar;
      }
      if (currentByteColor != COLORS) {
        oldText[i*2 + 1] = currentByteColor;
      }

      // set new values
      pokeb(0xb800,  START_X * 2 + i * 2, newClock[i]);
      pokeb(0xb800,  START_X * 2 + i * 2 + 1, COLORS);
    }
  }
  strcpy(oldClock, newClock);

  outp(0x20, 0x20);
  ClockOldInt();
}

int main()
{
  ClockOldInt = getvect(CLOCK_INT);
  KeyboardOldInt = getvect(KEYBOARD_INT);

  setvect(KEYBOARD_INT, KeyboardInt);
  setvect(CLOCK_INT, ClockInt);


  // _psp -- starting address of memory
  // _SS & _SP to get adress of the end of the stack
  keep(0, (_SS + (_SP / 16) - _psp));

  return 0;
}
/* vim: set sw=2: */
