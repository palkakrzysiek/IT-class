#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>

const int termSizeX = 80;
const int termXCenter = termSizeX/2;
const int termSizeY = 25;
const int termYCenter = termSizeY/2;
const int defaultBg = 0x0f;
const int defaultFg = 0x00;
enum { UP, DOWN, LEFT, CENTER, RIGHT };
const int graphicOffset = 0xB800;

const char k_plus_press = 78;
const char k_minus_press = 74;
const char k_up_press = 72;
const char k_down_press = 80;
const char k_left_press = 75;
const char k_down_press = 77;
const char k_plus_release = 206;
const char k_minus_release = 202;
const char k_up_release = 72;
const char k_down_release = 208;
const char k_left_release = 203;
const char k_down_release = 205;


class Terminal {
    public:
        Terminal(int f = defaultFg, int b = defaultBg) : fg(f), bg(b) {_setcursortype(_NOCURSOR);}
        ~Terminal() {_setcursortype(_NORMALCURSOR);}
        void clear();
        void setFg(int x = defaultBg) {fg = x % 0x0f;}
        void setBg(int x = defaultFg) {bg = x % 0x0f;}
        void changeFg() {fg = (fg + 1) % 0x0f;}
        void changeBg() {bg = (fg + 1) % 0x0f;}
        void setChar(int x = 0, int y = 0, int f = defaultFg, int b = defaultBg,
                char c = ' ' );
        int getBg() {return bg;}
        int getFg() {return fg;}
    private:
        int fg;
        int bg;

};

class Text {
    public:
        Text(const char str[], int x, int y, int a, int c, int b) ;
        ~Text();
        void show(Terminal & t);
    private:
        int xPos;
        int yPos;
        int color;
        int background;
        int strLen;
        int align;
        char str[termSizeX];
        Terminal * term;
};




int main(int argc, char const* argv[])
{
    Terminal t(2, 5);
    Text txt("CompArch is the best subject ever!", termXCenter,
           termYCenter, CENTER, 0, 10);
    t.clear();
    t.changeBg();
    t.clear();
    txt.show(t);
    getch();
    return 0;
}




void Terminal::setChar(int x, int y, int fgColor, int bgColor, char c) {
    pokeb(graphicOffset, (y % termSizeY) * termSizeX * 2 +
            (x % termSizeX) * 2, c);
    pokeb(graphicOffset, (y % termSizeY) * termSizeX * 2 + 
            (x % termSizeX) * 2 + 1, (fgColor % 0x0f) + 0x0f * (bgColor % 0x0f));
}

void Terminal::clear() {
    for (int i = 0; i < termSizeX; i++) {
        for (int j = 0; j < termSizeY; j++) {
            this->setChar(i, j, fg, bg, ' ');
        }
    }
}

Text::Text(const char s[], int x, int y, int a, int c, int b) :
    xPos(x), yPos(y), align(a), color(c), background(b), strLen(strlen(s)) {
        strncpy(str, s, termSizeX);
        switch (align) {
            case CENTER:
                xPos = x - strLen / 2;
                break;
            case RIGHT:
                xPos = x - strLen;
                break;
            case LEFT:
            default:
                xPos = x;
                break;
        }
}

void Text::~Text() {
    for (int i = 0; i < strLen; i++) {
        if (term != NULL) 
            term->setChar(xPos + i, yPos, term->getFg(), term->getBg(), ' ');
    }
}

void Text::show(Terminal & term) {
    for (int i = 0; i < strLen; i++) {
        this->term = &term; // set last used terminal
        term.setChar(xPos + i, yPos, color, background, str[i]);
    }
}
