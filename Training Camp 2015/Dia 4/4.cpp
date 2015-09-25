#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector<pair<int,ii> > edgelist,mst;

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

int main() {
	ios_base::sync_with_stdio(false);
	int n,m,a,b,w;
	
	while(cin >> n >> m) {
		edgelist.clear();
		mst.clear();
		edgelist.resize(m);	
		fore(i,0,m) {
			cin >> a >> b >> w;
			a--; b--;
			
			edgelist[i] = make_pair(w,ii(a,b));
		}
	
		sort(edgelist.begin(), edgelist.end()); 

		int mst_cost1 = 0,mst_cost2 = 0,mstcons = 0,t,cant = 0;
		UnionFind UF(n);

		for (int i = 0; i < m; i++) { 
			pair<int, ii> front = edgelist[i];
			if (!UF.isSameSet(front.second.first, front.second.second)) { 
				mst_cost1 += front.first; 
				UF.unionSet(front.second.first, front.second.second); 
				mst.push_back(front);
			} 
		}
		
		t = mst.size();
		fore(i,0,t) {
			pair<int, ii> q = mst[i];
			mst_cost2 = 0;
			UnionFind UF(n);
			for (int i = 0; i < m; i++) { 
				pair<int, ii> front = edgelist[i];
				if (!UF.isSameSet(front.second.first, front.second.second) && front != q) { 
					mst_cost2 += front.first; 
					UF.unionSet(front.second.first, front.second.second); 
				}
			
			}
			if(mst_cost2 != mst_cost1) {
				cant++;
				mstcons += q.first;
			}
			
		}
	
		cout << cant << " " << mstcons << endl;
	
	}
	
}
