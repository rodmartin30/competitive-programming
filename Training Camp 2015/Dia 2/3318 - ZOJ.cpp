#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define MAX 500005
using namespace std;

bool graph[31][31][31];
int paths[35][35],visited[35],distancia[35];
vector<vector<int> > levels,caminos;
int t,n,dist,jump,pos,dist2,dist3;

void bfs(int mapa, int s) {
  dist = -1;

  levels.clear();
  levels.resize(n);
  memset(visited,false,sizeof visited);
  memset(distancia,1000,sizeof distancia);

  queue<int> q;
  q.push(s);
  distancia[s] = 0;
  levels[0].push_back(s);
  visited[s] = 1;

  while(!q.empty()) {
    int u = q.front();
    q.pop();
      
    fore(i,0,n) {
      if(graph[mapa][u][i] && !visited[i]) {
	visited[i] = 1;
	distancia[i] = distancia[u] + 1;
	levels[distancia[i]].push_back(i);
	q.push(i);
	if(i == t)
	  dist = distancia[i];
      }
    }
  }

}

int bfs2(int mapa, int s) {

  memset(visited,false,sizeof visited);
  memset(distancia,1000,sizeof distancia);

  queue<int> q;
  q.push(s);
  distancia[s] = 0;
  visited[s] = 1;

  while(!q.empty()) {
    int u = q.front();
    q.pop();
      
    fore(i,0,n) {
      if(graph[mapa][u][i] && !visited[i]) {
	visited[i] = 1;
	distancia[i] = distancia[u] + 1;
	q.push(i);
  }
  }
  }
  return distancia[t];
}

void make(int l,int ant,int mapa,vector<int> f ) {
  if(l == dist) {
    if(graph[mapa][ant][t] == 1) {
      f.push_back(t);
      caminos.push_back(f);
      return ;
    }
  }
  int d = levels[l].size(),lugar = f.size();
  bool flag = false;
  fore(i,0,d) {
    int v = levels[l][i];
    if(graph[mapa][ant][v] == 1) {
      if(!flag) {
	f.push_back(v);
	flag = true;
      }
      else {
	f[lugar] = v;
      }
      make(l+1,v,mapa,f);
    }
  }

}

bool canReach(int mapa,int s,int i) {
  
  int ant = s,v;
  fore(j,1,dist+1) {
    v = caminos[i][j];
    if(!graph[mapa][ant][v])
      return false;
    ant = v;
  }
  return true;
}


int main() {
  ios_base::sync_with_stdio(false);
  int test,m,s,a,b,mapa,r,distintos;
  cin >> test;

  while(test--) {
    cin >> n >> m >> s >> t;
    
    s--; t--;
    memset(graph,false,sizeof graph);
    distintos = 0;
    jump = 0;
    
    fore(i,0,m) {
      cin >> r;
      fore(j,0,r) {
	cin >> a >> b;
	a--; b--;
	graph[i][a][b] = 1;
	graph[i][b][a] = 1;
      }
    }
    
    caminos.clear();
    mapa = 0;
    int res = 0;
    long long sum = 0;
    while(mapa < m) {
      caminos.clear();
      bfs(mapa,s);
      sum+=dist;
      if(mapa == m)
				break;
      vector<int> f;
      f.push_back(s);
      caminos.clear();
      make(1,s,mapa,f);
      
      int d = caminos.size(),quedan;
      quedan = d;
      mapa++;
			while(mapa < m && quedan > 0) {
				if(mapa == 1)
					dist3 = bfs2(mapa,s);
				if(mapa+1 < m) {
					dist2 = dist3;
					dist3 = bfs2(mapa+1,s);
				}
				else {
					dist2 = dist3;
				}
			
				if(mapa+1 == m) {  		
					fore(i,0,d) {
						if(caminos[i].size() != 0) {
							if(!canReach(mapa,s,i)) {
								quedan--;
								caminos[i].clear();
							}
						}
					}
					if(quedan) {
						sum+=dist2;
						mapa++;
					}
				}
				else {
			
					// Aca es la parte donde conviene usar un camino mas largo para evitar change
			
					if(dist2+1 == dist && dist == dist3) {
						fore(i,0,d) {
							if(caminos[i].size() != 0) {
								if(!canReach(mapa+1,s,i)) {
									quedan--;
									caminos[i].clear();
								}
							}
						}
						if(quedan) {
							fore(i,0,d) {
							if(caminos[i].size() != 0) {
								if(!canReach(mapa,s,i)) {
									quedan--;
									caminos[i].clear();
									}
								}
							}
						
							if(quedan) {
								sum+=dist3+dist3;
								mapa+=2;
							}
							else {
								
							}
						}
					}
					else {
						if(dist != dist2) {
							break;
						}
						else {
							fore(i,0,d) {
								if(caminos[i].size() != 0) {
									if(!canReach(mapa,s,i)) {
										quedan--;
										caminos[i].clear();
									}
								}
							}
							if(quedan) {
								sum+=dist2;
								mapa++;
							}
						}
					}	
				}
			}
			if(mapa<m) {
				res++;
			}
  }
    cout << sum+res << endl;
  }
}



