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
dxk[] = {n,m, n, m,-n,-m,-n,-m};
dyk[] = {m,n,-m,-n,-m,-n, m, n};
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
		odd = even = 0;
		cin >> water;
		while(water--)
		{
			int i,j;
			cin >> i >> j;
			table[i][j] = -1;
		}
		
		fore(i,0,r)
			fore(j,0,c)
			{
				if(i>=n && j>=m && table[i][j] != -1 && table[i-n][j-m] != -1)
				{
					graph[i*c+j].insert((i-n)*c+j-m);
					//graph[(i-n)*c+j-m].insert(i*c+j);
				}
				
				if(i>=n && j<=c-1-m && table[i][j] != -1 && table[i-n][j+m] != -1)
				{
					graph[i*c+j].insert((i-n)*c+j+m);
					//graph[(i-n)*c+j+m].insert(i*c+j);
				}
				
				if(i<=r-1-n && j>=m && table[i][j] != -1 && table[i+n][j-m] != -1)
				{
					graph[i*c+j].insert((i+n)*c+j-m);
					//graph[(i+n)*c+j-m].insert(i*c+j);
				}
				
				if(i<=r-1-n && j<=c-1-m && table[i][j] != -1 && table[i+n][j+m] != -1)
				{
					graph[i*c+j].insert((i+n)*c+j+m);
					//graph[(i+n)*c+j-m].insert(i*c+j);
				}
				
				if(i>=m && j>=n && table[i][j] != -1 && table[i-m][j-n] != -1)
				{
					graph[i*c+j].insert((i-m)*c+j-n);
					//graph[(i-m)*c+j-n].insert(i*c+j);
				}
				
				if(i>=m && j<=c-1-n && table[i][j] != -1 && table[i-m][j+n] != -1)
				{
					graph[i*c+j].insert((i-m)*c+j+n);
					//graph[(i-m)*c+j+n].insert(i*c+j);
				}
				
				if(i<=r-1-m && j>=n && table[i][j] != -1 && table[i+m][j-n] != -1)
				{
					graph[i*c+j].insert((i+m)*c+j-n);
					//graph[(i+m)*c+j-n].insert(i*c+j);
				}
				
				if(i<=r-1-m && j<=c-1-n && table[i][j] != -1 && table[i+m][j+n] != -1)
				{
					graph[i*c+j].insert((i+m)*c+j+n);
					//graph[(i+m)*c+j-n].insert(i*c+j);
				}
			}
		/*fore(i,0,r*c)
		{
			cout << i << " : ";
			for(set<int>::iterator it=graph[i].begin();it!=graph[i].end();it++)
				cout << *it << " ";
			cout << endl;
		}*/
		dfs(0);
		
		printf("Case %d: %d %d\n",caso++,even,odd);
		//caso++;
		
	}
	
}	
