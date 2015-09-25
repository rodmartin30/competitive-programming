#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define VISITADO true
#define NO_VISITADO false
#define INFINITO INT_MAX
#define NULO -1
using namespace std;
int n,a,o,d,u,v,tamano,index;
vector<bool> estado;
vector<int> distancia;
vector<int> padre;
queue<int> Q;

void init(int N)
{
	for (int i=0; i< N; i++)
	{
		estado.push_back(NO_VISITADO);
		distancia.push_back(INFINITO);
		padre.push_back(NULO);
	}
}
int bfs(vector<int> grafo[],int s)
{
	queue<int> Q;
	estado[s] = VISITADO;
    distancia[s] = 0;
    Q.push(s);
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		tamano = grafo[u].size();
		for (int i=0; i < tamano; i++)
		{
			v = grafo[u][i];
			if (estado[v]==NO_VISITADO)
			{
				estado[v] = VISITADO;
				distancia[v] = distancia[u] +1;
				padre[v] = u;
				Q.push(v);
			}
		}

	}

	return 0;
}

int main()
{
	cin >> n >> a;
	vector<int> graph[n];
	for(int i = 0;i<a;i++)
	{
		cin >> o >> d;
		graph[o-1].push_back(d-1);
	}
	init(n);
	for (int i=0; i< n; i++)
	{
		cout << i << ": "<< distancia[i] << endl;
	}
	cout << endl;
	for (int i=1; i< n; i++)
	{
		cout << i <<": ";
		if (padre[i] == NULO)
		{
			cout << "No hay camino" << endl;
		}
		else
		{
			index = i;
			while (padre[index] != NULO)
			{
				cout << index << " -> ";
				index = padre[index];
			}
			cout << 0 << endl;
		}
	}
	cout << endl;
	return 0;
}

