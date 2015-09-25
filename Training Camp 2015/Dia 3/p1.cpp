#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
#define mod 1000000007
#define mp make_pair
using namespace std;

int in[205],n,k;
long long memo[2][100005];

int main() {
  ios_base::sync_with_stdio(false);
  int barsa,real,k;
  while(cin >> barsa >> real) {
    cin >> n;
    fore(i,1,n+1)
      cin >> in[i];
		
	int t = min(barsa,real);
		
		memo[0][0] = 1;
	fore(i,1,t+1)
		memo[0][i] = 0;
	int i,g;
	fore(h,1,n+1) {
		fore(j,0,t+1) {
			i = h % 2;
			g = (i+1) % 2;
			k = in[h];
			memo[i][j] = 0;
			if(!(k%2) && k/2 <= j)
				memo[i][j]+=memo[g][j-k/2];
			if(k <= j)
				memo[i][j] += memo[g][j-k];
			memo[i][j] += memo[g][j];
			
			memo[i][j] = memo[i][j] % mod;
		}
	}
    cout << memo[i][t] << endl;

  }

}

