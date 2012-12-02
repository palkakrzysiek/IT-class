#include <stdio.h>

int parent (int n){
    return n/2+1;
}
int left (int n){
    return 2*n + 1;
}
int right (int n){
    return 2*n + 2;
}



void push(int *T, int N, int x){
    T[N+1] = x;
    int current = N+1;
    while(current > 0){
        if (T[current] < T[parent(current)]){
            int temp = T[parent(current)];
            T[parent(current)] = T[current];
            T[current] = temp;
            current = parent(current);



        }
    }
}

int pop(int *T, int N){
    T[0] = T[N];
    int current = 0;
    int smallerChild = (left(N)<right(N)?left(N):right(N));
}
