#include <cstdio>

void bublesort(int *T, int n){
    int temp;
    for (int i = 1; i < n - 1; i++){	 	 	// n - 1 times
        for(int j = n - 1; j > i; j--){
            if(T[j] < T[j-1]){
                temp = T[j];
                T[j] = T[j-1];
                T[j-1] = temp;
            }
        }
    }
}

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);
    int *tab = new int[n];
    int temp;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        tab[i] = temp;
    }
    for(int i = 0; i < n; i++)
        printf("%d ", tab[i]);
    puts("");
    bublesort(tab, n);
    for(int i = 0; i < n; i++)
        printf("%d ", tab[i]);
    puts("");

    return 0;
}
