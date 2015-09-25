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
#define T 1005
#define ii pair<int,int>
using namespace std;



int table[T][T];
int n,m;
bool bound(int x,int y)
{
	if(x>=0 && x<m && y >=0 && y<n)
		return true;
	return false;
}
vector<int> distancia;
vector<vector<ii> > graph;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dijkstra(ii s)
{
	int u,d,my,mx;
	ii front,v;
	distancia[s.second] = s.first;
	priority_queue< ii,vector<ii>,greater<ii> >pq;
	pq.push(s);
	
	while(!pq.empty())
	{
		front = pq.top();
		pq.pop();
		u = front.second;
		d = front.first;
		
		if(d>distancia[u])
			continue;
		fore(i,0,4)
		{
			mx = u%m + dx[i];
			my = u/m + dy[i];
			if(bound(mx,my))
			{
				v = make_pair(my*m+mx,table[my][mx]);
				if(distancia[u] + v.second < distancia[v.first] )
				{
					distancia[v.first] = distancia[u] + v.second;
					pq.push(make_pair(distancia[v.first],v.first));
				}
			}
		}
		
	}
}

int main()
{
	int test,mx,my;
	cin >> test;
	while(test--)
	{
		cin >> n >> m;
		graph.clear(); graph.resize(n*m);
		distancia.clear(); distancia.resize(n*m,INT_MAX);
		fore(i,0,n)
			fore(j,0,m)
				cin >> table[i][j];
		
		
		dijkstra(make_pair(table[0][0],0));
		cout << distancia[n*m-1] << endl;
	}
}	
