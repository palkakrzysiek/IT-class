#include <cstdio>

void quicksort(int *T, int n){
    if(n<=1) return;
    int T1[n-1], T2[n-1];
    //int *T1 = new int[n-1];
    //int *T2 = new int[n-1];
    int x = T[0], j=0, k=0;
    for(int i = 0; i < n; i++){
        if(T[i] < x)
            T1[j++]=T[i];
        else
            T2[k++]=T[i];
    }
    quicksort(T1, j);
    quicksort(T2, k);
    //merge
    int c = 0;
    for(int i = 0; i < j; i++)
        T[c++]=T1[i];
    T[c++]=x;
    for(int i = 0; i < k; i++)
        T[c++]=T2[i];
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
    quicksort(tab, n);
    for(int i = 0; i < n; i++)
        printf("%d ", tab[i]);
    puts("");

    return 0;
}
