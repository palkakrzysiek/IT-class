#include <dos.h>
#include <conio.h>
#include <iostream.h>

void main()
{
 unsigned char c;
 clrscr();
 _setcursortype(_NOCURSOR);
 do
 {
  gotoxy(40, 12);
  c = inportb(0x60);
  cout << (int)c << "   ";
 }
 while (c != 1);
 while (kbhit()) getch();
 clrscr();
 _setcursortype(_NORMALCURSOR);
}
