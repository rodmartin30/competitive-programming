#include <bits/stdc++.h>
#define fore(i,a,n) for(int i = a;i<n;i++)

using namespace std;

int in0[20],in1[20],sec[20],cre[20];
int n,s,k;

int createsec(int init) {
	k = 0;
	fore(i,0,s) {
		fore(j,0,sec[i]) {
			cre[k++] = init;
		}
		init = init ^ 1;
	}
}

int sol(int se[]) {
	int res = 0;
	fore(i,0,n) {
		if(cre[i] != se[i]) {
			fore(j,i+1,n) {
				if(cre[i] == se[j]) {
					while(j>i) {
						swap(se[j],se[j-1]);
						j--;
						res++;
					}
					break;
				}
			}
		}
	}
	return res;

}

int main() {
	ios_base::sync_with_stdio(false);
	int u,c,a,b;
	
	while(cin >> n >> s) {
		u = c = a = b = 0;
		int mn1=1e8,mn0 = 1e8;
		
		fore(i,0,n) {
			cin >> in0[i];
			in1[i] = in0[i];
			if(in0[i])	
				u++;
			else
				c++;
		}
		
		fore(i,0,s) {
			cin >> sec[i];
			if(!(i%2))
				a += sec[i];
			else
				b += sec[i];
		}
		if(a == c && b == u) {
			createsec(0);
			mn0 = sol(in0);
		}
		
		if(a == u && b == c) {
			createsec(1);
			mn1 = sol(in1);
		}
		
		cout << min(mn1,mn0) << endl;
	}

}
