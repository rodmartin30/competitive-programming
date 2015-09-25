#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
#define M 1005
#define make_pair mp
#define PI M_PI
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector<vector<ii> > graphs,grapht;
vector<int> dists,distt;

void dijkstra(int N, int s, vector<int> &dist, vector<vector<ii> > graph) {
  dist[s] = 0;
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,s));
  
  while(!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;
    if(d > dist[u] ) continue;
    int t = graph[u].size();

    fore(i,0,t) {
      ii v = graph[u][i];
      if(dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first],v.first));
      }
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	int n,m,k,w,u,v,s,t,caso=0,test;
	cin >> test;
	while(test--) {
	
		cin >> n >> m >> k >> s >> t;
		s--; t--;
		
		graphs.clear(); graphs.resize(n);
		grapht.clear(); grapht.resize(n);
		
		dists.clear(); dists.resize(n,1e9);
		distt.clear(); distt.resize(n,1e9);
		
		fore(i,0,m) {
			cin >> u >> v >> w;
			u--; v--;
			graphs[u].push_back(ii(v,w));
			grapht[v].push_back(ii(u,w));
		}
		
		dijkstra(n,s,dists,graphs);
		dijkstra(n,t,distt,grapht);
		
		int mn = dists[t];
		fore(i,0,k) {
			cin >> u >> v >> w;
			u--; v--;
			int a = dists[u] + w + distt[v],b = dists[v] + w + distt[u];
			mn = min(mn,a);
			mn = min(mn,b);
		}
		
		if(mn == 1e9)
			cout << -1 << endl;
		else
			cout << mn << endl;
		
		
		
		
	}
}
