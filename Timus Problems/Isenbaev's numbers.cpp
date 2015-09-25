#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#define VISITADO true
#define NO_VISITADO false
#define NULO -1
#define INFINITO INT_MAX

using namespace std;

map<string,vector<string> > graph;
map<string,bool> estado;
map<string,int> distancia;

void BFS(string s)
{
	string u,v;
	queue<string> Q;
	distancia[s] = 0;
	estado[s] = VISITADO;
	Q.push(s);
	
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		
		for(int i=0;i<graph[u].size();i++)
		{
			v = graph[u][i];
			if(estado[v] == NO_VISITADO)
			{
				Q.push(v);
				distancia[v] = distancia[u] + 1;
				estado[v] = VISITADO;				
			}
		}
	}
}

int main()
{
	int n;
	string p1,p2,p3;
	cin >> n;	
	
	while(n--)
	{
		cin >> p1 >> p2 >> p3;
		graph[p1].push_back(p2);
		graph[p1].push_back(p3);
		
		graph[p2].push_back(p1);
		graph[p2].push_back(p3);
		
		graph[p3].push_back(p1);
		graph[p3].push_back(p2);
		
		estado[p1] = NO_VISITADO;
		estado[p2] = NO_VISITADO;
		estado[p3] = NO_VISITADO;
		
		distancia[p1] = INFINITO;
		distancia[p2] = INFINITO;
		distancia[p3] = INFINITO;
	}
	
	if(graph.count("Isenbaev"))
	{
		BFS("Isenbaev");
		
		for(map<string,vector<string> >::iterator it=graph.begin();it!=graph.end();++it)
		{
			if(distancia[it->first]==INFINITO)
				cout << it->first << " " << "undefined" << endl;
			else
				cout << it->first << " " << distancia[it->first] << endl;
		}
	}
	else
	{
		for(map<string,vector<string> >::iterator it=graph.begin();it!=graph.end();++it)
			cout << it->first << " " << "undefined" << endl;
	}
}
