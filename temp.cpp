#include <iostream>
using namespace std;
int fun(int *var){
    *var += 10;
    cout << *var * 2 << endl;
    return *var * *var;
}

int fun2(int T1[], int T2[], int N){
    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += T2[i] * T1[i]; 
    }
    return sum;
}

int main()
{

    int tab1[] = {1, 2, 342, 432, 132, 21, 321, 543, 312, 432};
    int tab2[] = {1, 2, 342, 432, 132, 21, 321, 543, 312, 432};
    cout << fun2(tab1, tab2, 10);

    return 0;
}
