#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#define NULO -1
#define INFINITO INT_MAX
#define VISITADO true
#define NO_VISITADO false

using namespace std;

vector<set<int> > graph;
vector<int> distanciaM,distanciaC1,distanciaC2;
vector<bool> estadoM,estadoC1,estadoC2;

void BFS(vector<bool>& estado,vector<int>& distancia,int s)
{
	int u,v;
	queue<int> Q;
	distancia[s] =0;
	estado[s] = VISITADO;
	Q.push(s);
	
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for(set<int>:: iterator it=graph[u].begin();it != graph[u].end();++it)
		{
			if(estado[*it] == NO_VISITADO)
			{
				v = *it;
				distancia[v] = distancia[u] + 1;
				estado[v] = VISITADO;
				Q.push(v);
			}
		}
	}
}

int main()
{
	
	int n,m,test,m1,m2,c1,c2,k1,k2;
	bool yes;
	cin >> n >> m >> test;
	
	graph.resize(n*m);
	
	for(int i=0;i<n;i++)
		for(int j =0;j<m;j++)
		{
			if(i!=0)
				graph[i*m+j].insert((i-1)*m+j);
			if(i!=n-1)
				graph[i*m+j].insert((i+1)*m+j);
			if(j!=0)
				graph[i*m+j].insert(i*m+j-1);
			if(j!=m-1)
				graph[i*m+j].insert(i*m+j+1);
				
		}
		
	while(test--)
	{
		distanciaM.clear(); distanciaC1.clear(); distanciaC2.clear();
		estadoM.clear(); estadoC1.clear(); estadoC2.clear();
		distanciaM.resize(m*n,INFINITO); distanciaC1.resize(m*n,INFINITO); distanciaC2.resize(m*n,INFINITO);
		estadoM.resize(m*n,NO_VISITADO); estadoC1.resize(m*n,NO_VISITADO); estadoC2.resize(m*n,NO_VISITADO);
		yes = false;
		
		cin >> m1 >> m2 >> c1 >> c2 >> k1 >> k2;
		m1--; m2--; c1--;c2--; k1--;k2--;
		
		BFS(estadoM,distanciaM,(m1*m+m2));
		BFS(estadoC1,distanciaC1,(c1*m+c2));
		BFS(estadoC2,distanciaC2,(k1*m+k2));
		
		for(int i=0;i<n;i++)
		{
			if(distanciaM[i*m] < distanciaC1[i*m] && distanciaM[i*m] < distanciaC2[i*m])
				yes = true;
			if(distanciaM[i*m+m-1] < distanciaC1[i*m+m-1] && distanciaM[i*m+m-1] < distanciaC2[i*m+m-1])
				yes = true;		
		}
		
		for(int j=0;j<m;j++)
		{
			if(distanciaM[j] < distanciaC1[j] && distanciaM[j] < distanciaC2[j])
				yes = true;
			if(distanciaM[(n-1)*m+j] < distanciaC1[(n-1)*m+j] && distanciaM[(n-1)*m+j] < distanciaC2[(n-1)*m+j])
				yes = true;			
		}
		if(yes)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
		/*
	for(int i=0;i<n*m;i++)
	{
		cout << i << ": ";
		for(set<int>::iterator it = graph[i].begin();it!=graph[i].end();++it)
			cout << *it << " ";
		cout << endl;
	}*/
	
}
