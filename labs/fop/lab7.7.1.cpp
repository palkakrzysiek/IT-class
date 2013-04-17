#include <iostream>
using namespace std;
void fun(int number);
int main() 
{ 	int a=10;
cout<<"before function call a="<<a<<endl;
fun(a);
cout<<"after function call a="<<a<<endl;
return 0;
}
void fun(int number)
{ cout<<"inside function a="<<number<<endl;
number++;
cout<<"after incrementation inside function a="<<number<<endl;
}
