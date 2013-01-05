#include<iostream>

using namespace std;
int find(int T[], int N, int x){
    for(int i = 0; i < N; ++i){
        if(T[i] == x){
            return i;
        }
    }
    return -1;
}

int main(int argc, char const* argv[])
{
    int Z[] = {1, 2, 4, 5, 9, 2, 3, 4};
    int iloscElementow = 8;
    int szukana = 3;
    if(find(Z, iloscElementow, szukana) == -1)
        cout << "nie znaleziono takiej liczby" << endl;
    return 0;
}
