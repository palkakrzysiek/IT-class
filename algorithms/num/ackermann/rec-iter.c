#include <stdio.h>
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
typedef long long LL;
typedef unsigned long long ULL;
int examine = 1;
int indent = 1;
int case1 = 0;
int case2 = 0;
int case3 = 0;


ULL rec2(ULL m, ULL n){
    if (m == 0) {
        return n + 2;
    }
    if (m > 0 && n == 0) {
        return rec2(m - 1, 1);
    }
    if (m>0 && n > 0) {
        return rec2(m - 1,rec2(m,n-1));
    }

}
ULL rec(ULL m, ULL n){
    if(examine)
        FOR(i, 0, indent-1)
            printf(" ");
    if(examine) printf("f(%llu, %llu)\n", m, n);
    if(examine)
        FOR(i, 0, indent)
            printf(" ");
    if (m == 0) {
        if(examine) printf("return: %llu\na", n + 2); --indent; case1++;
        return n + 2;
    }
    if (m > 0 && n == 0) {
        if(examine) printf("return: func(%llu, %llu) [%llu]\nb", m - 1, 1, rec2(m - 1, 1)); ++indent; case2++;
        return rec(m - 1, 1);
    }
    if (m>0 && n > 0) {
        if(examine) printf("return: func(%llu, func(%llu, %llu)) [func(%llu, %llu)] [%llu]\nc",m - 1, m,n - 1, m - 1, rec2(m, n - 1), rec2(m - 1, rec2(m, n - 1))); ++indent; case3++;
        return rec(m - 1,rec(m,n-1));
    }
}
ULL inter(ULL m, ULL n){
    ULL em[m];
    return 0;

}


int main(int argc, char const* argv[])
{
    ULL m,n;
    scanf("%llu %llu", &m, &n);
    printf(">>> %llu\n", rec(m,n));
    printf("%i %i %i", case1, case2, case3);
    return 0;
}
