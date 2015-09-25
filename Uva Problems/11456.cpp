#include <bits/stdc++.h>

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define T 2005
#define M 1000000

using namespace std;
int a[T],n,L[T];
int Lis(int k) {
	int lis = 1,pos,s;
	fore(i,n) L[i] = INT_MAX;
	L[0] = a[k-1];
	for(int i=k;i<n;i++) {
			int l=-1,r=lis;
			while(r-l>1) {
				s = (l+r)/2;
				if(L[s] < a[i]) {
					l = s;
				} else
					r = s;
			}
			if(r!=0) {
				L[r] = a[i];
				if(r+1>lis)
					lis++;
			}
	}
	return lis;
	

}
int Lds(int k) {
	int lis = 1,s;
	fore(i,n) L[i] = INT_MIN;
	L[0] = a[k-1];
	for(int i=k;i<n;i++) {
			int l=-1,r=lis;
			while(r-l>1) {
				s = (l+r)/2;
				if(L[s] > a[i]) {
					l = s;
				} else
					r = s;
			}
			if(r!=0) {
				L[r] = a[i];
				if(r+1>lis)
					lis++;
			}
	}
	return lis;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		scanf("%d",&n);
		fore(i,n) {
			scanf("%d",&a[i]);
		}
		
		int res = 0;
		if(n)
			fore(i,n) {
				res = max(res,Lis(i+1) + Lds(i+1)-1);
			}
		cout << res << endl;
		
	
	}


	
  return 0;
}
