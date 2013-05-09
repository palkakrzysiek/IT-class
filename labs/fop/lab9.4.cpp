#include <iostream>
using namespace std;

int fun1(int a, int b){
    cout << "fun1 is working\nThe sum of arguments is: " << a+b << endl;
    return a+b;
}

int fun2(int a, int b){
    cout << "fun2 is working\nThe product of arguments is: " << a*b << endl;
    return a*b;
}

int main(int argc, char const* argv[])
{
    int (*fun_pointer)(int, int);
    int i;
    while(1){
        cout << "What function do you want to call?\n 1 - fun1\n 2 - fun2\n?>";
        cin >> i;
        switch(i){
            case 1:
                    fun_pointer = fun1;
                    break;
            case 2:
                    fun_pointer = fun2;
                    break;
            default:
                    fun_pointer=NULL;
                    break;
        }
        if(fun_pointer)
            cout << fun_pointer(10,20) << endl;
        else break;
    }
    return 0;
}
