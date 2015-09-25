#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define VISITADO true
#define NO_VISITADO false
#define INFINITO INT_MAX
#define NULO -1
using namespace std;
int n,a,o,d,u,v,tamano,index,tiempo;
vector<bool> estado;
vector<int> distancia;
vector<int> padre,ds,f;
queue<int> Q;
vector<int> graph[1000];
void init(int N)
{
	for (int i=0; i< N; i++)
	{
		estado.push_back(NO_VISITADO); //Vector
		distancia.push_back(INFINITO); //Vector
		padre.push_back(NULO); // Vector 
		ds.push_back(NULO);		
		f.push_back(NULO);
	}
}

void dfs_visitar(int h,int t)
{
	estado[h] = VISITADO;
	tiempo += 1;
	ds[h] = tiempo;
	tamano = graph[h].size();
	for(int j=0;j<tamano;j++)
	{
		if(estado[j] == NO_VISITADO)
		{
			padre[j] = h;
			dfs_visitar(j,tiempo);
		}
		estado[h] = VISITADO;
		tiempo += 1;
		f[h] = tiempo;
	}
}

void dfs(vector<int> grafo[])
{
	
	tiempo = 0;
	for(int i = 0;i<n;i++)
	{
		if(estado[i] == NO_VISITADO)
		{
			dfs_visitar(i,tiempo);
		}
	}
}

int main()
{
	cin >> n >> a;
	
	for(int i = 0;i<a;i++)
	{
		cin >> o >> d;
		graph[o-1].push_back(d-1);
	}
	init(n);
	dfs(graph);


	for (int i=0; i< n; i++)
	{
		cout << i << ": "<< ds[i] <<  endl;
		

	}
cout << endl;
	for (int i=0; i< n; i++)
	{
		cout << i << ": "<< f[i] << endl;
		

	}
cout << endl;
	for (int i=0; i< n; i++)
	{
		cout << i << ": "<< padre[i]  << endl;
		

	}
	
	cout << endl;
	return 0;
}
