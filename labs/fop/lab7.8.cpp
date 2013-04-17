#include <iostream>
using namespace std;
int potega(int number, int power=2);   //if you inform compiler about default value here
float potega(float number, int power=2); //you can't do it once more in definition
int main()
{ 	cout<<"Enter an integer number"<<endl;
int num; cin>>num;
	cout<<"Enter the first integer power "<<endl;
	int p1; cin>>p1;
cout<<"Enter another integer value "<<endl;
	int p2; cin>>p2;
	int result=(potega(num,p1)+potega(num,p2))/potega(num);
	cout<<"integer num-> (num^p1+num^p2)/num^2  =  "<<result<<endl;
        //float values
        cout<<"Enter a real number"<<endl;
        float number; cin>>number;
        cout<<"Enter the first integer power "<<endl;
	int pf1; cin>>pf1;
        cout<<"Enter another integer value "<<endl;
	int pf2; cin>>pf2;
	float resultf=(potega(number,pf1)+potega(number,pf2))/potega(number);
	cout<<"float num-> (num^p1+num^p2)/num^2  =  "<<resultf<<endl;
    return 0;

}
int potega(int number, int power)  
{ int result=number;              
for(int i=1;i<=power;i++)
result*=number;
return result;
}
float potega(float number, int power)
{ float result=number;
for(int i=1;i<=power;i++)
result*=number;
return result;
}
