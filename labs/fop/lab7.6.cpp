#include <iostream>
using namespace std;

int potega(int base, int exponent){
    int result = 1;
    while (exponent != 0){
        if(exponent%2 == 1) result = result * base;
        exponent = exponent / 2;
        base = base * base;
    }
    return result;
}

int main(int argc, char const* argv[])
{
    int a, b;
    cout << "Podaj podstawę i wykładnik potęgi: ";
    cin >> a >> b;
    cout << "Wynik to " << potega(a, b) << "." << endl;
    return 0;
}
