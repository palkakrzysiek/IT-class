#include<cstdio>
using namespace std;

struct DArray{
    int *T;
    int N;
    int L;
};

int length(DArray *D){
    return D->N;
}

int get(DArray *D, int i){
    return (D->T)[i];
}

int set(DArray *D, int i, int x){
    (D->T)[i] = x;
}

void add(DArray *D, int x){
    if (D->L > D->N){
        (D->T)[(D->N)++] = x;
    }
    else{
        int *temp = new int[2*D->L];
        for (int i = 0; i < D->L; i++)
            temp[i] = D->T[i];
        delete [] D->T;
        D->T = temp;
        add(D,x);
    }

}

int main(int argc, char const* argv[])
{
    DArray *P = new DArray;
    P->L = 4;
    P->N = 0;
    P->T = new int[P->L];
    return 0;
}
