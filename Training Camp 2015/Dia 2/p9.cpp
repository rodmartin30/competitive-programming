#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;

vector<vector<int> > graph;
vector<int> num;
int n,ans[105];
bool push = true;

bool dfsCan(int s,int cant) {
  int t = graph[s].size();
  bool res = false;
  if(cant == n) {
    ans[cant-1] = s+1;
    return true;
    
  }
  fore(i,0,t) {
    int v = graph[s][i];
    if(num[v] == 0 && !res) {
      num[v] = 1;
      res |= dfsCan(v,cant+1);
      num[v] = 0;
    }
  }
  if(res) {
    ans[cant-1] = s+1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  int test,t,a,b;
  bool yes = false;
  cin >> test;

  while(test--) {
    cin >> n;

    if(n==1) {
      cout << 1 << endl;
      continue;
    }

    yes = false;
    graph.clear();
    num.clear();
    graph.resize(n);
    num.resize(n,0);
    push = true;

    t = n*(n-1)/2;

    fore(i,0,t) {
      cin >> a >> b;
      a--; b--;
      graph[a].push_back(b);
    }

    for(int i = 0;i<n && !yes;i++) {
      num[i] = 1;
      yes = dfsCan(i,1);
      num[i] = 0;
      if(yes) {
	break;
      }
    }

    if(yes) {
      for(int i = 0;i<n;i++) {
	if(i)
	  cout << " ";
	cout << ans[i];
      }
      cout << endl;
    }
    else
      cout << "Impossible\n";
  }
}


