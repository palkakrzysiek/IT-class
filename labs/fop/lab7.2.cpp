#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    int n = 0;
    cout << "Give the number of the cells: ";
    cin >> n;
    int *wsk = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "tab[" << i << "] = " << *(wsk+i) << endl;
    }
    delete [] wsk;
    return 0;
    wsk = NULL;
}
