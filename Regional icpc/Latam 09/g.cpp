#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
using namespace std;

typedef long long ll;
int table[505][505],diag[1005][1005],sz[1005];

int main(){
	ios_base::sync_with_stdio(false);
	int n,m,q,l,u,t,mx,cur;
	while(cin >> n >> m && n && m) {
		fore(i,0,n)
			fore(j,0,m)
				cin >> table[i][j];
		
		int h = 0,f=0,g;
		
		for(int j = m-1;j>=0;j--) {
			h = 0;
			g = j;
			for(int i=0;i<n && g<m;i++) {
				diag[f][h++] = table[i][g++];
			}
			sz[f++] = h;
		}
		
		for(int i=1;i<n;i++) {
			h = 0;
			g = i;
			for(int j =0;j<m && g <n;j++) {
				diag[f][h++] = table[g++][j];
			}
			sz[f++] = h;
		}
		
		cin >> q;
		
		fore(j,0,q) {
			cin >> l >> u;
			mx = 0;
			fore(i,0,f) {
				cur = 0;
				int a,b;
				a = lower_bound(diag[i],diag[i]+sz[i],l) - diag[i];
				b = upper_bound(diag[i],diag[i]+sz[i],u) - diag[i];
				if(a < n && b < m) {
					cur = b-a;
				}
				else if(a < n) {
					cur = sz[i] - a;
				}
				
				mx = max(mx,cur);
			}
			cout << mx << endl;
			
		}
		cout << "-" << endl;
	
	}
}
		

