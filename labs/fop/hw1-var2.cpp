#include <iostream>
#include <math.h>

using namespace std;


int print_sqares(double a, double b, double c double *sol1, *sol2){
    double delta = b*b - 4*a*c;
    if (delta < 0)
        cout << "There are no solutions" << endl;
    else if (delta == 0)
        *sol1 = 
        cout << "The only solution is " << -b/2/a << endl;
    else
        cout << "Solutions: " << (-b - sqrt(delta))/(2*a) << ", " << (-b + sqrt(delta))/(2*a) << endl;

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
    double x,y
    int d;
    cout << "Give a, b and c factors (separated with spaces) for square equation: ";


    cin >> a >> b >> c;
    print_sqares(a, b, c, &x, &y);

    cout << "Give parameter of factorial: ";
    cin >> d;
    cout << "Result is << " << factorial(d);
    
    return 0;
}
