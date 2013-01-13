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


int main(int argc, char const* argv[])
{
    int *temp;
    for(int i = 1; i <= 31; i += 5){
        temp = getRandomArray(i, 0, 25);
        printarray(temp, i);
        insertion_sort(i, temp);
        printarray(temp, i);
        delete [] temp;
    }

    return 0;
}
