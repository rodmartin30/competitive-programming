#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
#define M 1005
#define S 200015
#define PI M_PI
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


vector<vector<int> > graph;
int parent[M],num[M],low[M];
int N;

void pointAndBridges(int u) {
	num[u] = low[u] = ++N;
	int t = graph[u].size(),v;
	
	for(int i = 0;i<t ;i++) {
		v = graph[u][i];
		if(num[v] == 0) {
			parent[v] = u;
			cout << u+1 << " " << v+1 << endl ;
			pointAndBridges(v);
			
			if(low[v] > num[u]) 
					cout << v+1 << " " << u+1 << endl;
					
			low[u] = min(low[u],low[v]);
		}
		else {
			if(v != parent[u]) {
				if(num[u] > num[v])
					cout << u+1 << " " << v+1 <<  endl;
				low[u] = min(low[u],num[v]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n,m,u,v,caso=0,t;
	string s;
	while(cin >> n >> m && m && n) {
		
		graph.clear();
		graph.resize(n);
		memset(num,0,sizeof num);
		memset(low,0,sizeof low);
		memset(parent,-1,sizeof parent);
		
		N = 0;
		fore(i,0,m) {
			cin >> u >> v;
			u--;
			v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		cout << ++caso << endl << endl;
		fore(i,0,n)
			if(num[i] == 0)
				pointAndBridges(i);
		cout << "#" << endl;
	}

}
