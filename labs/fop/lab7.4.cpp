#include <iostream>
using namespace std;

int kuku(int ile);

int main(int argc, char const* argv[])
{
    int i = 10, j;
    cout << "Enter an integer value" << endl;
    i = kuku(j);
    cout << "After first function call i = " << i << endl;
    cout << "Enter an integer value" << endl;
    cin >> j;
    i = kuku(j);
    cout << "After second function call i = " << i << endl;
    cout << "Enter an integer value: ";
    cin >> j;
    i = kuku(j);
    cout << "After third function call i = " << i << endl;

    return 0;
}

int kuku(int ile){
    for(int i = 0; i < ile; i++){
        cout << "Kuku!" << endl;
        return ile;
    }
}
