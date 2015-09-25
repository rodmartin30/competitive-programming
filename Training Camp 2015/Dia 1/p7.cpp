#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;

vector<vector<int> > graph; // Nuestro grafo dirigido
vector<int> num,low,visited; // NUM es el numero en que descubrimos al vertice, LOW guarda el minimo num[] de la SCC (recheable del MST)
stack<int> s;
map<int,int> in,out;
int N,r; // N es el momento enesimo que descubre, R es el numero de SCC
set<int> mylow;

void tarjanSCC(int u) {
  low[u] = num[u] = N++; // num[u] <= low[u]
  s.push(u); 
  visited[u] = 1;
  fore(i,0,graph[u].size()) {
    int v = graph[u][i];
    if(num[v] == 0)
      tarjanSCC(v); // Enviamos a los vecinos de u
    if(visited[v] == 1) {
      low[u] = min(low[u],low[v]); //Como visited es == 1 eso significa que u y v estan en la misma SCC luego calculamos el low[u]
    }
  }
  if(low[u] == num[u]) {  // Nodo "Padre" de la SCC
    r++; 
    while(1) {
      int v = s.top(); s.pop(); visited[v] = 0; // Gracias a esto podemos identificar las distintas SCC
      if(u == v)
	break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int test,a,b,n,m;
  cin >> test;
  while(test--) {
    cin >> n >> m;
    graph.clear();
    graph.resize(n);

    fore(i,0,m) {
      cin >> a >> b;
      a--; b--;
      graph[a].push_back(b);
    }

    num.clear();
    visited.clear();
    low.clear();
    num.resize(n);
    visited.resize(n);
    low.resize(n);

    N = 1;
    r= 0;

    fore(i,0,n) {
      if(num[i] == 0)
	tarjanSCC(i);
    }
    while(!s.empty())
      s.pop();

    in.clear();
    out.clear();
    mylow.clear();

    fore(i,0,n)
      mylow.insert(low[i]);

    for(set<int>::iterator it = mylow.begin();it != mylow.end();it++) {
      fore(i,0,n) {
	if(low[i] == *it) {
	  int t = graph[i].size();
	  fore(k,0,t) {
	    if(*it != low[graph[i][k]]) {
	      in[low[graph[i][k]]]++;
	      out[*it]++;
	    }
	  }
	}
      }
    }
    int ind=0,outd=0;
    for(set<int>::iterator it = mylow.begin();it != mylow.end();it++) {
      if(in[*it] == 0)
	ind++;
      if(out[*it] == 0)
	outd++;
    }
    if(n==1 || r == 1)
      cout << 0 << endl;
    else
      cout << max(ind,outd) << endl;
  }
}

