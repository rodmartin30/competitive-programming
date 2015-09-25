#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define N 1000010
#define endl '\n'
#define mk make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


int mapa[505][505],visited[505][505],dist[505][505];
int n,m;

int di[4] = {0,1,0,-1}, dj[4] = {1,0,-1,0};
bool bound(int i,int j) { return (i >= 0 && i < n && j >= 0 && j < m) ? 1 : 0; }

bool bfs(int T) {
	fore(i,0,n) fore(j,0,m) dist[i][j] = 1e9;
	memset(visited,0,sizeof visited);
	dist[0][0] = T;
	visited[0][0] = 1;
	queue<ii> q;
	q.push(mk(0,0));
	ii u,v;
	
	while(!q.empty()) {
		u = q.front(); q.pop();
		fore(k,0,4) {
			v.first = u.first + di[k]; v.second = u.second + dj[k];
			if(bound(v.first,v.second)) {
				if(!visited[v.first][v.second] && dist[u.first][u.second] + 1 < mapa[v.first][v.second]) {
					dist[v.first][v.second] = dist[u.first][u.second] + 1;
					q.push(v);
					visited[v.first][v.second] = 1;				
				}
			}
		}
	}
	return dist[n-1][m-1] != 1e9;
}



int main() {
	ios_base::sync_with_stdio(false);
	int mn,mx,res,mid;
	cin >> n >> m;

	fore(i,0,n)
		fore(j,0,m)
			cin >> mapa[i][j];
	
	
	mn = 0;mx = mapa[0][0]; res = -1;
	
	while(mx-mn > 1) {
		mid = (mx+mn)/2;
		if(bfs(mid)) {
			res = max(res,mid);
			mn = mid;
		}
		else
			mx = mid;
	}
	
	if(bfs(mn))
		res = max(res,mn);
	else if(bfs(mx))
		res = max(res,mx);
	
	cout << res << endl;
}
