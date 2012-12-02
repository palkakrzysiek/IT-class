#include <cstdio>
void merge(int *T, int start, int end){
    int *temp = new int[end - start + 1];
    int mid = (start + end)/2;
    int a = start, b = mid + 1, i = 0;
    while(i<=end - start){
        if((a <= mid) && ((T[a] < T[b]) || b == end))
            temp[i++] = T[a++];
        else
            temp[i++] = T[b++];
    }
    for(i = 0; i <= end; i++){
        T[start+i] = temp[i];
    }
}
void mergeSort(int *T, int start, int end){
    if (start < end) {
        int mid = (start + end)/2;
        mergeSort(T, start, mid);
        mergeSort(T, mid+1, end);
        merge(T, start, end);
    }
}

int main(int argc, char const* argv[])
{
    int c;
    scanf("%d", &c);
    int *tab = new int[c];
    int i = 0;
    while(i < c)
        scanf("%d", tab + i++);
    for(i = 0; i < c; i++){
        printf("%d\n", tab[i]);
    }
    puts("");
    mergeSort(tab, 0, c-1);
    for(i = 0; i < c; i++){
        printf("%d\n", tab[i]);
    }
    puts("");

    return 0;
}
