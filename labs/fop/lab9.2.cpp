#include <iostream>
using namespace std;

int silnia(int number);

int main(int argc, char const* argv[])
{
    int a = 1;
    cin >> a;
    int b = silnia(a);
    cout << silnia(a) << endl;
    return 0;
}

int silnia(int number){
    if (number == 1)
        return 1;
    else
        return silnia(number - 1) * number;
}
