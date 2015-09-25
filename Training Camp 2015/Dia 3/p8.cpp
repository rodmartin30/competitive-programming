#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int n,distmx;
vector<vector<int> > graph,check;
vector<int> marbles,padre,visited,dist;

void bfs(int s) {
  distmx = 0;
  visited.clear(); visited.resize(n,0);
  dist.clear(); dist.resize(n,100000);
  check.clear(); check.resize(n+10);

  visited[s] = 1;
  dist[s] = 0;
  queue<int> q; q.push(s);
  int u,v,t;
  while(!q.empty()) {
    u = q.front();
    q.pop();
    t = graph[u].size();
    fore(i,0,t) {
      v = graph[u][i];
      if(visited[v] == 0) {
	visited[v] = 1;
	dist[v] = dist[u] + 1;
	distmx = max(distmx,dist[v]);
	check[dist[v]].push_back(v);
	q.push(v);	
      }
    }
    }
}

int main() {
  int v,m,d,s,g,h,son;
  long long res;
  while(cin >> n && n != 0) {

    res = 0;
    graph.clear(); graph.resize(n);
    marbles.clear(); marbles.resize(n);
    padre.clear(); padre.resize(n,-1);

    fore(i,0,n) {
      cin >> v >> m >> d;
      v--;
      marbles[v] = m;

      fore(j,0,d) {
	cin >> son;
	son--;
	graph[v].push_back(son);
	graph[son].push_back(v);
	padre[son] = v;
      }
    }

    fore(i,0,n) {
      if(padre[i] == -1)
	s = i;
    }
    
    bfs(s);
    
    for(int i = distmx;i>0;i--) {
      int t = check[i].size();
      
      fore(j,0,t) {
        v = check[i][j];
	g = marbles[v];

	if(g > 1) {
	  marbles[padre[v]] += abs(g-1);
	  res+=abs(g-1);
	  marbles[v] = 1;
	}
	else if(g < 1) {
	  marbles[padre[v]] -= abs(g-1);
	  res+=abs(g-1);
	  marbles[v] = 1;
	}
      }
    }
    cout << res << endl;




  }

}
