#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#define T 105
#define H 50005
#define fore(i,m,n) \
for(int i = m;i<n;i++)

using namespace std;
int sum;
int memo[T][H];
vector<int> coins;
int minimo(int a, int b, int c)
{
	return min(min(a,b),c);
}
int dp(int c,int i)
{
	if(c<0)
		return abs(i-(sum-i));
	if(memo[c][i]!=-1)
		return memo[c][i];
	
	return memo[c][i] = min(dp(c-1,i+coins[c]),dp(c-1,i));
}

int main(){
	int test;
	cin >> test;
	while(test--) {
	
		int n; cin >> n; sum=0;
		coins.clear(); coins.resize(n);
		memset(memo,-1,sizeof(memo));
		fore(i,0,n) {
			cin >> coins[i]; sum+= coins[i];
		}
		
		cout << dp(n-1,0) << endl;
	}
}
