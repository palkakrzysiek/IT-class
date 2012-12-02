#include <stdio.h>

int find(int N, int x, int *T){
    for(int i = 0; i < N; ++i){
        if(T[i] == x){
            return i;
        }
    }
    return -1;
}

void sort(*T, int N){
    for(int i = 1; i < N; i++){
        int key = T[i];
        int j = i - 1;
        while(j >= 0 && T[j] > key){
           T[j + 1] = T [j];
           j--;
        }
        T[j + 1] = key;
    }

    }
}

int mediana(*T, int n){
    if(n%2 == 1){
        int srodek = n/2+1
    }
    else{
        int srodek = (n/2+n/2+1)/2;
    }
    sort(*T, n);
    return T[srodek];
}

int min(int *T,int  n){
    int minimum = T[0];
    int i = 1;
    while(i < n){
        if(T[i] < minimum){
            minimum = T[i];
        }
        i++;
    }
    return minimum;
}

int indexMin(int *T, int n){
    int indexOfmin = 0;
    int i = 1;
    while(i < n){
        if(T[i] < T[indexOfmin]){
            indexMin = i;
        }
        i++
    }
    return indexMin;
}

int main(int argc, char const* argv[])
{
    int Z[8] = {1, 2, 4, 5, 9, 2, 3, 4};
    int iloscElementow = 8;
    int szukana = 3;
    printf("%d", find(iloscElementow, szukana, &Z));
    if(find(iloscElementow, szukana, &Z) == -1)
        puts("nie ma takiej liczby");
    return 0;
}
