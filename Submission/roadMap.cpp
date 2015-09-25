#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define VISITADO true
#define NO_VISITADO false
#define INFINITO INT_MAX
#define NULO -1

using namespace std;
vector<int> padre,distancia;
vector<bool> estado;
int n,r1,r2,temp;

void init(int N)
{
	padre.resize(N,NULO);
	distancia.resize(N,INFINITO);
	estado.resize(N,NO_VISITADO);
}
void BFS(vector<int> graph[],int s)
{
	int u,v,tamanio;
	queue<int> Q;

	estado[s] = VISITADO;
	distancia[s] = 0;
	padre[s] = NULO;
	Q.push(s);

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		tamanio = graph[u].size();
		for(int i =0;i<tamanio;i++)
		{
			v = graph[u][i];
			if(estado[v]==NO_VISITADO)
			{
				estado[v] = VISITADO;
				padre[v] = u;
				distancia[v] = distancia[u] + 1;
				Q.push(v);
			}

		}

	}
}
int main()
{
	cin >> n >> r1 >> r2;
	vector<int> graph[n];
	for(int i =0;i<n;i++)
	{
		if(i<r1-1)
		{
			cin >> temp;
			graph[i].push_back(temp-1);
			graph[temp-1].push_back(i);
		}
		if(i>r1-1)
		{
			cin >> temp;
			graph[i].push_back(temp-1);
			graph[temp-1].push_back(i);
		}


	}
	init(n);
	BFS(graph,r2-1);
	for(int i=0;i<n;i++)
	{
		if(padre[i]!=NULO) cout << padre[i]+1 << " ";		
	}
	
	cout << endl;

}
























