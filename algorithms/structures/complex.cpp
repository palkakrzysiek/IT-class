#include <cstdio>

struct Scomplex{
    double re;
    double im;
};

Scomplex add(Scomplex x, Scomplex, y){
    Scomplex resoult;
    resoult.re = x.re + y.re;
    resoult.im = x.im + y.im;
    return resoult;
}

int main(int argc, char const* argv[])
{
    Scomplex a = {3.14, 6.18};
    Scomplex b = {1,2};
    Scomplex c = add(a,b);
    return 0;
}
