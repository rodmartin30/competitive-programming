#include <bits/stdc++.h>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define T 105
#define M 10005

using namespace std;
long long a[6] = {0,1,5,10,25,50},dp[6][30005];
int main() {
	memset(dp,0,sizeof dp);
  fore(j,30005) dp[0][j] = 0;
  fore(i,6) dp[i][0] = 1;
  
  for(int i=1;i<6;i++) {
    for(int j =1;j<30005;j++) {
    	dp[i][j] = dp[i-1][j];
      if(a[i]<=j) {
      	dp[i][j] += dp[i][j-a[i]];
      }
    }
  }
  int n;
  while(scanf("%d",&n) != EOF) {
  	if(dp[5][n] != 1)
    	printf("There are %lld ways to produce %d cents change.\n",dp[5][n],n);
   	else
   		printf("There is only %lld way to produce %d cents change.\n",dp[5][n],n);
  }
  
  return 0;
}
