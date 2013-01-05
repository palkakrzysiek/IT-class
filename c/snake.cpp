#include <stdio.h>
#define X_SIZE = 20;
#define Y_SIZE = 15;

enum FIELD {HEAD, APPLE, EMPTY};
enum DIRECTION {UP, DOWN, LEFT, RIGHT, NONE};

int getDIRECTON()
{
	DIRECTION k = NONE;
    FIELD t;

	int i = 0;
	i = getchar();
	if (i == 119 || i ==  87)
		k = UP;
	if (i == 115 || i ==  83)
		k = DOWN;
	if (i == 97 || i ==  65)
		k = LEFT;
	if (i == 100 || i ==  68)
		k = RIGHT;
	return k;
}

int main(int argc, char const* argv[])
{
    int i;
    while((i = getchar(ungetc(stdin))) != EOF){
        printf("%d\n",i);
    }

    
    return 0;
}
