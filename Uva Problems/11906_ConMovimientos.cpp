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
#define T 105
using namespace std;

int table[T][T];
int test,r,c,m,n,water,caso=1;
bool bound(int x,int y)
{
	return x>=0 && x<r && y>=0 && y<c;
}
vector<set<int> > graph;
vector<int> visited;
int odd,even;
void dfs(int s)
{
	visited[s] = 1;
	if(graph[s].size()%2==0)
		even++;
	else
		odd++;
	
		
	for(set<int>::iterator it=graph[s].begin();it!=graph[s].end();it++)
		if(visited[*it]==0)
			dfs(*it);
}

int main()
{
	
	cin >> test;
	while(test--)
	{
		cin >> r >> c >> m >> n;
		memset(table,0,sizeof(table));
		visited.clear();
		visited.resize(r*c,0);
		graph.clear();
		graph.resize(c*r);
		int dxk[] = {n,m, n, m,-n,-m,-n,-m};
		int dyk[] = {m,n,-m,-n,-m,-n, m, n};
		odd = even = 0;
		cin >> water;
		while(water--)
		{
			int i,j;
			cin >> i >> j;
			table[i][j] = 1;
		}
		fore(i,0,r)
			fore(j,0,c)
				fore(d,0,8)
				{
					int nx = i+dxk[d];
					int ny = j+dyk[d];
					if(bound(nx,ny) && table[nx][ny] != 1)
						graph[i*c+j].insert(nx*c+ny);
				}
		dfs(0);
		
		printf("Case %d: %d %d\n",caso++,even,odd);
		//caso++;
		
	}
	
}	
