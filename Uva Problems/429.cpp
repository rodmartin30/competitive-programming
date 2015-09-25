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
#define T 205
using namespace std;

vector<string> word;
map<string,vector<string> > graph;
map<string,int> visited,distancia;

void bfs(string s)
{
	visited[s] = 1;
	distancia[s] = 0;
	string u,v;
	queue<string> Q;
	Q.push(s);
	
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		
		fore(i,0,graph[u].size())
		{
			v = graph[u][i];
			if(visited[v] ==0)
			{
				distancia[v] = distancia[u] + 1;
				visited[v] = 1;
				Q.push(v);
			}
		}
	}
}

int main()
{
	//ofstream cout ("out.txt");
	int test,i; string s;
	cin >> test;
	while(test--)
	{
		word.clear();
		word.resize(T);
		
		i =0;
		while(cin >> s && s != "*")
		{
			word[i++]=s;
		}
		fore(k,0,i-1)
			fore(j,0,i)
				if(word[k].size() == word[j].size() && j!=k)
				{
					int flag =0;
					fore(h,0,word[k].size())
						if(word[k][h]!= word[j][h])
							flag++;
					if(flag==1)
					{
						graph[word[k]].push_back(word[j]);
						graph[word[j]].push_back(word[k]);
					}
				}
		getline(cin,s);
		while(getline(cin,s))
		{
			if(s=="")
				break;
			string a="",b=""; bool paso = false;
			fore(g,0,s.size())
			{
				if(!paso && s[g] != ' ')
					a+=s[g];
				else if(!paso && s[g] == ' ')
					paso = true;
				else if(s[g] != ' ' && paso)
					b+=s[g];
				
			}
			visited.clear(); distancia.clear();
			bfs(a);
			
			/*for(map<string,vector<string> >::iterator it = graph.begin();it!=graph.end();++it)
			{
				cout << (*it).first << " : ";
				fore(l,0,(*it).second.size())
					cout << (*it).second[l] << " ";
				cout << endl;
			}
			fore(l,0,i)
				cout << distancia[word[l]] << " ";
			cout << endl;*/
			if(a!=b && distancia[b] == 0)
				cout << a << " " << b << " " << -1 << endl;
			else
				cout << a << " " << b << " " << distancia[b] << endl;
		}
		if(test!=0)
			cout << endl;
	}
	
}	
