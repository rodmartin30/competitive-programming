#include <bits/stdc++.h>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define T 7500
#define M 1000000
using namespace std;
long long a[6] = {0,1,5,10,25,50};
long long m[8][T];
int main() {
	long long n;
	long long res;
	fore(i,T) m[0][i] = 0;
	m[0][0] = 1;
	for(int i=1;i<6;i++)
		for(int j=0;j<T;j++) {
			if(a[i]<=j)
				m[i][j] = m[i-1][j] + m[i][j-a[i]];
			else
				m[i][j] = m[i-1][j];		
		}
	while(scanf("%lld",&n) != EOF) {
	res=0;
	
	printf("%lld\n",m[5][n]);
	
	}
	
	
  return 0;
}
