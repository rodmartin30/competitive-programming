#include <bits/stdc++.h>

using namespace std;
#define T 160
#define fore(i,n) for(int i = 0;i<n;i++)

int a[T][T],res,n,q;

int main() {
	int test;
	cin >> test;
	while(test--) {
		scanf("%d",&n);
		int q = n*2;
		res = INT_MIN;
		fore(i,n)
			fore(j,n) {
					scanf("%d",&a[i][j]);
						a[n+i][j] = a[i][j];
						a[i][n+j] = a[i][j];
						a[i+n][n+j] = a[i][j];
			}
		fore(i,q)
			fore(j,q) {
				if(i>0) a[i][j] += a[i-1][j];
				if(j>0) a[i][j] += a[i][j-1];
				if(i>0 && j>0) a[i][j] -= a[i-1][j-1];
			}
		/*fore(i,n)
		{ fore(j,n)
			cout << a[i][j] << " ";
		cout << endl; }s*/
		fore(i,n)
			fore(j,n)
				for(int k=i;k<n+i;k++)
					for(int l=j;l<j+n;l++) {
						int cur = a[k][l];
						if(i>0) cur -= a[i-1][l];
						if(j>0) cur -=a[k][j-1];
						if(i>0 && j>0) cur += a[i-1][j-1];
						res = max(cur,res);
					}
		
		printf("%d\n",res);	
		
	}

}
