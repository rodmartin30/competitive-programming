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
#include <fstream>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
fore(int i=m;i<=n;i++)
#define T 1005
#define ii pair<int,int>
using namespace std;

int n;
vector<vector<ii> > graph;
vector<int> distancia;

void dijkstra(ii s)
{
	
	distancia.clear();distancia.resize(n,INT_MAX);
	int u,d;
	ii front,v;
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	
	distancia[s.second] = 0;
	pq.push(s);
	
	while(!pq.empty())
	{
		front = pq.top(); pq.pop();
		u = front.second;
		d = front.first;
		
		if(d > distancia[u])
			continue;
		fore(i,0,graph[u].size())
		{
			v = graph[u][i];
			if(distancia[u] + v.second < distancia[v.first])
			{
				distancia[v.first] = distancia[u] + v.second;
				pq.push(make_pair(distancia[v.first],v.first));
			}
		}
	}
	
}



int main()
{
	//ofstream cout ("out.txt");
	int test,e,t,r,u,v,d,contador;
	cin >> test;
	while(test--)
	{
		contador = 0;
		cin >> n >> e >> t >> r;
		graph.clear();
		graph.resize(n);
		e--;
		fore(i,0,r)
		{
			cin >> u >> v >> d;
			u--;v--;
			graph[u].push_back(make_pair(v,d));
		}
		fore(i,0,n)
		{
			dijkstra(make_pair(0,i));
			if(distancia[e]<=t)
				contador++;
		}
		cout << contador << endl;
		if(test!=0)
			cout << endl;
			
	}
}	
