#include <cstdlib>

struct selem{
    double x;
    selem *p; 
};

selem *h;

void init(){
    h = NULL;
}

void push(double x){
    selem *pnew = new selem;
    pnew -> x = x;
    pnew -> p = h;
    h = pnew;
}
