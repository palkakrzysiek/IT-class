#include <stdio.h>

short shortbinpow(short x, unsigned long long y){
    short r = 1;
   // printf("\n\nr: %hd x: %hd; y: %llu\n",r, x, y);
    while (y != 0) {
        if(y%2==1){
            r = r * x;
            r = r % 100;
    //printf("\n\nr: %hd x: %hd; y: %llu\n",r, x, y);
        }
        y = y / 2;
    //printf("\n\nr: %hd x: %hd; y: %llu\n",r, x, y);
        x = x * x;
        x = x % 100;
    //printf("\n\nr: %hd x: %hd; y: %llu\n",r, x, y);

    }
    return r;
}
unsigned long long read(short *a){
    char temp;
    unsigned long long counter = 0;
    while(scanf("%1c", &temp) && temp != 32){
        //printf("%d\n", (int)(temp - 48));
        a[1]=a[0];
        a[0]=temp - 48;
        if(a[1] == - 38)
            a[1] = 0;
    }
    //printf("%llu\n", counter);
    if (counter == 1)
        a[1] = 0;
    unsigned long long b;
    scanf("%llu", &b);
    return b;
}
int main(int argc, char const* argv[])
{
    short a[2];
    a[0] = a[1] = 0;
    unsigned long long b = read(&a);
    short aw = 10*a[1]+a[0];
    //printf("%hd %llu\n", aw, b);
    short res =  shortbinpow(aw, b);
    printf("%hd\n", res/10);

    return 0;
}
