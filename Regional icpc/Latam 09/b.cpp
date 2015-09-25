#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int mi[4] = {0,1,0,-1},mj[4] = {1,0,-1,0};
int a[105][105],b[105][105],n,r,c,k;

bool bound(int i, int j) {
	if(i >= 0 && i < r && j >= 0 && j < c)
		return true;
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);

	while(cin >> n >> r >> c >> k && n && r && c && k) {
	
		fore(i,0,r)
			fore(j,0,c)
				cin >> a[i][j];
		int g = 0;
		int t = k;
		while(k--) {
			if(!g) {
				memset(b,-1,sizeof b);
				fore(i,0,r)
					fore(j,0,c) {
						fore(h,0,4) {
							int ni = i + mi[h],nj = j + mj[h];
							if(bound(ni,nj)) {
								if(((a[i][j] + 1) % n) == a[ni][nj])
									b[ni][nj] = a[i][j];
							}
						}
					}
				fore(i,0,r)
					fore(j,0,c) {
						if(b[i][j] == -1)
							b[i][j] = a[i][j];
					}
			}
			else {
				memset(a,-1,sizeof a);
				fore(i,0,r)
					fore(j,0,c) {
						fore(h,0,4) {
							int ni = i + mi[h],nj = j + mj[h];
							if(bound(ni,nj)) {
								if(((b[i][j] + 1) % n) == b[ni][nj])
									a[ni][nj] = b[i][j];
							}
						}
					}
				fore(i,0,r)
					fore(j,0,c) {
						if(a[i][j] == -1)
							a[i][j] = b[i][j];
					}
			}
			g = g ^ 1;
		}
		if(t%2) {
			fore(i,0,r) {
				fore(j,0,c) {
					if(j)
						cout << " ";
					cout << b[i][j];
				}
				cout << endl;
			}
		} 
		else {
			fore(i,0,r) {
				fore(j,0,c) {
					if(j)
						cout << " ";
					cout << a[i][j];
				}
				cout << endl;
			}
		}
	
	
	
	
	}
	
}
