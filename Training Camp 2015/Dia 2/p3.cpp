#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)

using namespace std;
long long mod = 9999991;
int in[25],padre[25];
long long memo[1<<20],n;
vector<vector<int> > graph;

map<int,pair<int,int> > g;

long long dp(int mask) {
  if(__builtin_popcount(mask) == n-1)
    return 1;

  if(memo[mask] != -1)
    return memo[mask];

  long long res = 0;
  fore(i,0,n) {
    if(mask & (1 << i)) {
      int t = graph[i].size();
      fore(j,0,t) {
	if((mask & (1 << graph[i][j])) == 0) {
	  res+= dp(mask | (1 << graph[i][j]));
	  res = res % mod;
	}
      }
    }
  }
  return memo[mask] = res;
}

int main() {
  int test;
  cin >> test;

  while(test--) {
    cin >> n;

    graph.clear();
    graph.resize(n);

    fore(i,0,n) {
      cin >> in[i];
      in[i]--;
    }
    if(n == 1) {
      cout << 1 << endl;
      continue;
    }

    g.clear();
    if(in[1]>in[0])
      g[in[0]] = make_pair(-1,in[1]);
    else
      g[in[0]] = make_pair(in[1],-1);

    g[in[1]] =  make_pair(-1,-1);
    graph[in[0]].push_back(in[1]);

    int root = in[0],node;
    fore(i,2,n) {
      root = in[0];
      node = in[i];
      bool flag = true;
      while(flag) {
	if(node < root && g[root].first == -1) {
	  g[root].first = node;
	  g[node] = make_pair(-1,-1);
	  graph[root].push_back(node);
	  flag = false;
	}
	else if(node > root && g[root].second == -1) {
	  g[root].second = node;
	  g[node] = make_pair(-1,-1);
	  graph[root].push_back(node);
	  flag = false;
	}
	else {
	  if(node < root)
	    root = g[root].first;
	  else
	    root = g[root].second;
	}
      }
    }

    
    memset(memo,-1,1<<(n+3));

    cout << dp(1 << in[0]) << endl;
  }
}
