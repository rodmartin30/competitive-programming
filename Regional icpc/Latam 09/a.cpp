#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
#define M 100005
#define make_pair mp
#define PI M_PI
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<vector<int> > graph;
int p,memo[M];
int dp(int u) {
	if(memo[u] != -1)
		return memo[u];
	int t = graph[u].size(),m,res;
	
	if(!t)
		return 1;
		
	vector<int> k(t);
	fore(i,0,t) {
		k[i] = dp(graph[u][i]);
	}
	sort(k.begin(),k.end());
	
	m = p*t/100;
	if(m*100/t < p)
		m++;
	
	res = 0;
	fore(i,0,m)
		res+=k[i];
	
	return memo[u] = res;

}


int main() {
	ios_base::sync_with_stdio(false);
	int n;
	
	while(cin >> n >> p && n && p) {
		graph.clear(); graph.resize(n+1);
		memset(memo,-1,sizeof memo);
		int u;
		fore(i,1,n+1) {
			cin >> u;
			graph[u].push_back(i);
		}
		cout << dp(0) << endl;
	
	}
		
}
