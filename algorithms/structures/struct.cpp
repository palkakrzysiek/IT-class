#include<cstdio>
using namespace std;

struct Point2D{
    double x;
    double y;
};

int main(int argc, char const* argv[])
{
    Point2D *P = new Point2D;
    Point2D *P2 = new Point2D;
    P -> x = 2.0;
    P2 -> x = P -> x;
    // P = P2; we lost link to P2 - we can't free P - memory leak
    delete P;
    
    return 0;
}
