#include <iostream>
using namespace std;

int kuku(int ile){
    for(int i = 0; i < ile; i++){
        cout << "Kuku!" << endl;
        return ile;
    }
}

int i;

int main(int argc, char const* argv[])
{
    cout << "Adress of i: " << (long)&i << endl;
    cout << &kuku << endl;
    return 0;
}
