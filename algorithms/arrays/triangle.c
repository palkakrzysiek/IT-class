#include <stdio.h>
void tab(int n, int tab[][7], int m){
    if(m == n)
        return;
    int i = 0;
    while(i<=m)
        tab[m][i] = ++i;
    while(i<n)
        tab[m][i] = ++i;
    return(n, tab[][n]);

}

int main(int argc, char const* argv[])
{
    int n = 7;
    int tab[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
    return 0;
}
