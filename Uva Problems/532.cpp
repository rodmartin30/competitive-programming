#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <utility>
#include <map>
#include <sstream>
#include <cstring>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
fore(int i=m;i<=n;i++)
#define T 35
using namespace std;

int l,n,m;
char table[T][T][T];
struct terna{
	int d,f,c;
};
vector<vector<int> > graph;
vector<int> distancia,visited;
int dd[] = {1,-1,0,0,0,0};
int dx[] = {0,0,1,-1,0,0};
int dy[] = {0,0,0,0,1,-1};
bool bound(int pl, int pn, int pm)
{
	bool flag = false;
	if(pl>=0 && pl<=l-1 && pn>=0 && pn<=n-1 && pm>=0 && pm<=m-1)
		flag = true;
	return flag;
}
void bfs(int s)
{
	int u,v;
	distancia[s] =0;
	visited[s] = 1;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		fore(i,0,graph[u].size())
		{
			v = graph[u][i];
			if(visited[v]==0)
			{
				distancia[v] = distancia[u] +1;
				visited[v] = 1;
				Q.push(v);
			}
		}
	}
}
int main()
{
	terna s,e;
	while(cin >> l >> n >> m && l!=0 && n!=0 && m!=0)
	{
		graph.clear(); graph.resize(l*m*n);
		visited.clear(); visited.resize(l*m*n,0);
		distancia.clear(); distancia.resize(m*l*n,-1);
		fore(k,0,l)
			fore(i,0,n)
				fore(j,0,m)
				{
					cin >> table[k][i][j];
					if(table[k][i][j]== 'S')
					{
						s.d = k;
						s.f = i;
						s.c = j;
					}
					if(table[k][i][j]== 'E')
					{
						e.d = k;
						e.f = i;
						e.c = j;
					}	
				}
		fore(k,0,l)
			fore(i,0,n)
				fore(j,0,m)
					fore(h,0,6)
					{
						int dm = k + dd[h];
						int nm = i + dx[h];
						int mm = j + dy[h];
						if(bound(dm,nm,mm) && table[k][i][j] != '#' && table[dm][nm][mm] != '#')
							graph[(k*n*m)+(i*m+j)].push_back((dm*n*m)+(nm*m+mm));
					}
					
		/*fore(i,0,l*n*m)
		{
			cout << i << " : ";
			fore(j,0,graph[i].size())
				cout << graph[i][j] << " ";
			cout << endl;
		}*/		
					
		bfs((s.d*n*m)+(s.f*m+s.c));
		if(distancia[(e.d*n*m)+(e.f*m+e.c)] == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",distancia[(e.d*n*m)+(e.f*m+e.c)]);
						
	}
}	
