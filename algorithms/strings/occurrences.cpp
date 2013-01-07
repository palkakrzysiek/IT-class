/* Let T and P be strings. Find how many times P appears in T – appearances can overlap. */
#include <string.h>
#include <cstdio>
int occurrences(char *T, char *P){
    int counter = 0;
    int T_len = strlen(T);
    int P_len = strlen(P);
    for(int i = 0; i < T_len; i++){
        for(int j = 0; j < P_len; j++){
            if (T[i + j] == P[j]) { 
                if (j == P_len - 1) 
                    counter++;
            }
            else
                break;
        }
    }
    return counter;
}

int main(int argc, char const* argv[])
{
    char a[] = "abababaaba";
    char b[] = "aba";
    printf("%d\n", occurrences(a, b));

    return 0;
}
