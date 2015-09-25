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
#include <fstream>
#include <sstream>
#include <stack>
#define VISITADO true
#define NO_VISITADO false
#define NULO -1
#define INFINITO INT_MAX
#define T 35
using namespace std;

vector<int> graph[T];
map<string,int> nodo;
map<int,string> vnodo;
vector<int> distancia,padre;
vector<bool> estado;
set<string> myset;
int toInt(string s)
{
    istringstream in(s);
    int i;
    in >> i;
    return i;
}
void init(int N)
{
    estado.clear();
    distancia.clear();
    padre.clear();
    for(int i =0;i<N;i++)
    {
        estado.push_back(NO_VISITADO);
        padre.push_back(NULO);
        distancia.push_back(INFINITO);
    }
}

void BFS(int s)
{
    int u,v,cantVefinos,nodos;
    
    queue<int> Q;
    Q.push(s);
    distancia[s] = 0;
    padre[s] = NULO;
    estado[s] = VISITADO;
    
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        cantVefinos = graph[u].size();
        
        for(int i =0;i<cantVefinos;i++)
        {
            v = graph[u][i];
            if(estado[v] == NO_VISITADO)
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
    ifstream fin ("test.in");
    ofstream fout ("test.out");
    
    int n,contador=0,test=0,cant,v1,v2,nodos;
    string s1,s2;
    bool primero = true;
    while(cin >> n && n != 0)
    {
        primero = true;
        for(int i=0;i<T;i++)
            graph[i].clear();
            
        contador = 0;
        nodo.clear();
        vnodo.clear();
        myset.clear();
        
        while(n--)
        {
            cin >> s1 >> s2;
            
            myset.insert(s1);
            myset.insert(s2);
            if(primero)
            {
                v1 = contador++;
                nodo[s1] = v1;
                vnodo[v1] = s1;
                primero = false;
            }
            else
            {
                if(nodo[s1] == 0 && vnodo[0] != s1)
                {
                    v1 = contador++;
                    nodo[s1] = v1;
                    vnodo[v1] = s1;
                }  
            } 
            if(nodo[s2] == 0 && vnodo[0] != s2)
            {
                v2 = contador++;
                nodo[s2] = v2;
                vnodo[v2] = s2;
            }
            
            graph[nodo[s1]].push_back(nodo[s2]);
            graph[nodo[s2]].push_back(nodo[s1]);
        }
        nodos = myset.size();
        /*for(set<string>::iterator it=myset.begin();it!=myset.end();++it)
        {
            cout << *it << " " << endl;
        }
        for(int i=0;i<nodos;i++)
        {
            cout<< vnodo[i] << " : ";
            for(int j=0;j<graph[i].size();j++)
            {
                cout<< vnodo[graph[i][j]] << " ";
            }
            cout<< endl;
        }*/
        while(cin >> s1 >> s2 && s1 != "0")
        {
            if(myset.find(s1)!=myset.end())
            {
            
                init(nodos);
                BFS(nodo[s1]);
                cant = 0;
                test++;
                for(int i=0;i<distancia.size();i++)
                {
                    if(distancia[i]>toInt(s2))
                        cant++;
                }
                cout<< "Case " << test << ": " << cant << " nodes not reachable from node " << toInt(vnodo[nodo[s1]]) << " with TTL = " << s2 << "." << endl;  
                //printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",test,cant,toInt(vnodo[nodo[s1]]),toInt(s2));
                
            }
            else
            {
                test++;
                int d;
                if(s2 == "0") d = 0;
                else d = 1;
                cout<< "Case " << test << ": " << d << " nodes not reachable from node " << s1 << " with TTL = " << s2 << "." << endl;
                
            }
        }
    }
    
}
