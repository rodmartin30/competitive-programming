#include <bits/stdc++.h>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define all(v) v.begin(),v.end()
#define FIN -4611256527403020609
#define T 25
using namespace std;
long long d[T][T][T];

int main() {
  int test;
  cin >> test;
  while(test--) {
    int a,b,c;
    long long res = 0,total=0;
    cin >> a >> b >> c;
    fore(k,a)
      fore(i,b)
        fore(j,c) {
          scanf("%lld",&d[k][i][j]);
          total += d[k][i][j];
          if(i>0) d[k][i][j] += d[k][i-1][j];
          if(j>0) d[k][i][j] += d[k][i][j-1];
          if(i>0 && j>0) d[k][i][j] -= d[k][i-1][j-1];          
        }
    res = FIN;
    fore(i,b)
      fore(j,c) {
          for(int h=i;h<b;h++)
            for(int l=j;l<c;l++) {
              long long curr = 0;
              long long x = 0;
              fore(k,a) {
                curr += d[k][h][l];
                if(i>0) curr -= d[k][i-1][l];
                if(j>0) curr -= d[k][h][j-1];
                if(i>0 && j>0) curr += d[k][i-1][j-1];
                
                res = max(res,curr);
                curr = max(curr,x);
              }
            }
      }
    cout << res << endl;
    if(test)
      cout << endl;
  }  
}
