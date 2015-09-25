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
#define T 500
using namespace std;

char table[T][T];
int tam[T];
vector<vector<int> > graph;
vector<int> visited;
void graphCheck(int s,int color)
{
	visited[s] = color;
	tam[color]++;
	
	fore(i,0,graph[s].size())
		if(visited[graph[s][i]]==0)
			graphCheck(graph[s][i],color);
}
int main()
{
	int test,n,m;
	
	while(cin >> n >> m)
	{
		int cant = 0;
		graph.clear(); visited.clear();
		graph.resize(n*m); visited.resize(n*m,-1);
		fore(i,0,n)
			fore(j,0,m)
				cin >> table[i][j];
		
		char a;
		int ci,cj;
		cin >> ci >> cj;
		a = table[ci][cj];
				
		fore(i,0,n)
			fore(j,0,m)
			{
				if(table[i][j] == a)
					visited[i*m+j] =0;
					
				if(j==0 && table[i][j] == a && table[i][m-1] == a)
				{
					graph[i*m+j].push_back(i*m+m-1);
					graph[i*m+m-1].push_back(i*m+j);
				}
				if(i!=0 && table[i][j] == a && table[i-1][j] == a)
				{
					graph[i*m+j].push_back((i-1)*m+j);
					graph[(i-1)*m+j].push_back(i*m+j);
				}
				
				if(i!=n-1 && table[i][j] == a && table[i+1][j] == a)
				{
					graph[i*m+j].push_back((i+1)*m+j);
					graph[(i+1)*m+j].push_back(i*m+j);
				}
				
				if(j!=0 && table[i][j] == a && table[i][j-1] == a)
				{
					graph[i*m+j].push_back(i*m+j-1);
					graph[i*m+j-1].push_back(i*m+j);
				}
				
				if(j!=m-1 && table[i][j] == a && table[i][j+1] == a)
				{
					graph[i*m+j].push_back(i*m+j+1);
					graph[i*m+j+1].push_back(i*m+j);
				}
				/*
				if(i!=0 && j!=0 && table[i][j] == a && table[i-1][j-1] == a)
				{
					graph[i*m+j].push_back((i-1)*m+j-1);
					graph[(i-1)*m+j-1].push_back(i*m+j);
				}
				
				if(i!=0 && j!=m-1 && table[i][j] == 'l' && table[i-1][j+1] == 'l')
				{
					graph[i*m+j].push_back((i-1)*m+j+1);
					graph[(i-1)*m+j+1].push_back(i*m+j);
				}
				
				if(i!=n-1 && j!=0 && table[i][j] == 'l' && table[i+1][j-1] == 'l')
				{
					graph[i*m+j].push_back((i+1)*m+j-1);
					graph[(i+1)*m+j-1].push_back(i*m+j);
				}
				
				if(i!=n-1 && j!=m-1 && table[i][j] == 'l' && table[i+1][j+1] == 'l')
				{
					graph[i*m+j].push_back((i+1)*m+j+1);
					graph[(i+1)*m+j+1].push_back(i*m+j);
				}*/
					
					
			}
			memset(tam,0,sizeof(tam));
			int color = 1,maxx=0;
			fore(i,0,m*n)
				if(visited[i]==0)
				{
					graphCheck(i,color++);
					cant++;
				}
			tam[visited[ci*m+cj]] = 0;
			fore(i,0,color+5)
				maxx = max(maxx,tam[i]);
				
			cout << maxx << endl;
	}
	
}	
