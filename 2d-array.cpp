#include <iostream>
using namespace std;
int printarr(int (*t)[2], int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << t[i][j];
        }
    }
}

int main(int argc, char const* argv[])
{
    int a[][2] = {{0, 1},
                 {5, 7},
                 {2, 1},
                 {4, 4}};
    printarr(a, 4, 2);
    return 0;
}
