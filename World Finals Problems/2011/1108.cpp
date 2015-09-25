#include <bits/stdc++.h>
#include <math.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
#define M 50010
#define S 200015
#define PI M_PI
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

ii in[M];

vector<vector<int> > graph; 
vector<int> num,low,parent,articulation_vertex; 
int N,r,dfsRoot,rootChildren,ap,p; 
bool s;
void articulationP(int u) {
  low[u] = num[u] = ++N;
  fore(i,0,graph[u].size()) {
    int v = graph[u][i];
    if(num[v] == 0) {
    	parent[v] = u;
    	if(u == dfsRoot) rootChildren++;
    	articulationP(v);
    	
    	if(low[v] >= num[u]) {
    		articulation_vertex[u] = 1;
    		ap++;
    	}
    	
    	
      low[u] = min(low[u],low[v]); 
    }
    else if(v != parent[u])
    	low[u] = min(num[v],low[u]);
  }
 	
}

ll floodfill(int u) {
	num[u] = 1;
	int t = graph[u].size(),v,res  = 1;
	
	fore(i,0,t) {
		v = graph[u][i];
		if(articulation_vertex[v] == 0 && num[v] == 0)
			res+=floodfill(v);
		else if(articulation_vertex[v]) {
			if(p==-1)
				p = v;
			else if(v != p)
				s = 1;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n,mx,caso=0;
	while(cin >> n && n) {
		mx = 1;
		N=0; r=0; ap=0;
		fore(i,0,n) {
			cin >> in[i].first >> in[i].second;
			mx = max(mx,in[i].first); mx = max(mx,in[i].second);
			in[i].first--; in[i].second--;
		}
		graph.clear();
		graph.resize(mx);
		
		low.clear();
		low.resize(mx,0);
		parent.clear();
		parent.resize(mx,-1);
		num.clear();
		num.resize(mx,0);
		articulation_vertex.clear();
		articulation_vertex.resize(mx,0);
		int u,v;
		fore(i,0,n) {
			u = in[i].first;
			v = in[i].second;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		ll res = 0,forms = 1,tmp;
		fore(i,0,mx)
			if(num[i] == 0) {
				dfsRoot = i; rootChildren = 0;
				articulationP(i);
				articulation_vertex[i] = (rootChildren > 1);
			}
		
		num.assign(mx,0);
		fore(i,0,mx) {
			if(articulation_vertex[i] == 0 && num[i] == 0) {
				p=-1;
				s = false;
				tmp = floodfill(i);
				if(!s) {
					res++;
					forms*=tmp;
				}
			}
		}
		if(res==1) {
			res++;
			forms = (mx*(mx-1))/2;
		}
		cout << "Case " << ++caso << ": " << res << " " << forms << endl;
	}

}
