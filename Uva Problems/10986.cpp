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
#define T 100005
#define ii pair<int,int>
using namespace std;

pair<int,int> par;
vector<vector<pair<int,int> > > graph;
vector<int> distancia,visited;

void dijkstra(pair<int,int> s)
{
	pair<int,int> front,v;
	int u,d;
	distancia[s.second] = 0;
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	pq.push(s);
	while(!pq.empty())
	{
		front = pq.top();
		pq.pop();
		d = front.first;
		u = front.second;
		if(d>distancia[u])
			continue;
		fore(i,0,graph[u].size())
		{
			v = graph[u][i];
			if(distancia[u]+v.second < distancia[v.first]){
				distancia[v.first] = distancia[u] + v.second;
				pq.push(make_pair(distancia[v.first],v.first));
				
			}
		}
	}
}
int main()
{
	int test,n,m,s,t,u,v,d,caso=1,dis;
	cin >> test;
	while(test--)
	{
		cin >> n >> m >> s >> t;
		distancia.clear(); distancia.resize(T,INT_MAX);
		graph.clear(); graph.resize(n);
		while(m--)
		{
			cin >> u >> v >> d;
			graph[u].push_back(make_pair(v,d));
			graph[v].push_back(make_pair(u,d));
		}
		dijkstra(make_pair(0,s));
		if(distancia[t]== INT_MAX)
			printf("Case #%d: unreachable\n",caso++);
		else
			printf("Case #%d: %d\n",caso++,distancia[t]);
	}
	
}	
