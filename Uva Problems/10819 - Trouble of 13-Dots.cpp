#include <bits/stdc++.h>

using namespace std;
#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define T 105
#define M 10005

int p[T],f[T],dp[T][M];
int m,n;

int mochila(int i, int w) {
  if(w > m && m <= 1800)
    return INT_MIN;
  if(w > m + 200)
    return INT_MIN;
  if(i == n) {
    if(w>m && w<=2000)
      return INT_MIN;
    return 0;
  }
  int res = dp[i][w];
  if(res != -1)
    return res;
  else {
    res = max(mochila(i+1,w),mochila(i+1,w+p[i]) + f[i]);
    dp[i][w] = res;
    return res;
  }
}

int main() {
  while(scanf("%d %d",&m,&n) != EOF) {
    fore(i,n) {
      scanf("%d %d",&p[i],&f[i]);
    }
    memset(dp,-1,sizeof dp);
    printf("%d\n",mochila(0,0));
  }
  return 0;
}
