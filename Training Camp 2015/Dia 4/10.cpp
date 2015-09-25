#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define mp make_pair
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;

class UnionFind { 
	private: vector<int> p, rank; 
	public:
	UnionFind(int N) { 
		rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; 
	}
	
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) { // if from different set
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
			else { p[x] = y;
				if (rank[x] == rank[y]) rank[y]++; 
			}
		} 
	}
};

vector< pair<int, ii> > EdgeList;

int main() {
  ios_base::sync_with_stdio(false);
  int test,caso=0;
  cin >> test;
  while(test--) {
  	int n,m,a,b,w;
  	
  	int sum = 0;
  	cin >> n >> m;
  	
  	EdgeList.clear();
  	EdgeList.resize(m);
  	
  	fore(i,0,m) {
  		cin >> a >> b >> w;
  		a--; b--;
  		sum+=w;
  		EdgeList[i].first = w;
  		EdgeList[i].second.first = a;
  		EdgeList[i].second.second = b;
  	
  	}
  
  	sort(EdgeList.begin(), EdgeList.end());
  	reverse(EdgeList.begin(),EdgeList.end());

		int mst_cost = 0,mx=0;
		UnionFind UF(n);

		for (int i = 0; i < m; i++) { 
			pair<int, ii> front = EdgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)) {
				mst_cost += front.first; 
				UF.unionSet(front.second.first, front.second.second); 
			}
			else
				mx = max(mx,front.first);
		}
		cout << "Case #" << ++caso << ": " <<  sum-mst_cost << " " << mx << endl;
  
  }
}


