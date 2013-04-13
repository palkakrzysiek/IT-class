#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    int tab[10];
    int *wsk1=&tab[2];
    int *wsk2=&tab[5];
    for(int i = 0; i < 10; i++) tab[i]=i*2;
    cout<<"wsk2>wsk1: "<<(wsk2>wsk1)<<endl;
    cout<<"wsk1<wsk2: "<<(wsk1<wsk2)<<endl;
    cout<<"wsk2>=wsk1: "<<(wsk2>=wsk1)<<endl;
    cout<<"wsk1<=wsk2: "<<(wsk1<=wsk2)<<endl;
    cout<<"wsk2==wsk1: "<<(wsk2==wsk1)<<endl;
    cout<<"wsk1!=wsk2: "<<(wsk1!=wsk2)<<endl;
}
