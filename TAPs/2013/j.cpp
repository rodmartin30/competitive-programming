#include <bits/stdc++.h>
#define MOD 1000000007
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int memo[1005][1005];
int dp(int piedras, int pilas) {
	if(memo[piedras][pilas] == -1) {
		memo[piedras][pilas] = dp(piedras,pilas-1); // cerrar pila
		if(piedras >= pilas) 
			memo[piedras][pilas] += dp(piedras-pilas,pilas);
	}
	return memo[piedras][pilas] = memo[piedras][pilas] % MOD;
}
int main() {
	int test;
	cin >> test;
	
	memset(memo,-1,sizeof memo);
	memo[0][0] = 1;
	fore(i,1,1005) memo[i][0] = 0;
	
	while(test--) {
		int n;
		cin >> n;
		int sum = 0;
		
		for(int i=1-(n%2);i<=n;i+=2) {
			sum+= dp(n-i,i);
			sum = sum%MOD;
		}
		cout << sum << endl;
	}
		

}
