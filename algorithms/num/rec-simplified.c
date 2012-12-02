#include <stdio.h>
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
int examine = 1;
int indent = 1;
int case1 = 0;
int case2 = 0;
int case3 = 0;

int inter(int m, int n){
    while(m){
    }
}

int rec2(int m, int n){
    if (m == 0) {
        return n + 1;
    }
    if (m > 0 && n == 0) {
        return rec2(m - 1, 1);
    }
    if (m>0 && n > 0) {
        return rec2(m - 1,rec2(m,n-1));
    }

}
int rec(int m, int n){
    if(examine)
        FOR(i, 0, indent-1)
            printf(" ");
    if(examine) printf("f(%i, %i)\n", m, n);
    if(examine)
        FOR(i, 0, indent)
            printf(" ");
    if (m == 0) {
        if(examine) printf("return: %i\na", n + 1); --indent; case1++;
        return n + 1;
    }
    if (m > 0 && n == 0) {
        if(examine) printf("return: func(%i, %i) [%i]\nb", m - 1, 1, rec2(m - 1, 1)); ++indent; case2++;
        return rec(m - 1, 1);
    }
    if (m>0 && n > 0) {
        if(examine) printf("return: func(%i, func(%i, %i)) [func(%i, %i)] [%i]\nc",m - 1, m,n - 1, m - 1, rec2(m, n - 1), rec2(m - 1, rec2(m, n - 1))); ++indent; case3++;
        return rec(m - 1,rec(m,n-1));
    }
}
int inter(int m, int n){
    FOR(i, 0, m){
        FOR(j, 0, n){

        }
    }
}


int main(int argc, char const* argv[])
{
    int m,n;
    scanf("%i %i", &m, &n);
    printf(">>> %i\n", rec(m,n));
    printf("%i %i %i", case1, case2, case3);
    return 0;
}
