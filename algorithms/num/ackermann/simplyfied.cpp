#include <cstdio>

#define FOR(x, b, e) for(long long x=b; x<=(e); ++x)
#define FORD(x, b, e) for(long long x=b; x>=(e); --x)
int examine = 1;
int indent = 1;
int case1 = 0;
int case2 = 0;
int case3 = 0;


long long rec2(long long m, long long n){
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
long long rec(long long m, long long n){
    if(examine)
        FOR(i, 0, indent-1)
            printf(" ");
    if(examine) printf("f(%lld, %lld)\n", m, n);
    if(examine)
        FOR(i, 0, indent)
            printf(" ");
    if (m == 0) {
        if(examine) printf("return: %lld\na", n*n - n + 2); --indent; case1++;
        return n + 2;
    }
    if (m > 0 && n == 0) {
        if(examine) printf("return: func(%lld, %lld) [%lld]\nb", m - 1, (long long)1, (long long)rec2(m - 1, 1)); ++indent; case2++;
        return rec(m - 1, (long long)1);
    }
    if (m>0 && n > 0) {
        if(examine) printf("return: func(%lld, func(%lld, %lld)) [func(%lld, %lld)] [%lld]\nc",m - 1, m,n - 1, m - 1, rec2(m, n - 1), rec2(m - 1, rec2(m, n - 1))); ++indent; case3++;
        return rec(m - 1,rec(m,n-1));
    }
}
long long iter(long long m, long long n){
    if(m == 0)
        return n + 2;
    else{
        long long wynik = 0;
        FOR(i, 0, m){
            FOR(j, 0, (i == m?n:0)){
                if(examine) printf("i: %lld, j: %lld\n",i,j);
                wynik = wynik + 2;
            }
        }
        return wynik;
    }
}


int main(int argc, char const* argv[])
{
    if(argc == 2 && argv[2] == 0) examine = 0;
    long long m,n;
    scanf("%lld %lld", &m, &n);
    printf(">>> %lld\n", iter(m,n));
    printf(">>> %lld\n", rec(m,n));
    printf("%d %d %d", case1, case2, case3);
    return 0;
}
