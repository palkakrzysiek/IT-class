#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
   int *p;// two different notations: star closer to the pointer name
   int* p1;// star closer to the type specifier 
   int i=10;
   p=&i;
   p1=p;
   cout<<"value of i: "<<i<<" address of i "<<&i<<endl;
   cout<<"value of p: "<<p<<" address of p "<<&p<<endl;
   cout<<"value of p1: "<<p1<<" address of p1 "<<&p1<<endl;
   *p=20;
   cout<<"value of i: "<<i<<" the same using pointer p: "<<*p<<" the same using pointer p1: "<<*p1<<endl;
   *p1=30;
   cout<<"value of i: "<<i<<" the same using pointer p: "<<*p<<" the same using pointer p1: "<<*p1<<endl;
   cout<<"sizeof p: "<<sizeof(p)<<endl;

    return 0;
}
