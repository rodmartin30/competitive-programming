#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ii in[1005];
ll m[1005];
ll dist(int i, int j) {

	ll	a = in[j].first - in[i].first, b = in[j].second - in[i].second;
	a*=a; b*=b;
	return a+b;
}

ll n2(ll n) {
	return (n*(n-1))/2;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> n && n) {
  
  	fore(i,0,n)
  		cin >> in[i].first >> in[i].second;
  		
  	ll res = 0;
  	fore(i,0,n) {
  		int k = 0;
  		fore(j,0,n) {
  			if(i != j)
  				m[k++] = dist(i,j);  		
  		}
  		sort(m,m+k);
  		int s,e = 0;
  		while(e < k) {
  			s = e;
  			while(e < k && m[s] == m[e]) e++;
  				res += n2(e-s);
  		}
  	}
  	cout << res << endl;
  
  }
}


