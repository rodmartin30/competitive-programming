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
#include <bitset>
#define fore(i,m,n) \
for(int i=m;i<n;i++)

using namespace std;

vector<string> input;
vector<int> topo;
bitset<30> my,visited;
map<int,vector<int> > graph;

void dfs(int c)
{
	visited.set(c);
	
	for(int i=0;i<graph[c].size();i++)
	{
		int v = graph[c][i];
		if(!visited[v])
			dfs(v);
	}
	
	topo.push_back(c);
}

int main()
{
	
	string s;
	
	while(cin >> s)
	{
		
		if(s!="#")
			input.push_back(s);
	
		else
		{
			fore(i,0,input.size()-1)
			{
				int t = min(input[i].size(),input[i+1].size());
				fore(j,0,t)
				{
					char a=input[i][j]-'A',b = input[i+1][j]-'A';
			
					if(a!=b)
					{
						my.set(a);
						my.set(b);
						graph[a].push_back(b);
				
						break;
					}
				}
			}
			
			for(int i=0;i<26;i++)
				if(!visited[i] && my[i])
					dfs(i);
			
			for(int i=topo.size()-1;i>=0;i--)
				printf("%c", topo[i] + 'A');
	
			cout << endl;
			visited.reset();
			my.reset();
			input.clear();
			graph.clear();
			topo.clear();
		}
		
	}
}
