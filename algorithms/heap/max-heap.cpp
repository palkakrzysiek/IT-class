#include <cstdio>
struct HEAP{
    int *elements;
    int size;
    int length;
};

void exchange(HEAP *T, int a, int b){
    int temp = T->elements[a];
    T->elements[a] = T->elements[b];
    T->elements[b] = temp;
    printf("%d %d\n", a, b);
}
inline int left(int n){
    return n+1;
}
inline int right(int n){
    return n+2;
}
inline int parent(int n){
    return (n-1) / 2;
}

void maxHeapify(HEAP *T, int N){
    int l = left(N);
    int r = right(N);
    int largest;
    if(l <= T->size && T->elements[l] > T->elements[N])
        largest = l;
    else
        largest = N;
    if(r <= T->size && T->elements[r] > T->elements[largest])
        largest = r;
    if(largest != N){
        exchange(T, largest, N);
        maxHeapify(T, largest);
    }
}

void buildMaxHeap(HEAP *T){
    for(int i = (T->size - 1) >> 1 << 1 / 2; i >= 0; i--){
        printf("%d\n", i);
        maxHeapify(T, i);
    }
}

void heapSort(HEAP *T){
    for(int i = T->length - 1; i > 1; i--){
        exchange(T, 0, i);
        T->size--;
        maxHeapify(T, 0);
    }
}

void printHeap(HEAP *T){
    for(int i = 0; i<T->length; i++)
        printf("%d ", T->elements[i]);
    puts("");
}

int main(int argc, char const* argv[])
{
    HEAP *hp = new HEAP;
    hp->elements = new int[10];
    hp->elements[0] = 16;
    hp->elements[1] = 4;
    hp->elements[2] = 10;
    hp->elements[3] = 14;
    hp->elements[4] = 7;
    hp->elements[5] = 9;
    hp->elements[6] = 3;
    hp->elements[7] = 2;
    hp->elements[8] = 8;
    hp->elements[9] = 1;
    hp->size = 10;
    hp->length = 10;
    printHeap(hp);
    //maxHeapify(hp, 1);
    buildMaxHeap(hp);
    printHeap(hp);
    heapSort(hp);
    printHeap(hp);
    return 0;
}

    //printf("l: %d; r: %d; size: %d; v(l): %d; v(r): %d; N: %d; v(N): %d, largest: %d\n", l, r, T->size, T->elements[l], T->elements[r], N, T->elements[N], largest);
