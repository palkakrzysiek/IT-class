#include <stdio.h>

/******************
 * x^1 = x
 * x^2 = x^2
 * x^3 = x*x^2
 * x^4 = (x^2)^2
 * x^5 = x*(x^2)^2
 * x^6 = x^2*(x^2)^2
 *****************/

int power3(int base, int exponent){
    if (exponent == 1)
        return base;
    else
        return base * power3(base, exponent - 1);
}

// 3 3 (3*9 = 27)
//  3 2 (3*3 = 9)
//   3 1 (3)

double pow2(double x, int y){
    double r = 1;
    while (y != 0) {
        if(y%2==1) r = r * x;
        y = y / 2;
        x = x * x;
    }
    return r;
}


int power(int base, int exponent){
    int info = 1;
	int result = 1;

    if(info) printf("result: %d, base: %d, exponent %d\n", result, base, exponent);
    if(info) printf("%d*%d^%d = ", result, base, exponent);

	while(exponent != 0){
		if(exponent % 2 == 1)
			result = result * base;
		exponent = exponent / 2;
		base = base * base;
        if(info) printf("%d*%d^%d = ", result, base, exponent);
	}
    if(info) printf("result: %d, base: %d, exponent %d\n", result, base, exponent);
    return result;
}

int main(int argc, char const* argv[])
{
    printf("%d\n", power(2,18));
    printf("%d\n", power(2,29));
    printf("%d\n", power(3,4));
    printf("%d\n", power(5,5));
    printf("%f\n", pow2(3,3));
    printf("%f\n", pow2(1.5,3));
    printf("%f\n", pow2(2.5,3));
    return 0;
}
