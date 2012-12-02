#include <iostream>
using namespace std;

float m1[10000], n1[10000], m2[10000], n2[10000];

int loop(int i) {
   while (m2[i-1] > 0) {
      if (n2[i-1] != 0) {
         m1[i] = m2[i-1] - 1;
         n1[i] = -1;
         m2[i] = m2[i-1];
         n2[i] = n2[i-1] - 1;
      }
      else {
         --i;
         m2[i] = m2[i] - 1;
         n2[i] = 1;
      }
      ++i;
   }
   return i;
}

int fi(int m, int n) {
   unsigned int z;
   m2[0] = m;
   n2[0] = n;
   z = 1;
   z = loop(z);
   --z;
   while (m2[z] == 0 && z != 0) {
         m2[z-1] = m1[z];
         n2[z-1] = n2[z]*n2[z] -n2[z] +2;
         z = loop(z);
         --z;
   }
   if (m2[0] == 0) return n2[0]*n2[0] - n2[0] + 2;
}

int main() {
   int x, m, n;
   cin >> m;
   cin >> n;
   x = fi(m, n);
   cout << x << endl;
}
