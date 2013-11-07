#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>

int main(){
    _setcursortype(_NOCURSOR);
    short int x, y, txtcolor, bgcolor, ch, len;
    char *str;
    str = "text";
    len = strlen(str);
    x = 40;
    y = 12;
    txtcolor = 15;
    bgcolor = 0;
    clrscr();
    while(inportb(0x60) != 1){
        gotoxy(x, y);
        cout << str;
        {
            for (int i=-1; i<len-1; ++i){
                pokeb(0xB800, (0x0000 + (y-1)*160 + (x+i)*2 + 1), (bgcolor*16)+txtcolor);
            }
        }
        delay(50);
        getch();
        ch = inportb(0x60);
        {
            for (int i=-1; i<len; ++i){
                pokeb(0xB800, (0x0000 + (y-1)*160 + (x+i)*2 + 1), 0);
            }
        }
        switch(ch){
            case 72: //up
                if (y > 1)
                    --y;
                break;
            case 75: //left
                if (x > 1)
                    --x;
                break;
            case 77: //right
                if (x < (80-len))
                    ++x;
                break;
            case 80: //down
                if (y < 25)
                    ++y;
                break;
            case 13: //plus
                if (txtcolor < 15)
                    ++txtcolor;
                else
                    txtcolor = 0;
                break;
            case 12: //minus
                if (bgcolor < 15)
                    ++bgcolor;
                else
                    bgcolor = 0;
                break;
        }
    }
    _setcursortype(_NORMALCURSOR);
    return 0;
}
