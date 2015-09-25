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


map<string,int> ind;
vector<vector<int> > graph;
vector<int> parent,num,low,articulation_vertex;
vector<string> res;
string in[105];
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
	ios_base::sync_with_stdio(false);
	int n,m,u,v,caso=0;
	string s;
	while(cin >> n && n) {
		if(caso)
			cout << endl;
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
		res.clear();
		N = 0; p = 0;
		
		fore(i,0,n) {
			cin >> in[i];
			ind[in[i]] = i;
		}
		cin >> m;
		fore(i,0,m) {
			cin >> s;
			u = ind[s];
			cin >> s;
			v = ind[s];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		fore(i,0,n) {
			if(!num[i]) {
				root = i;
				children = 0;
				pointAndBridges(i);
				articulation_vertex[i] = children > 1;
			}
		}
		fore(i,0,n)
			if(articulation_vertex[i]) {
				res.push_back(in[i]);
			}
			
		sort(res.begin(),res.end());
		cout << "City map #" << ++caso << ": " << res.size() << " camera(s) found" << endl;
		fore(i,0,res.size())
			cout <<  res[i] << endl;
		
	}

}
