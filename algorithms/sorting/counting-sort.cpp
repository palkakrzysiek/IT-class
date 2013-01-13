#include <ctime>
#include <cstdio>
#include <cstdlib>

int* getRandomArray(int n, int min, int max){
    // require ctime and cstdlib 
    srandom(time(0));
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        arr[i] = random() % (max - min + 1) + min;
    }
    return arr;
}

void printarray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    putchar('\n');
}

int maxvalue(int *T, int n){
    int max = T[0];
    for(int i = 0; i < n; i++){
        if(T[i] > max)
            max = T[i];
    }
    return max;
}

void countingsort(int *A, int n){
    int k = maxvalue(A, n);
    int *B = new int[n];
    int *C = new int[k+1];
    for(int i = 0; i < k+1; i++)
        C[i] = 0;
    for(int i = 0; i < n; i++)
        C[A[i]]++;
    for(int i = 1; i < k+1; i++)
        C[i] += C[i-1];
    for(int i = n-1; i >= 0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
    for(int i = 0; i < n; i++){
        A[i]=B[i];
    }
    delete [] B;
    delete [] C;
}

int main(int argc, char const* argv[])
{
    int *temp;
    for(int i = 1; i <= 41; i += 5){
        temp = getRandomArray(i, 0, 25);
        printarray(temp, i);
        countingsort(temp, i);
        printarray(temp, i);
        delete [] temp;
    }

    return 0;
}
