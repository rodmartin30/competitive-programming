#include <bits/stdc++.h>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define T 105
#define M 1000000
#define push_back pb

using namespace std;
long long dp[105][105];
long long m(int n,int k) {
	if(n == 0)
		return 1;
	if(k==0)
		return 0;
		
	if(dp[n][k] != -1)
		return dp[n][k];
		
	long long res =0;
	fori(i,n)
		res+=m(n-i,k-1);
	res = res%M;
	dp[n][k] = res;
	return res;
}



int main() {
	int n,k;
	while(scanf("%d %d",&n,&k) && n != 0 && k!=0) {
		memset(dp,-1,sizeof dp);
		printf("%lld\n",m(n,k));
	}
  return 0;
}
