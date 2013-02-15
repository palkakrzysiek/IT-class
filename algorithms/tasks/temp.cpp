int find(int *T, int N, int k){

    mergesort(T, N);

    int lastValue = T[0];
    int tempCounter = 1;
    int occurences = 0;
    for ( int i = 1; i < N; i++){
        if (lastValue == T[i]){
            tempCounter++;
        }
        else{
        if (tempCounter == k) occurences++;
        lastValue = T[i];
        tempCounter = 1;
        }
        
        return occurences;
    }

}
