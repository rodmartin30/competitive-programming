#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define N 100005
using namespace std;
typedef long long ll;

ll n,k;
int in[N];

ll n2(ll n) {
	if(n == 0 || n == 1)
		return 0;
	return n*(n-1)/2;
}

ll ccant(ll d) {
	ll res = 0,tmp;
	int r,j=1;
	
	fore(i,0,n) {
		j = lower_bound(in,in+n,in[i]-d) - in;
		if(in[i]-in[j] <= d && in[i]-in[j]) {
			res+=i-j;
		}
	}
	return res;

}


int main() {
	ios_base::sync_with_stdio(false);
	while(cin >> n >> k && n && k) {
		fore(i,0,n)
			cin >> in[i];
			
		sort(in,in+n);
		ll mn = 1,mx = in[n-1],mid,f;
		ll cant;
		while(mx-mn > 1) {
			mid = (mn+mx)/2;
			cant = ccant(mid);
			if(k <= cant)
				mx = mid;
			else
				mn = mid;	
		}
		if(ccant(mn)>= k)
			f = mn;
		else
			f = mx;
		
		k = ccant(f) - k;
		for(int i=n-1;i>=0;i--) {
			if(k==0 && binary_search(in,in+n,in[i]-f)) {
				cout << in[i]-f << " " << in[i] << endl;
				break;
			}
			if(binary_search(in,in+n,in[i]-f))
				k--;
		}
	}
}
