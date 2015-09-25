#include <bits/stdc++.h>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define T 105
#define M 10005
#define push_back pb

using namespace std;
pair<int,int> pos[15];
int graph[15][15],b,dp[12][5000];
int tsp(int pos,int mask) {
	if(mask == (1 << b)-1) {
		return graph[pos][0];
	}
	if(dp[pos][mask] != -1)
		return dp[pos][mask];
	int res = INT_MAX;
	fore(i,b) {
		if(!(mask & (1 << i))) {
			res = min(res,graph[i][pos] + tsp(i,mask | (1<<i)));
		}
	}
	dp[pos][mask] = res;
	return res;
}



int main() {
	int test,n,m,beapers,x0,y0,tmp1,tmp2;
	
	scanf("%d",&test);
	while(test--) {
		scanf("%d %d",&n,&m);
		scanf("%d %d",&x0,&y0);
		memset(dp,-1,sizeof dp);
		scanf("%d",&beapers);
		
		pos[0] = make_pair(x0,y0);
		fore(i,beapers) {
			scanf("%d %d",&tmp1,&tmp2);
			pos[i+1] = make_pair(tmp1,tmp2);
		}
		b = beapers+1;
		fori(i,beapers) {
			for(int j = i+1;j<=beapers;j++) {
				graph[i][j] = abs(pos[i].first-pos[j].first) + abs(pos[i].second - pos[j].second);
				graph[j][i] = graph[i][j];
			}
		}
		
		printf("The shortest path has length %d\n",tsp(0,1));
		
		
	}
  return 0;
}
