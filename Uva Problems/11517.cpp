#include <bits/stdc++.h>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define all(v) v.begin(),v.end()
#define FIN -4611256527403020609
#define T 10005
using namespace std;
#define inf 10000000
int a[T][T],d[T];
int main() {
  int test,n,p,tmp;
  scanf("%d",&test);
  while(test--) {
  	scanf("%d",&p);
  	scanf("%d",&n);
  	fore(i,n) {
  		scanf("%d",&d[i+1]);
  	}
  	fore(i,T) { 
  		a[0][i] = inf;
  		a[i][0] = 0;
  	}
  	sort(d+1,d+n+1);
  	for(int i=1;i<=n;i++) {
  		for(int j=1;j<T;j++) {
					if(d[i]<=j) {
						a[i][j] = min(a[i-1][j],a[i-1][j-d[i]]+1);
					}
					else a[i][j] = a[i-1][j];
  			
  		}
  	}
  	for(int j=p;j<T;j++) {
  		if(a[n][j] != inf) {
  			printf("%d %d\n",j,a[n][j]);
  			break;
  		}
  	}
  }
}
