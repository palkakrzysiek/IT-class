#include <iostream>
using namespace std;

int a=20,b=30,c=40;

int main(int argc, char const* argv[])
{
    int i=10, j=20,k=30;
    cout<<"address of i: "<<(long)&i<<endl;
    cout<<"address of j: "<<(long)&j<<endl;
    cout<<"address of k: "<<(long)&k<<endl;
    cout<<"address of a: "<<(long)&a<<endl;
    cout<<"address of b: "<<(long)&b<<endl;
    cout<<"address of c: "<<(long)&c<<endl;
    cout<<"sizeof i: "<<sizeof(i)<<endl;
    return 0;
}
