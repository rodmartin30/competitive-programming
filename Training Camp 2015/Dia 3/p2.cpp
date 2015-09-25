#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define N 500005
using namespace std;

typedef long long ll;

ll memo[N][2];
int cons[N],p;
vector<vector<int> > graph;

ll dp(int u, int e) {
	if(memo[u][e] != -1)
		return memo[u][e];
	int t = graph[u].size(),v;
	ll sum = 0,res=0,g=-1;
	if(!t)
		return 0;
	
	fore(i,0,t)
		sum += dp(graph[u][i],0);
	res = sum;

	if(e == 0) {
		fore(i,0,t) {
			v = graph[u][i];
			ll tmp = sum - dp(v,0) + dp(v,1) + 1000;
			if(tmp > res) {
				res = tmp;
				cons[p] = v;
			}
		}
		if(res > sum)
			p++;
	}
	return memo[u][e] = res;

}

int main() {
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	
	while(test--) {
		int n,tmp,mx;
		p = 0;
		cin >> n;
		graph.clear();
		graph.resize(n);
		
		fore(i,1,n) {
			cin >> tmp;
			graph[--tmp].push_back(i);
		}
		memset(memo,-1,sizeof memo);
		cout << dp(0,0) << endl;
		sort(cons,cons+p);
		fore(i,0,p) {
			if(i)
				cout << " ";
			cout << cons[i]+1;
		}
		cout << endl;
	}
}
