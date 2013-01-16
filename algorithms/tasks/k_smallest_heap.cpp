inline int leftChild(int n){
    return n+1;
}
inline int rightChild(int n){
    return n+2;
}
inline int parent(int n){
    return (n-1) / 2;
}

void exchange(double *T, int x, int y){
    double temp = T[x];
    T[x] = T[y];
    T[y] = temp;
}

void unheap (double *T, int N, int i){
    int current = N;
    T[current] = i;
    while (current>0 && T[parent(current)] < T[current]) {
        exchange(T, parent(current), current);
        current = parent(current);
    }
}

void downheap (double *T, int N, int i){
    exchange (T, N, 0);
    N--;
    int current = 0;
    while (leftChild(current) <= N || leftChild(current) <= N) {
        if(T[current] > T[leftChild(current)]){
            //TODO
        }
    }
}
