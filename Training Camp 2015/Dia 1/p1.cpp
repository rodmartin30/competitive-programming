#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int g[105],b[105];
long long gcd (long long a, long long b) { return b == 0 ? a : gcd(b,a%b);}

int main() {
  ios_base::sync_with_stdio(false);
  long long  l,u;
  while(cin >> l >> u && l != 0 && u != 0) {
    cout << u/5+1 - ((l)/5 ) << endl;
  }
}
