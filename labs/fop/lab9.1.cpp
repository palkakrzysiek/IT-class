#include <iostream>
using namespace std;

void fun1(const int *zm, int rozmiar);

int main(int argc, char const* argv[])
{
    int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fun1(tab, 10);
    cout << "After fun1 call" << endl;
    for(int i = 0; 1 < 10; i++)
        cout << "tab[" << i << "]=" << tab[i] << endl;
    return 0;
}

void fun1(const int *zm, int rozmiar){
    cout << "In fun1" << endl;
    for (int i = 0; i < rozmiar; i++){
        cout << "tab[" << i << "]=" << *(zm+1) << endl;
    }
}
