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
