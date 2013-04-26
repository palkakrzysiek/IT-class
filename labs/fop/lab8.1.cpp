#include <iostream>
using namespace std;
int potega(int number, int power);
float potega(float number, int power);
int main() 
{ 	cout<<"Enter an integer number"<<endl;
int num; cin>>num;
	cout<<"Enter the first integer power "<<endl;
	int p1; cin>>p1;
cout<<"Enter another integer value "<<endl;
	int p2; cin>>p2;
	cout<<"Enter the third integer power "<<endl;
	int p3; cin>>p3;
	int result=(potega(num,p1)+potega(num,p2))/potega(num,p3);
	cout<<"integer num-> (num^p1+num^p2)/num^p3  =  "<<result<<endl;
        //float values
        cout<<"Enter a real number"<<endl;
        float number; cin>>number;
        cout<<"Enter the first integer power "<<endl;
	int pf1; cin>>pf1;
        cout<<"Enter another integer value "<<endl;
	int pf2; cin>>pf2;
	cout<<"Enter the third integer power "<<endl;
	int pf3; cin>>pf3;
	float resultf=(potega(number,pf1)+potega(number,pf2))/potega(number,pf3);
	cout<<"float num-> (num^p1+num^p2)/num^p3  =  "<<resultf<<endl;
    return 0;
}
int potega(int number, int power = 4)
{ int result=number;
for(int i=1;i<=power;i++)
result*=number;
return result;
}
float potega(float number, int power = 4)
{ float result=number;
for(int i=1;i<=power;i++)
result*=number;
return result;
}
