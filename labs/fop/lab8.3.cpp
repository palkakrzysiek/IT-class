#include <iostream>
using namespace std;

int* fun1(int *tab, int rozmiar);
int* fun2(int *tab, int rozmiar);


int main()
{ 
    int tab[10]={1,2,3,4,5,6,7,8,9,10};
    int *pointer1=fun1(tab,10);
    cout<<"After fun1 call"<<endl;
    for(int i=0;i<10;i++)cout<<"tab["<<i<<"]="<<pointer1[i]<<endl;
    int *pointer=fun2(tab,10);
    cout<<"After fun2 call"<<endl;
    for(int i=0;i<10;i++)cout<<"tab["<<i<<"]="<<pointer[i]<<endl;
    return 0;
}
int* fun1(int *tab, int rozmiar)
{ 
    cout<<"In fun1"<<endl;
	int *pointer=tab;
	for(int i=0;i<rozmiar;i++)
        {
            tab[i]+=10;
            cout<<"tab["<<i<<"]="<<tab[i]<<endl;
        }
    return pointer;
}
int* fun2(int *tab, int rozmiar)
{ 
    cout<<"In fun2"<<endl;
    for(int i=0;i<rozmiar;i++)
    {
        *(tab+i)+=10;
        cout<<"tab["<<i<<"]="<<*(tab+i)<<endl;
    }
return tab;
}
