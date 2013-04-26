#include <iostream>
#include <math.h>

using namespace std;


int print_sqares(double a, double b, double c, double &sol1, double &sol2){
    double delta = b*b - 4*a*c;
    if (delta < 0){
        return 0;
    }
    else if (delta == 0){
        sol1 = -b/2/a;
        return 1;
    }
    else{
        sol1 = (-b - sqrt(delta))/(2*a); 
        sol2 = (-b + sqrt(delta))/(2*a);
        return 2;
    }

}

int factorial(int a){
    int r = 1;
    for(int i = 1; i <= a; i++){
        r *= i;
    }
    return r;
}



int main(int argc, char const* argv[])
{

    double a,b,c;
    double x,y;
    int d;
    cout << "Give a, b and c factors (separated with spaces) for square equation: ";

    cin >> a >> b >> c;

    switch(print_sqares(a, b, c, x, y)){
        case 0:
            cout << "Ain't solutions" << endl;
            break;
        case 1:
            cout << "The only solution: " << x << endl;
            break;
        case 2:
            cout << "Solutions: " << x << " and " << y << endl;
            break;

    }

    cout << "Give parameter of factorial: ";
    cin >> d;
    cout << "Result is << " << factorial(d);
    
    return 0;
}
