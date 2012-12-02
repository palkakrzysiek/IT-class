#include <stdio.h>
#include <string.h>

void fortune_cookie(char msg[]){
    printf("Message reads: %s\n", msg);
    printf("Message occupies %i bytes\n", sizeof(msg));

}
void skip(char *msg){
    puts(msg + 6);
}
void print_reverse(char *s){
    size_t len = strlen(s);
    printf("%d\n", len);
    for(int i = 1; i <= len; i++){
        printf("%c", *(s + len - i));
    }
    puts("");
}


int main(int argc, char const* argv[])
{
    print_reverse("ABC");
    int x = 4;
    printf("x is stored at %p\n", &x);
    char quote[] = "Cookies make you fat";
    printf("Message occupies %i bytes\n", sizeof(quote));
    fortune_cookie(quote);
    char msg_from_amy[] = "Don't call me";
    skip(msg_from_amy);
    char food[3];
    scanf("%s", &food);
    puts(food);
    *(food+5)=32;
    puts(food + 3);
    printf("%i, %i", (int)&quote, (int)&food);
    return 0;
}
