#include <cstdio>


int insertion_sort(int n, int *T){
    int i;
    for(i = 1; i < n; i++){
        int key = T[i];
        // wprowadź T[i] do posortowanej sekwencji A[1... i - 1].
        int j = i - 1;
        while(j >= 0 && T[j] > key){
            T[j + 1] = T [j];
            j--;
        }
        T[j + 1] = key;
    }
    return 0;
}

//Divide and rule
void combine(int *T, int a, int b, int c){
    int *Zanel = new int[c-a+1];
    int m = a, k = b, i = 0;
    while(m<b && (i <= c - a)){
        if(k > c || T[m] > T[k]){
            Zanel[i] = T[m];
            ++m;
        }
        else {
            Zanel[i] = T[k];
            ++k;
        }
        ++i;
    }
    // copy tem array to the old one
}

void mergeSort(int *T, int a, int c){
    if(c - a < 1) return;
    int b = ((a+c)/2) + 1; //devide O(1)
    mergeSort(T, a, b-1);
    mergeSort(T, b, c);
    combine(T, a, b, c);
}



int main(int argc, char const* argv[])
{
    int n = 5;
    int m[] = {32, 12, 43,65,42,73,11,24};
    int t[n];
    t[0] = 5;
    t[1] = 3;
    t[2] = 7;
    t[3] = 1;
    t[4] = 9;

    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%i ", t[i]);
    }

    puts("");
    insertion_sort(n, t);
    for (i = 0; i < n; i++) {
         printf("%i ", t[i]);
     }


    puts("");
    for (i = 0; i < 8; i++) {
        printf("%i ", m[i]);
    }

    puts("");
    mergeSort(m, 0, 7);
    for (i = 0; i < 8; i++) {
         printf("%i ", m[i]);
     }
    return 0;
}
