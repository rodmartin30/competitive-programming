#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
#define N 505
using namespace std;
typedef long long ll;
//typedef pair<int,int> ii;
int table[N][N],mi[2] = {0,-1},mj[2] = {-1,0},memo[N][N];
int n,m;

int main() {
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	while(test--) {
		cin >> n >> m;
		fore(i,0,n)
			fore(j,0,m)
				cin >> table[i][j];
				
		int mn=0,mx = 1e6,mid;
		
		while(mx-mn>1) {
			mid = (mx+mn)>>1;
			memset(memo,0,sizeof memo);
			memo[0][0] = mid;
			
			
			fore(i,0,n)
				fore(j,0,m)
					fore(k,0,2) {
						int ii = i + mi[k], jj = j + mj[k];
						if(ii >= 0 && jj >= 0 && memo[ii][jj] > 0) {
							memo[i][j] = max(0,max(memo[i][j],memo[ii][jj]+table[i][j]));
						}
					}
			
			if(memo[n-1][m-1] > 0)
				mx = mid;
			else
				mn = mid;
		}
		cout << mx << endl;
	
	
	
	
	}
	
	
	
}
