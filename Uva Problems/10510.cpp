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

vector<vector<int> > graph; 
vector<int> num,low,visited;
int check[M];
stack<int> s;
int N,r,root,back; 
bool res,flag;

void tarjan(int u) {
  low[u] = num[u] = ++N; 
  s.push(u); 
  visited[u] = 1;
  fore(i,0,graph[u].size()) {
    int v = graph[u][i];
    
    if(num[v] == 0)
      tarjan(v);
    if(visited[v] == 1) {
      low[u] = min(low[u],low[v]);
    }
  }
  if(low[u] == num[u]) { 
    r++; 
    while(1) {
      int v = s.top(); s.pop(); visited[v] = 0; 
      if(u == v)
			break;
    }
  }
}

void dfs(int u, int minback) {
	check[u] = 1;
	int t = graph[u].size(),v,back=0;
	bool hasBack = false;
	
	fore(i,0,t) {
		v = graph[u][i];
		if(num[v] < num[u])
			hasBack = 1;
	}
	
	if(hasBack)
		minback = num[u];
	
	
	fore(i,0,t) {
		int v = graph[u][i];
		if(check[v] == 2)
			res = false;
		else if(num[v] < minback) {
			back++;
			if(back>1)
				res = false;
		}
		else
			dfs(v,minback);
	}
	check[u] = 2;
}


int main() {
	ios_base::sync_with_stdio(false);
	int n,m,test,u,v;
	cin >> test;
	while(test--) {
		cin >> n >> m;
		memset(check,0,sizeof check);
		graph.clear(); graph.resize(n);
		num.clear(); num.resize(n,0);
		low.clear(); low.resize(n,0);
		visited.clear(); visited.resize(n,0);
		
		fore(i,0,m) {
			cin >> u >> v;
			graph[u].push_back(v);
		}
		
		r = 0; N = 0;
		res = true; back = 0;
		fore(i,0,n) {
			if(num[i] == 0)
				tarjan(i);
		}
		dfs(0,-1);
		res &= (r < 2);
			
		if(res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	
	
	}
		
}
