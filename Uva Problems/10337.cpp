#include <bits/stdc++.h>
#define fore(i,n) for(int i=0;i<n;i++)
#define T 1005
#define M 100005
using namespace std;
int n,a[10][T],memo[10][T];
int dp(int i, int j) {
	int res=M;
	if(i==9 && j == n)
		return 0;
	else if(i!=9 && j == n)
		return M;
	else if(memo[i][j] != -1)
		return memo[i][j];
	else if(i > 0 && i <9) {
		res = min(dp(i-1,j+1)+60-a[i][j],min(dp(i,j+1)+30-a[i][j],dp(i+1,j+1)+20-a[i][j]));
		memo[i][j] = res;
	}
	else if(i<9) {
		res = min(dp(i,j+1)+30-a[i][j],dp(i+1,j+1)+20-a[i][j]);
		memo[i][j] = res;
	}
	else if(i>0) {
		res = min(dp(i,j+1)+30-a[i][j],dp(i-1,j+1)+60-a[i][j]);
		memo[i][j] = res;
	} else {
		res = dp(i,j+1)+30-a[i][j];
		memo[i][j] = res;
	}
	
	return res;
}
int main() {
	int test;
	cin >> test;
	while(test--) {
		int ans=M;
		memset(memo,-1,sizeof memo);
		cin >> n;
		n/=100;
		fore(i,10) {
			fore(j,n)
				scanf("%d",&a[i][j]);		
		}
		ans = dp(8,1)+60-a[9][0];
		ans = min(ans,dp(9,1)+30-a[9][0]);
		cout << ans << endl << endl;
	}
}
