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
#include <string>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
fore(int i=m;i<=n;i++)
#define T 105
#define ii pair<int,int>
#define si pair<string,int>
#define is pair<int,string>
#define ss pair<string,string>
#define iii pair<int,pair<int,int> >
#define iii2 pair<pair<int,int>,int>
using namespace std;


vector<int> tiempo;
vector<vector<int> > pisos;
map<ii,vector<iii2> > graph;
int distancia[T][6];
vector<int> zeros;
void dijkstra(iii s)
{
	distancia[s.second.first][s.second.second] = 0;
	iii front;
	iii2 v;
	int d;
	ii u;
	priority_queue< iii,vector<iii>,greater<iii> >pq;
	pq.push(s);
	
	while(!pq.empty())
	{
		front = pq.top();
		pq.pop();
		
		u = front.second;
		d = front.first;
		
		if(d > distancia[u.first][u.second])
			continue;
		fore(i,0,graph[u].size())
		{
			v = graph[u][i];
			if(distancia[u.first][u.second] + v.second < distancia[v.first.first][v.first.second])
			{
				distancia[v.first.first][v.first.second] = distancia[u.first][u.second] + v.second;
				pq.push(make_pair(distancia[v.first.first][v.first.second],v.first));
			}
		}
	}
}

int main()
{
	int n,k,temp,h=0,pos;
	string s;
	
	while(cin >> n >> k)
	{
		graph.clear();
		zeros.clear();
		int r=0,flag=n;
		tiempo.clear(); tiempo.resize(n); pisos.clear();pisos.resize(n);
		fore(i,0,n)
			cin >> tiempo[i];
		getline(cin,s);
		pos = 0;
		while(flag--)
		{
			getline(cin,s);
			
			istringstream iss;
			iss.str(s);	
			int a,b;
			iss >> a;
			if(a==0)
				zeros.push_back(pos);
			fore(i,0,n)
					graph[make_pair(a,i)].push_back(make_pair(make_pair(a,pos),60));
			
			while(iss >> b)
			{
				graph[make_pair(a,pos)].push_back(make_pair(make_pair(b,pos),abs(b-a)*tiempo[pos]));
				graph[make_pair(b,pos)].push_back(make_pair(make_pair(a,pos),abs(b-a)*tiempo[pos]));
				fore(i,0,n)
				graph[make_pair(b,i)].push_back(make_pair(make_pair(b,pos),60));
				a = b;
				
			}
			pos++;
		}
		int miin = INT_MAX;
		
		fore(i,0,zeros.size())
		{
			fore(pi,0,100)
				fore(pj,0,n)
					distancia[pi][pj] = INT_MAX;
			dijkstra(make_pair(0,make_pair(0,zeros[i])));
			
			fore(j,0,n)
				miin = min(miin,distancia[k][j]);
					
		}
		if(miin==INT_MAX)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << miin << endl;
	}
	
		
}	
