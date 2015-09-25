#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)

using namespace std;

typedef long long ll;
vector<vector<int> > graph;
ll ways[30005],memo[30005];
int n;
long long dp(int nodo) {
  if(memo[nodo] != -1)
    return memo[nodo];
  if(nodo == n-1)
    return 1;
  ll res = 0;
  int v;
  fore(i,0,graph[nodo].size()) {
    v = graph[nodo][i];
    res = max(res,dp(v) + ways[v]);
  }
  return memo[nodo] = res;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n,s,a,b;
  cin >> n >> s;
  graph.resize(n);
  
  fore(i,0,s) {
    cin >> a >> b;
    a--; b--;

    graph[a].push_back(b);
  }
  ways[n-1] = 1;
  for(int i = n-2;i>=0;i--) {
    int t = graph[i].size(),v;
    ll w = 0;
    fore(j,0,t) {
      v = graph[i][j];
      w += ways[v];
    }
    ways[i] = w;
  }
  n--;
  memset(memo,-1,sizeof memo);

  cout << dp(0) + ways[0] << endl;
    
}
