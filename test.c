#include <stdio.h>

int main(int argc, char const* argv[])
{
    int i;
    for (i = 0; i <= 128; i++) {
        printf("%i: %c; ", i, (char)i);
        if(i%4==0) puts("");
    }
    return 0;
}
