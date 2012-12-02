#include <cstdlib>
#include <iostream>
using namespace std;

void sortuj_szybko(int t[], int n)
{
 int i, j, x = t[0], n1 = 0, n2 = 0, t1[n -1], t2[n -1];
 if (n <= 1) return;
 for (i = 1; i < n; i++)
  if (t[i] < x) { t1[n1] = t[i]; n1++; }
  else          { t2[n2] = t[i]; n2++; }
 sortuj_szybko(t1, n1);
 sortuj_szybko(t2, n2);
 for (i = 0, j = 0; j < n1; j++, i++) t[i] = t1[j];
 t[i] = x; i++;
 for (j = 0; j < n2; j++, i++)        t[i] = t2[j];
}

void wyswietl(int t[], int n)
{
 int i; 
 for (i = 0; i < n; i++)
 {
  cout << t[i];
  if (i < n - 1) cout << ",";
  cout << " ";
 }
}

int main(int argc, char *argv[])
{
 int tablica1[10] = {  5, 2, 1, 3, 8, 7, 9, 4, 0, 6 };
 int tablica2[8]  = { -5, -2, 1, 33, 28, 17, -9, 42 };
 sortuj_szybko(tablica1, 10);
 sortuj_szybko(tablica2, 8);
 cout << "tablica1 = "; wyswietl(tablica1, 10); cout << endl;
 cout << "tablica2 = "; wyswietl(tablica2,  8); cout << endl;
 system("PAUSE");
 return 0;
}
