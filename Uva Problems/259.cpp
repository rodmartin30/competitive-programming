#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
#define MAX_N 40
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


vector<vector<int> > graph;
int s,t,f,mf,res[MAX_N][MAX_N];
vector<int> p;
void augment(int v, int midEdge) {
	if(v == s) {
		f = midEdge;
	}
	else if(p[v] != -1) {
		augment(p[v],min(midEdge,res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	string ss;
	s = 0; t = 37;
	while(getline(cin,ss) && !ss.empty()) {
		memset(res,0,sizeof res);
		graph.clear();
		graph.resize(40);
		
		int app,users,machine,totalUsers=0;
	 	app = ss[0]-'A'+1;
	 	users = ss[1] - '0';
	 	totalUsers+= users;
	 	fore(i,3,ss.size()-1) {
	 		machine = ss[i] - '0';
	 		graph[app].push_back(machine+27);
	 		graph[machine+27].push_back(app);
	 		res[app][machine+27] = 1e9;
	 		res[0][app] = users;
	 	}
	 	
		while(getline(cin,ss) && !ss.empty()) {
			app = ss[0]-'A'+1;
		 	users = ss[1] - '0';
		 	totalUsers+= users;
		 	
		 	fore(i,3,ss.size()-1) {
		 		machine = ss[i] - '0';
		 		graph[app].push_back(machine+27);
		 		graph[machine+27].push_back(app);
		 		res[0][app] = users;
		 		res[app][machine+27] = 1e9;
		 	}
		}
		fore(i,1,27)
			graph[0].push_back(i);
		fore(i,27,37) {
			graph[i].push_back(37);
			res[i][37] = 1;
		}/*
		fore(i,1,27)
			cout << res[0][i] << endl;
		cout << endl;
		fore(i,1,27) {
			cout << i << " : ";
			fore(j,0,graph[i].size()) {
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		fore(i,27,37)
			cout << res[i][37] << endl;*/
		mf = 0;
		while(1) {
			f = 0;
			int u,v;
			bitset<MAX_N> vis;
			vis.reset();
			vis[s] = 1;
			queue<int> q; q.push(s);
			p.assign(MAX_N,-1);
			while(!q.empty()) {
				u = q.front(); q.pop();
				if(u == t) break;
				for(int j = 0;j<graph[u].size();j++) {
					v = graph[u][j];
					if(res[u][v] > 0 && !vis[v])
						vis[v] = 1, q.push(v),p[v] = u;
				}
			}
	
			augment(t,1e9);
			if(f == 0)
				break;
		
			mf += f;
		}
		if(mf == totalUsers) {
			fore(i,27,37) {
				bool flag = true;
				fore(j,1,27) {
					if(res[i][j] == 1) {
						cout << (char)(j+'A'-1);
						flag = false;
						break;
					}
				}
				if(flag)
					cout << "_";
			}
			cout << endl;
		} else {
			cout << "!" << endl;
		}
		
		
	}
}
		

