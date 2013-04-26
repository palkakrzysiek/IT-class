#include <iostream>
using namespace std;
void fun(int tab[], int rozmiar);
void fun1(int *tab, int rozmiar);
void fun2(int *tab, int rozmiar);


int main()
{ int tab[10]={1,2,3,4,5,6,7,8,9,10};
fun(tab,10);
fun1(tab,10);
fun2(tab,10);
cout<<"After functions call"<<endl;
for(int i=0;i<10;i++)cout<<"tab["<<i<<"]="<<tab[i]<<endl;
return 0;
}
void fun(int tab[], int rozmiar)
{ for(int i=0;i<rozmiar;i++)
{tab[i]+=10;
cout<<"tab["<<i<<"]="<<tab[i]<<endl;
}
}
void fun1(int *tab, int rozmiar)
{ for(int i=0;i<rozmiar;i++)
{tab[i]+=10;
cout<<"tab["<<i<<"]="<<tab[i]<<endl;
}
}
void fun2(int *tab, int rozmiar)
{ for(int i=0;i<rozmiar;i++)
{*(tab+i)+=10;
cout<<"tab["<<i<<"]="<<*(tab+i)<<endl;
}
}
