#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
#define MAX_N 105
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<vector<int> > graph;

int s,t,f,mf,res[MAX_N][MAX_N];
vector<int> p;
void augment(int v, int midEdge) {
	if(v == s) {
		f = midEdge;
	}
	else if(p[v] != -1) {
		augment(p[v],min(midEdge,res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	int n,c,caso = 0;
	
	while(cin >> n && n) {
		cin >> s >> t >> c;
		s--;
		t--;
		
		graph.clear();
		graph.resize(n);
		memset(res,0,sizeof res);
		
		int u,v,w;
		
		fore(i,0,c) {
			cin >> u >> v >> w;
			u--; v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
			res[u][v] += w;
			res[v][u] += w;
		}	
		
		mf = 0;
		
		while(1) {
			f = 0;
			bitset<MAX_N> vis;
			vis.reset();
			vis[s] = 1;
			queue<int> q; q.push(s);
			p.assign(n,-1);
			while(!q.empty()) {
				u = q.front(); q.pop();
				if(u == t) break;
				for(int j = 0;j<graph[u].size();j++) {
					v = graph[u][j];
					if(res[u][v] > 0 && !vis[v])
						vis[v] = 1, q.push(v),p[v] = u;
				}
			}
		
			augment(t,1e9);
			if(f == 0)
				break;
			
			mf += f;
		}
		cout << "Network " << ++caso << endl << "The bandwidth is " << mf << "." << endl << endl;
		
	
	}
}
		

