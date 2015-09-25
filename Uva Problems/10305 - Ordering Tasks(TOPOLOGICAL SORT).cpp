#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <math.h>
#include <utility>
#include <queue>
#include <set>
#include <string.h>
#include <sstream>
#include <fstream>
#include <stack>

#define T 105
#define VISITADO true
#define NO_VISITADO false

using namespace std;

vector<int> graph[T],ts;
vector<bool> estado;
int indegree[T];
/*
void topoVisit(int u)
{
	int v;
	estado[u] = VISITADO;
	for(int i=0;i<graph[u].size();i++)
	{
		v = graph[u][i];
		if(estado[v] == NO_VISITADO)
			topoVisit(v);
	}
	topologicalSort.push_back(u);
}
*/
int main()
{
	ofstream fout("test.out");
	
	int n,m,a,b;
	cout << (int)'a' << " " << (int)' << endl;
	while(cin >> n >> m && n!=0)
	{
		queue<int> Q;
		for(int i=0;i<T;i++)
		{
			graph[i].clear();
			indegree[i] = 0;
		}
		
		ts.clear();
		estado.clear();
		for(int i=0;i<=n;i++)
			estado.push_back(NO_VISITADO);
			
		while(m--)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			indegree[b]++;
			
		}
		
		for(int i=1;i<=n;i++)
			if(indegree[i]==0)
				Q.push(i);
		
		while(!Q.empty())
		{
			int u = Q.front();
			ts.push_back(u);
			Q.pop();
			
			for(int i=0;i<graph[u].size();i++)
			{
				indegree[graph[u][i]]--;
				if(indegree[graph[u][i]]==0)
					Q.push(graph[u][i]);
			}
			
		}
		/*
		for(int i=1;i<=n;i++)
		{
			if(estado[i] == NO_VISITADO)
				topoVisit(i);
		}
		*/
		for(int i=0;i<ts.size();i++)
		{
			cout << ts[i];
			if(i!=ts.size()-1)
				cout << " ";
		}
		cout << endl;
	}
    
}
