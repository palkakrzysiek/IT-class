#include <stdio.h>
int count_chars(char *text){
    int i = 0;
    while (text[i] != 0){
        ++i;
    }
    return i;
}
int fifo(char *line){
    int len, max_len;
    len = max_len = count_chars(line);
    while(--len){
        // printf("%i [%c]: %s\n", len, line[len], line); //debug
        if (line[len - 1] < line[len]){
            line[len-1]=line[len];
            max_len--;
            int i;
            for(i = len; i <= max_len; ++i){
                line[i]=line[i+1];
            }
        }
    }
    return 0;
}
int main(int argc, char const* argv[])
{
    int t;
    scanf("%d", &t);
    int maxStrLen = 10000000 / t;
    if (maxStrLen > 1000000) maxStrLen = 1000000;
    char tekst[maxStrLen];
    while(t--){
        scanf("%s", &tekst);
        fifo(tekst);
        puts(tekst);
        
    }
    return 0;
}
