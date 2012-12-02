#include <stdio.h>

unsigned long long binpow(unsigned long long x, unsigned long long y){
    unsigned long long r = 1;
    while (y != 0) {
        if(y%2==1) r = r * x;
        y = y / 2;
        x = x * x;
    }
    return r;
}


int main(int argc, char const* argv[])
{
    unsigned long long a,b;
    for (int i = 0; i < 10; ++i){
        scanf("%llu %llud", &a, &b);
        unsigned long long wynik = binpow(a, b);
        if(wynik < 10){
            puts("0"); continue;
        }
        unsigned long long dec = (wynik % 100/10);
        printf("%llu\n", dec);
    }
    return 0;
}
