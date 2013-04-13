#include <iostream>
using namespace std;

int tab[10], a = 3;

int main(int argc, char const* argv[])
{
    for(int i = 0; i <= 10; i++){
        tab[i] = 100; cout << &tab[i] << endl;
        cout << &a << " " << a << endl;
    }
    return 0;
}
