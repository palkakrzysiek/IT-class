#include <iostream>
using namespace std;
int main() 
{ int i=10;
float pi=3.14;
  int* wsk=&i;
float *wsk1=&pi;
//wsk1=wsk;//can not convert from int* to float*
wsk1=(float *)wsk;

void* wskw=wsk;
cout<<"The value of i using int* "<<*wsk<<" the same value using void* "<<*((int *)wskw)<<endl;
wskw=wsk1;
cout<<"The value of pi using float* "<<*wsk1<<" the same value using void* "<<*((float *)wskw)<<endl;

return 0;
}
