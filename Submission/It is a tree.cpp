#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>

using namespace std;
vector<vector<int> > graph;
vector<int> estado,padre;
bool arbol = true;
void graphCheck(int u)
{
	estado[u] = 2;
	int v;
	for(int i=0;i<graph[u].size();i++)
	{
		v = graph[u][i];
		if(estado[v] == 0)
		{
			padre[v] = u;
			graphCheck(v);
		}
		else if(estado[v] == 2)
		{
			if(v != padre[u])
				arbol = false;
		}
	}
	estado[u] = 1;
}
int main()
{
	int n,m,a,b;
	cin >> n >> m;
	graph.resize(n+1);
	int comp = 0;
	for(int i=0;i<=n;i++)
	{
		estado.push_back(0);
		padre.push_back(-1);
	}	
	
	while(m--)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++)
		if(estado[i]==0)
		{
			graphCheck(i);
			comp++;
		}
			
	if(arbol && comp <=1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
