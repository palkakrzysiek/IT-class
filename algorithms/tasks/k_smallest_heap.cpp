#include <iostream>
using namespace std;

void printarray(double *A, int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
}

void exchange(double *T, int x, int y){
    double temp = T[x];
    T[x] = T[y];
    T[y] = temp;
}

void upheap(double *T, int N, int i){
    if(i <= 0)
        return;
    int parent = (i-1)/2;
    if (T[parent] > T[i]){
        exchange(T, parent, i);
        upheap(T, N, parent);
    }

}

void downheap (double *T, int N, int i){
    int rightChild = i*2 + 2;
    int leftChild = i*2 +1;
    int smallest;

    if(leftChild < N && T[leftChild] < T[i]){
        smallest = leftChild;
    }
    else{
        smallest = i;
    }
    if(rightChild < N && T[rightChild] < T[smallest]){
        smallest = rightChild;
    }
    if(smallest != i){
        exchange(T, smallest, i);
        downheap(T, N, smallest);
    }
}

int main(int argc, char const* argv[])
{
    double A[] = {4, 5, 3, 8, 9, 2, 1, 0};
    int size = 8;
    printarray(A, size);
    downheap(A, size, 0);
    upheap(A, size, 7);
    printarray(A, size);

    return 0;
}
