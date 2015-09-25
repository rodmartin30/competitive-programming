#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
#define N 45
#define MAX_N 85
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int points[N],matchs[N][N],lleft[N],res[MAX_N][MAX_N];
int s,t,f,mf,u,v,n;
vector<int> p;
vector<vector<int> > graph;
void augment(int k, int midEdge) {
	if(k == s) {
		f = midEdge;
	}
	else if(p[k] != -1) {
		augment(p[k],min(midEdge,res[p[k]][k]));
		res[p[k]][k] -= f;
		res[k][p[k]] += f;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int m,g,jugados;
	while(cin >> n >> m >> g && n && m && g) {
		memset(points,0,sizeof points);
		memset(matchs,0,sizeof matchs);
		fore(i,0,n)
			lleft[i] = (n-1)*m;
		fore(i,0,n)
			fore(j,0,n)
				if(i != j)
					matchs[i][j] = m;
		
		fore(i,0,g) {
			char c;
			cin >> u >> c >> v;
			matchs[u][v]--;
			matchs[v][u]--;
			lleft[u]--;
			lleft[v]--;
			if(c == '=') {
				points[u]++;
				points[v]++;
			}
			else 
				points[v]+=2;
		}
		fore(i,1,n) {
			points[0]+= matchs[0][i]*2;
			g+= matchs[0][i];
			lleft[i]-= matchs[0][i];
			matchs[0][i] = 0;
			matchs[i][0] = 0;
		}
		bool flag = true;
		int totalpoint = 0;
		fore(i,1,n) {
			totalpoint += lleft[i];
			if(points[i] >= points[0])
				flag = false;
		}
		if(!flag)
			cout << "N" << endl;
		else if(!totalpoint)
			cout << "Y" << endl;
		else {
			
			memset(res,0,sizeof res);
			graph.clear();
			graph.resize(MAX_N);
						
			fore(i,1,n) {
				graph[0].push_back(i);
				
				graph[i+n].push_back(n);
				graph[n].push_back(i+n);
				
				res[0][i] = lleft[i];
				res[i+n][n] = points[0] - points[i] -1 ;
			}
			
			fore(i,1,n) {
				graph[i].push_back(i+n);
				res[i][i+n] = lleft[i];
				graph[i+n].push_back(i);
				
				fore(j,1,n) {
					int w = matchs[i][j];
					if(w && i != j) {
						graph[i].push_back(j+n);
						graph[j+n].push_back(i);
						res[i][j+n] = w;
					}
				}
			}
			s = 0; t = n;
			mf = 0;
		
			while(1) {
				f = 0;
				bitset<MAX_N> vis;
				vis.reset();
				vis[s] = 1;
				queue<int> q; q.push(s);
				p.assign(MAX_N,-1);
				while(!q.empty()) {
					u = q.front(); q.pop();
					if(u == t) break;
					for(int j = 0;j<graph[u].size();j++) {
						v = graph[u][j];
						if(res[u][v] > 0 && !vis[v])
							vis[v] = 1, q.push(v),p[v] = u;
					}
				}
	
				augment(t,1e9);
				if(f == 0)
					break;
		
				mf += f;
			}
			if(mf == totalpoint)
				cout << "Y" << endl;
			else
				cout << "N" << endl;
		
		}
	}
}
		

