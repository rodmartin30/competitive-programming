#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#define T 8
#define VISITADO true
#define NO_VISITADO false
#define NULO -1
#define INFINITO INT_MAX

using namespace std;

int n,m,k;
vector<int> padre,distancia;
vector<bool> estado;
vector<set<int> > graph;

void BFS(int s)
{
	int u,v;
	queue<int> Q;
	Q.push(s);
	estado[s] = VISITADO;
	distancia[s] = 0;
	padre[s] = NULO;
	
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		
		for(set<int>:: iterator it=graph[u].begin();it != graph[u].end();++it)
		{
			v = *it;
			if(estado[v] == NO_VISITADO)
			{
				distancia[v] = distancia[u] + 1;
				padre[v] = u;
				Q.push(v);
				estado[v] = VISITADO;
			}
		}
	}
}
int toNodo(string s)
{
	int i,j;
	switch(s[0])
	{
		case 'a': j = 0;break;
		case 'b': j = 1;break;
		case 'c': j = 2;break;
		case 'd': j = 3;break;
		case 'e': j = 4;break;
		case 'f': j = 5;break;
		case 'g': j = 6;break;
		case 'h': j = 7;break;
	}
	
	switch(s[1])
	{
		case '8': i = 0;break;
		case '7': i = 1;break;
		case '6': i = 2;break;
		case '5': i = 3;break;
		case '4': i = 4;break;
		case '3': i = 5;break;
		case '2': i = 6;break;
		case '1': i = 7;break;
	}
	return i*T+j;
}
int main()
{
    string rey,comerciante;
    
    cin >> rey >> comerciante;
    
    padre.clear(); estado.clear(); distancia.clear(); graph.clear();
    
    graph.resize(T*T); estado.resize(T*T,NO_VISITADO); distancia.resize(T*T,INFINITO); padre.resize(T*T,NULO);
    
    for(int i=0;i<T;i++)
    	for(int j=0;j<T;j++)
    	{
    		if(i!=0)
    			graph[i*T+j].insert((i-1)*T+j);
    			
    		if(i!=T-1)
    			graph[i*T+j].insert((i+1)*T+j);
    			
    		if(j!=0)
    			graph[i*T+j].insert(i*T+j-1);
    		
    		if(j!=T-1)
    			graph[i*T+j].insert(i*T+j+1);
    		
    		if(i!=0 && j!=0)
    			graph[i*T+j].insert((i-1)*T+j-1);
    			
    		if(i!=0 && j!=T-1)
    			graph[i*T+j].insert((i-1)*T+j+1);
    			
    		if(i!=T-1 && j!=0)
    			graph[i*T+j].insert((i+1)*T+j-1);
    			
    		if(i!=T-1 && j!=T-1)
    			graph[i*T+j].insert((i+1)*T+j+1);			
    		
    		
    	}
    	
    /*for(int i=0;i<T*T;i++)
    {
    	cout << i << " : ";
    	for(set<int>:: iterator it=graph[i].begin();it != graph[i].end();++it )
    		cout << *it << " ";
    	cout << endl;
    }*/
    //cout << toNodo(comerciante) << " " << toNodo(rey) << endl;
    BFS(toNodo(comerciante));
    cout << distancia[toNodo(rey)] << endl;
    int k =toNodo(rey);
    while(k!=toNodo(comerciante))
    {
    	if(padre[k] - T == k)
    		cout << "D";
    		
    	if(padre[k] + T == k)
    		cout << "U";
    		
    	if(padre[k] - (T+1) == k)
    		cout << "RD";
    		
    	if(padre[k] - (T-1) == k)
    		cout << "LD";
    		
    	if(padre[k] - 1 == k)
    		cout << "R";
    	
    	if(padre[k] +1==k)
    		cout << "L";
    		
    	if(padre[k] + (T+1) == k)
    		cout << "LU";
    		
    	if(padre[k] + (T-1) == k)
    		cout << "RU";
    	
    		
    		
    		
    	k = padre[k]; 
    	cout << endl;
    }
}
