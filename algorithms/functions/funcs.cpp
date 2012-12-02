#include <iostream>
using namespace std;
double f(double x){
    double result;
    result = x*x + 2*x + 3;
    return result;
}


int main(int argc, char const* argv[])
{
    cout << f(1) << endl;
    cout << f(2) << endl;
    return 0;
}
