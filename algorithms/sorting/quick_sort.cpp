#include <ctime>
#include <cstdio>
#include <cstdlib>

int* getRandomArray(int n, int min, int max){
    // require ctime and cstdlib 
    srandom(time(0));
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = random() % (max + 1) + min;
    }
    return arr;
}

void printarray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    putchar('\n');
}

void exchange(int *A, int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition(int *A, int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(A[j] <= x){
            i++;
            exchange(A, j, i);
        }
    }
    exchange(A, i+1, r);
    return i+1;
}

void quicksort(int *A, int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int main(int argc, char const* argv[])
{
    int *temp;
    for(int i = 1; i <= 31; i += 5){
        temp = getRandomArray(i, 0, 25);
        printarray(temp, i);
        quicksort(temp, 0, i - 1);
        printarray(temp, i);
        delete [] temp;
    }

    return 0;
}
