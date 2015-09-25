#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<vector<ii> > graph;
vector<int> dist1,dist2;

void dijkstra(int N, int s, vector<int> &dist) {
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
	//ios_base::sync_with_stdio(false);
	
	int n,m,u,v,w,res,d;
	while(cin >> n >> m) {
		graph.clear();
		graph.resize(n);
		dist1.clear();
		dist1.resize(n,1e9);
		dist2.clear();
		dist2.resize(n,1e9);
		
		fore(i,0,m) {
			cin >> u >> v >> w;
			graph[u].push_back(mp(v,w));
			graph[v].push_back(mp(u,w));
		}
		
		dijkstra(n,0,dist1);
		dijkstra(n,n-1,dist2);
		
		res = 0;
		d = dist1[n-1];
		fore(i,0,n) {
			int t = graph[i].size();
			fore(j,0,t) {
				v = graph[i][j].first;
				w = graph[i][j].second;
				if((dist1[i] + w + dist2[v] == d) || (dist1[v] + w + dist2[i] == d)) {
					res+=w;
				}
			}
		
		}
		cout << res << endl;
	
	
	}
}
