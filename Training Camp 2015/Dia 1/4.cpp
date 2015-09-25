#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;

map<int,vector<int> > graph;
map<int,int> dfs_num,dfs_low,visited;
stack<int> s;
int N,r;
void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = N++;
  s.push(u);
  visited[u] = 1;
  fore(i,0,graph[u].size()) {
    int v = graph[u][i];
    if(dfs_num[v] == 0)
      tarjanSCC(v);
    if(visited[v] == 1) {
      dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }
  }
  if(dfs_low[u] == dfs_num[u]) {
    r++;
    while(1) {
      int v = s.top(); s.pop(); visited[v] = 0;
      if(u == v)
	break;
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  int p,n,a,b;
  while(cin >> p >> n) {
    graph.clear();
    dfs_num.clear(); dfs_low.clear(); visited.clear();
    fore(i,0,n) {
      cin >> a >> b;
      graph[-a].push_back(b);
      graph[-b].push_back(a);
    }
    N = 1;
    r =0;
    fore(i,1,p+1)
      if(dfs_num[i]==0)
	tarjanSCC(i);
	
    bool flag = false;
    fore(i,1,p+1) {
      if(dfs_low[i] == dfs_low[-i])
	flag = true;
    }
    while(!s.empty())
      s.pop();
    if(!flag)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
}
