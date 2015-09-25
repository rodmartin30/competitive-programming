#include <bits/stdc++.h>
#include <math.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
#define M 50010
#define S 200015
#define PI M_PI
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


vector<vector<int> > graph;
vector<int> parent,num,low,articulation_vertex;
int N,p,root,children;

void pointAndBridges(int u) {
	num[u] = low[u] = ++N;
	int t = graph[u].size(),v;
	
	for(int i = 0;i<t ;i++) {
		v = graph[u][i];
		if(num[v] == 0) {
			parent[v] = u;
			if(u==root) children++;
			
			pointAndBridges(v);
			
			if(low[v] >= num[u]) 
				articulation_vertex[u] = 1;
			//if(low[v] > num[u])
				//cout << "Bridge founded " << u << " " << v << endl;
			
			low[u] = min(low[u],low[v]);
		}
		else if(v != parent[u]){
			low[u] = min(low[u],num[v]);
		}
	}
}

    
int main() {
	//ios_base::sync_with_stdio(false);
	int n,m,u,v;
	string s;
	while(scanf("%d\n",&n) && n) {
		graph.clear();
		graph.resize(n);
		low.clear();
		low.resize(n,0);
		num.clear();
		num.resize(n,0);
		parent.clear();
		parent.resize(n,-1);
		articulation_vertex.clear();
		articulation_vertex.resize(n,0);
		N = 0; p = 0;
		while(getline(cin,s)) {
			istringstream in(s);
			in >> u;
			if(!u) break;
			u--;
			while(in >> v) {
				v--;
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}
		fore(i,0,n) 
			if(num[i] == 0) {
				root = i;
				children = 0;
				pointAndBridges(i);
				articulation_vertex[i] = children > 1;
			}
		fore(i,0,n)
			p += articulation_vertex[i];
		cout << p << endl;
	
	
	
	}

}
