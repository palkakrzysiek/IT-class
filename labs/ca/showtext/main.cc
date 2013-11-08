#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>

const int termSizeX = 80;
const int termXCenter = termSizeX/2;
const int termSizeY = 24;
const int termYCenter = termSizeY/2;

const int defaultBg = 0x06;
const int defaultFg = 0x0f;

enum { DEFAULT, UP, DOWN, LEFT, CENTER, RIGHT, PLUS, MINUS, ESC};

const int graphicOffset = 0xB800;
const int keyboardPort = 0x60;

const char k_plus_press = 78;
const char k_minus_press = 74;
const char k_up_press = 72;
const char k_down_press = 80;
const char k_left_press = 75;
const char k_right_press = 77;
const char k_esc_press = 1;
const char k_plus_release = 206;
const char k_minus_release = 202;
const char k_up_release = 200;
const char k_down_release = 208;
const char k_left_release = 203;
const char k_right_release = 205;
const char k_esc_release = 129;


class Terminal {
    public:
        Terminal(int f = defaultFg, int b = defaultBg) : fg(f), bg(b) {_setcursortype(_NOCURSOR);}
        ~Terminal() {_setcursortype(_NORMALCURSOR);}
        void clear();
        void setFg(int x = defaultBg) {fg = x % 0x10;}
        void setBg(int x = defaultFg) {bg = x % 0x10;}
        void changeFg() {fg = (fg + 1) % 0x10;}
        void changeBg() {bg = (fg + 1) % 0x10;}
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
        Text(const char str[], int x, int y, int a, int c, int b);
        ~Text();
        void clean();
        void show(Terminal & t);
        void move(int x, int y);
        void setStyle(int fg, int bg);
        void changeStyle(int fg, int bg);
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

class Keyboard {
    public:
        Keyboard() {}
        int getchar();
    private:
        char lastchar;
};


int main(int argc, char const* argv[])
{
    Terminal t;
    t.clear();

    Keyboard k;

    Text txt[4] = {
    Text("    There is a theory which states that if ever anyone discovers exactly", 2, termYCenter - 3, LEFT, 7, DEFAULT),
    Text("what the Universe is for and why it is here, it will instantly disappear", 2, termYCenter - 2, LEFT, 7, DEFAULT),
    Text("and be replaced by something even more bizarre and inexplicable.", 2, termYCenter -1, LEFT, 7, DEFAULT),
    Text("There is another theory which states that this has already happened.", termSizeX -2, termYCenter + 1, RIGHT, 0x0a, DEFAULT)
    };

    Text lt("Left top corner", 0, 0, LEFT, 0x00, 0x04);
    Text rt("Right top corner", termSizeX, 0, RIGHT, 0x00, 0x04);
    Text bt("Left bottom corner", 0, termSizeY, LEFT, 0x00, 0x04);
    Text br("Right bottom corner", termSizeX, termSizeY, RIGHT, 0x00, 0x04);

    lt.show(t);
    rt.show(t);
    bt.show(t);
    br.show(t);

    int i = 0;

    for (i = 0; i < 4; i++)
        txt[i].show(t);

    char c;
    while ((c = k.getchar()) != ESC) {
        for (i = 0; i < 4; i++)
            txt[i].clean();
        for (i = 0; i < 4; i++) {
            switch (c) {
                case UP:
                    txt[i].move(0, -1);
                    break;
                case DOWN:
                    txt[i].move(0, 1);
                    break;
                case LEFT:
                    txt[i].move(-1, 0);
                    break;
                case RIGHT:
                    txt[i].move(1, 0);
                    break;
                case MINUS:
                    txt[i].changeStyle(0,1);
                    break;
                case PLUS:
                    txt[i].changeStyle(1,0);
                    break;
                default:
                    break;
            }
        }

        for (i = 0; i < 4; i++)
            txt[i].show(t);

        lt.show(t);
        rt.show(t);
        bt.show(t);
        br.show(t);
    }
    return 0;
}




void Terminal::setChar(int x, int y, int fgColor, int bgColor, char c) {
    pokeb(graphicOffset, (y % (termSizeY+1)) * termSizeX * 2 +
            (x % termSizeX) * 2, c);
    pokeb(graphicOffset, (y % (termSizeY+1)) * termSizeX * 2 + 
            (x % termSizeX) * 2 + 1, (fgColor % 0x10) + 0x10 * (bgColor % 0x10));
}

void Terminal::clear() {
    for (int i = 0; i < termSizeX; i++) {
        for (int j = 0; j <= termSizeY; j++) {
            this->setChar(i, j, fg, bg, ' ');
        }
    }
}

Text::Text(const char s[], int x, int y, int a, int c, int b) :
    xPos(x), yPos(y), align(a), color(c), background(b), strLen(strlen(s)) {
        if (color == DEFAULT)
            if (term == NULL)
                color = defaultFg;
            else
                color = term->getFg();
        if (background == DEFAULT)
            if (term == NULL)
                background = defaultBg;
            else
                background = term->getBg();

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
    this->clean();
}

void Text::clean() {
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

void Text::move(int x, int y) {
    xPos = (xPos + x) % (termSizeX+1);
    if (yPos + y < 0) yPos = termSizeY;
    else yPos = (yPos + y) % (termSizeY+1);
}
void Text::setStyle(int fg, int bg) {
    color = fg % 0x10;
    background = bg % 0x10;
}
void Text::changeStyle(int fg, int bg) {
    color = (color + fg) % 0x10;
    background = (background + bg) % 0x10;
}

int Keyboard::getchar() {
    char c;
    while (1) {
        delay(10); // without 10 ms delay this function does not work for arrows in DosBox
        c = inportb(keyboardPort);
        if (c != lastchar) {
            if (c == k_up_release && lastchar == k_up_press){
                lastchar = NULL;
                return UP;
            }
            if (c == k_down_release && lastchar == k_down_press){
                lastchar = NULL;
                return DOWN;
            }
            if (c == k_left_release && lastchar == k_left_press){
                lastchar = NULL;
                return LEFT;
            }
            if (c == k_right_release && lastchar == k_right_press){
                lastchar = NULL;
                return RIGHT;
            }
            if (c == k_plus_release && lastchar == k_plus_press){
                lastchar = NULL;
                return PLUS;
            }
            if (c == k_minus_release && lastchar == k_minus_press){
                lastchar = NULL;
                return MINUS;
            }
            if (c == k_esc_release && lastchar == k_esc_press){
                lastchar = NULL;
                return ESC;
            }
            lastchar = c;
        }
    }
}
