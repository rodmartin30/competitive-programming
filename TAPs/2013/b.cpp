#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int a[20];
double p[20];
int main() {
  ios_base::sync_with_stdio(false);
  int n,total=0;
  cin >> n;
  fore(i,0,n) {
    cin >> a[i];
    total+=a[i];
  }
  fore(i,0,n)
    p[i] = 100 * a[i] / total;
  
  sort(p,p+n);
  reverse(p,p+n);
  if(p[0] >= 45 || (p[0] >= 40 && p[0]-p[1] > 10))
    cout << 1 << endl;
  else
    cout << 2 << endl;
}

