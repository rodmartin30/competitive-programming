#include <bits/stdc++.h>
#define T 205
#define fore(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,q,d,m;
int memo[T][25][25],a[T];
int mochila(int i, int w, int sum) {
	if(w==0) {
		if(!(sum%d))
			return 1;
		else 
			return 0;
	}
	if(i==n)
		return 0;
	else if(memo[i][w][sum] != -1) {
		return memo[i][w][sum];
	} 
	else {
		memo[i][w][sum] = mochila(i+1,w-1,(((sum+a[i])%d)+d)%d) + mochila(i+1,w,sum);
	}
	return memo[i][w][sum];
}


int main() {
	int set = 0;
	while(scanf("%d %d",&n,&q) && n != 0 && q!=0) {
		int caso = 0;
		fore(i,n) {
			scanf("%d",&a[i]);
		}
		
		printf("SET %d:\n",++set);
		fore(i,q) {
			scanf("%d %d",&d,&m);
			memset(memo,-1,sizeof memo);
			printf("QUERY %d: %d\n",++caso,mochila(1,m-1,((a[0]%d)+d)%d) + mochila(1,m,0));
		}
	}


}
