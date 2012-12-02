#include <stdio.h>
int fib(int n){
    printf("f(%d)\n", n);
    if(n <= 2)
        return 1;
    else
        return fib(n - 2)+fib(n - 1);
}
int fib2(int n){
    if(n <= 2)
        return 1;
    int a = 1, b = 1,c;
    for(int i = 3; i <= n; ++i){
        //c = b + a;
        //a = b;
        //b = c;
        b = b + a;
        a = b - a;
    }
    return b;
}
int main(int argc, char const* argv[])
{
    int i;
    scanf("%d", &i);
    printf("%d %d\n", fib(i), fib2(i));
    return 0;
}
