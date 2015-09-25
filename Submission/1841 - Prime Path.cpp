#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <string>
#include <queue>
#include <climits>
#define S 4
#define T 10000
#define VISITADO true
#define NO_VISITADO false
#define INFINITO INT_MAX
#define C 1000

using namespace std;


vector <int> numeros(T,0);
map<string,bool> estado;
map<string,int> distancia;
vector<string> primos;
map<string,vector<string> > graph;
char buf[30];

int toInt(string s)
{
	istringstream in(s);
	int i;
	in >> i;
	return i;
}
void cribaEratostenes()
{
    for(int i = 2;i<sqrt(T);i++)
        for(int j=i+i;j<T;j+=i) 
            numeros[j] = 1;
}

void ponerPrimos()
{
    int t = 0;
    for(int i =C;i<T;i++)
        if(numeros[i]==0)
        {
        	snprintf(buf, 30, "%d", i);
        	string s = buf;
            primos.push_back(s);
            estado[s] = NO_VISITADO;
            distancia[s] = INFINITO;
        }
}
void BFS(string s)
{
	string u,v;
	estado[s] = VISITADO;
	distancia[s] = 0;
	queue<string> Q;
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
				distancia[v] = distancia[u] + 1;
				Q.push(v);
				estado[v] = VISITADO;
			}
		}
	}
}
int main()
{
	int test;
	string n,m,temp;
	
	
    cribaEratostenes();
    cin >> test;
    ponerPrimos();
    for(int i=0;i<primos.size();i++)
   	{
   		for(int j=0;j<primos.size();j++)
   		{	
   			int dif = 0;
   			for(int k=0;k<S;k++)
   				if(primos[i][k] != primos[j][k])
   					dif++;
   			
   			if(dif == 1)
   				graph[primos[i]].push_back(primos[j]);
   		}
   	}
	   	
   	while(test--)
   	{
	   	
   	
   		cin >> n >> m;
   		
   		if(toInt(n)>toInt(m))
		{
			temp = m;
			m = n;
			n = temp;
		}
   		BFS(n);
   		if(distancia[m] != INFINITO)
   			cout << distancia[m] << endl;
   		else
   			cout << "INFINITO" << endl;
   			
   		estado.clear();
	   	distancia.clear();
   	}
   	
   	
    
}

