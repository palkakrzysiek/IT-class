#include <iostream>
using namespace std;

int *wsk1=0;

int main(int argc, char const* argv[])
{
    int *wsk2 = NULL;
    cout << wsk1 << " " << wsk2 << endl;
    if (wsk1 == NULL) cout << "wsk1 is NULL" << endl;
    if (wsk2 == 0) cout << "wsk2 is NULL" << endl;
    return 0;
}
