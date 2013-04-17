#include <iostream>
#include <stdlib.h>
using namespace std;

void copy_text(char target[], char source[]){
    int i = 0;
    while(target[i] = source[i])
        i++;
}

int main(int argc, char const* argv[])
{
    char z[] = "Ala ma kota";
    cout << z << endl;
    cout << sizeof(z) << endl;
    char z1[20];
    copy_text(z1, z);
    cout << z1;
    return 0;
}
