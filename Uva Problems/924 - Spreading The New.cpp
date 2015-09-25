#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <queue>
#define T 2505
#define fore(i,m,n) \
for(int i = m;i<n;i++)

using namespace std;
vector<vector<int> > graph;
int maxD,maxE;
vector<int> boom;
vector<int> distancia;
vector<int> visited;
void BFS(int s)
{
	distancia[s] = 0;
	visited[s] = 1;
	queue<int> Q;
	int u,v;
	Q.push(s);
	
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		int t = graph[u].size();
		fore(i,0,t)
		{
			v = graph[u][i];
			
			if(visited[v] == 0)
			{
				distancia[v] = distancia[u] +1;
				
				boom[distancia[v]]++;
				visited[v] = 1;
				Q.push(v);
			}
		}
		if(boom[distancia[u]]<boom[distancia[u]+1])
			maxD = distancia[u] +1;
	}
}

int main(){
	int n,e,temp;
	cin >> n;
	graph.resize(n);
	fore(i,0,n)
	{
		cin >> e;
		while(e--)
		{
			cin >> temp;
			graph[i].push_back(temp);
		}
	}
	
	int test,source;
	cin >> test;
	
	while(test--)
	{
		visited.clear(); visited.resize(n,0);
		distancia.clear(); distancia.resize(n,INT_MAX);
		boom.clear(); boom.resize(n,0);
		maxD = 0;
		cin >> source;
		BFS(source);
		sort(boom.begin(),boom.end());
		if(graph[source].size()>0)
			cout << boom[n-1] << " " << maxD << endl;
		else
			cout << 0 << endl;
	}
	
}
