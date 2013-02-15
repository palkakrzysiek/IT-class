#include <iostream>

int findMinColumn(int **T, int M, int N){
    /*
     * TC: O(MxN)
     * SC: O(M)
     * IC: T is an 2 dimensional array of integers, M is number of rows and N is number of columns
     * PC: function returns index of row of which arithmetic average is smallest
     */
    double *temp = new double[M];
    int sum = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            sum += T[i][j];
        }
        double average = sum / N;
        temp[i] = average;
        sum = 0;
    }
    double min = temp[0];
    for(int i = 1; i < M; i++){
        if(temp[i] < min)
            min = temp[i];
    }
    return min;
}

int main(int argc, char const* argv[])
{
    int M = 3;
    int N = 2;
    int **T = new int[M][N];
    T = { {2, 5},
          {7, 9},
          {1, 2} };
    std::cout << findMinColumn(T, 3, 2);
    return 0;
}
