#include <dos.h>
#include <conio.h>
#include <iostream.h>

void main()
{
 clrscr();
 _setcursortype(_NOCURSOR);
 do
 {
  pokeb(0xB800, 0x0000 + (12 * 80 * 2) + (40 * 2) + 0,  'A');
  pokeb(0xB800, 0x0000 + (12 * 80 * 2) + (40 * 2) + 1, 0x4E);
 }
 while (getch() != 27);
 clrscr();
 _setcursortype(_NORMALCURSOR);
 
}
