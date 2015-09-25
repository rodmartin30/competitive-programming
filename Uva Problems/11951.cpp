#include <bits/stdc++.h>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define all(v) v.begin(),v.end()
#define FIN -4611256527403020609
#define T 105
using namespace std;
long long a[T][T];

int main() {
  int test,n,m,k,caso=0,x,y;
  long long curr,area;
  pair<long long,long long> res,init = make_pair(0,0);
  cin >> test;
  while(test--) {
    scanf("%d %d %d",&n,&m,&k);
    res = init;
    fore(i,n)
      fore(j,m) {
        scanf("%lld",&a[i][j]);
        if(i>0) a[i][j] += a[i-1][j];
        if(j>0) a[i][j] += a[i][j-1];
        if(j>0 && i>0) a[i][j] -= a[i-1][j-1];
      }
      
    for(int i=0;i<n;i++)
      for(int j=0;j<m && (n-i)*(m-j)>=res.first;j++)
        for(int g=i;g<n;g++)
          for(int h=res.first/(g+1);h<m;h++) {
            curr = a[g][h];
            if(i>0) curr-=a[i-1][h];
            if(j>0) curr-=a[g][j-1];
            if(i>0 && j>0) curr+=a[i-1][j-1];
            area = ((g-i)+1)*(1+(h-j));
            if(curr<=k) {
              if(area>res.first) {
                res.first = area;
                res.second = curr;
                y = ((g-i)+1);
                x = (1+(h-j));
              } 
              else if(area==res.first && res.second>curr) {
                res.second = curr;
              }
            }
          }
    printf("Case #%d: %lld %lld\n",++caso,res.first,res.second);
      
  
  }
}
