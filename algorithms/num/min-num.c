int min(int T[], int n){
    int minimal;
    int index = 0;
    minimal = T[0];
    for(int i = 1; i < n; n++){
        if(T[i] < minimal){
            minimal = T[i];
            index = i;
        }
    }
}
