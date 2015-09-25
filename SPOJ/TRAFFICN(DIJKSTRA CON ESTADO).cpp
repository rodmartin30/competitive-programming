#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
#define M 10005
#define make_pair mp
#define PI M_PI
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct state {
	int u,w,f;
	state(int _u, int _w, bool _f)
		: u(_u), w(_w),f(_f) {}
	
	bool operator < (const state &other) const {
		return w > other.w;
	}
};


vector<vector<state> > graph[2];
bool visited[M][2];
int dist[M][2];

int dijkstra(int N, int s,int t) {
	memset(visited, 0, sizeof visited);
	fore(i,0,N) {
		dist[i][0] = 1e9;
		dist[i][1] = 1e9;
	}
  dist[s][0] = 0;
  priority_queue<state> pq; pq.push(state(s,0,0));
  
  while(!pq.empty()) {
    state front = pq.top(); pq.pop();
    int u = front.u, w = front.w, f = front.f,v;
  	if(visited[u][f]) continue;
  	
  	visited[u][f] = 1;
  	
  	int t = graph[f][u].size();
  	
  	fore(i,0,t) {
  		state v = graph[f][u][i];
  		int newv = v.u, neww = v.w, newf = f | v.f;
  		if(!visited[newv][newf])
  			if(dist[u][f] + neww < dist[newv][newf]) {
  				dist[newv][newf] = dist[u][f] + neww;
  				pq.push(state(newv,dist[u][f] + neww,newf));
  			}
  	}
  }
  return min(dist[t][0],dist[t][1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	int test,n,m,k,u,v,w,s,t;
	cin >> test;
	
	while(test--) {
		cin >> n >> m >> k >> s >> t;
		s--; t--;
		
		fore(i,0,2) {
			graph[i].clear();
			graph[i].resize(n);
		}
		
		fore(i,0,m) {
			cin >> u >> v >> w;
			u--; v--;
			graph[0][u].push_back(state(v,w,0));
			graph[1][u].push_back(state(v,w,1));
		}
		
		fore(i,0,k) {
			cin >> u >> v >> w;
			u--; v--;
			graph[0][u].push_back(state(v,w,1));
			graph[0][v].push_back(state(u,w,1));
		}
		int res = dijkstra(n,s,t);
		if(res == 1e9)
			cout << -1 << endl;
		else
			cout << res << endl;	
	}
		
}
