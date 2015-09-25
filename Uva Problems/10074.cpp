#include <bits/stdc++.h>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define T 105
#define M 1000000
using namespace std;
int a[T][T];
int main() {
	int n,m,res;
	while(scanf("%d %d",&n,&m) && n != 0 && m !=0)  {
		fore(i,n)
			fore(j,m) {
				scanf("%d",&a[i][j]);
				if(i>0) a[i][j] += a[i-1][j];
				if(j>0) a[i][j] += a[i][j-1];
				if(j>0 && i>0) a[i][j] -= a[i-1][j-1];			
			}
		res = 0;
		fore(i,n)
			for(int j=0;j<m && (n-i)*(m-j)>res;j++)
				for(int k=i;k<n;k++)
					for(int l=j;l<m;l++) {
						int tmp = a[k][l];
						if(i>0) tmp-=a[i-1][l];
						if(j>0) tmp-=a[k][j-1];
						if(j>0 && i>0) tmp+= a[i-1][j-1];
						if(tmp==0) {
							res = max(res,(k-i+1)*(l-j+1));
						}
					
					}
		printf("%d\n",res);
	
	
	}
	
  return 0;
}
