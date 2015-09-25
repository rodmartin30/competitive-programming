#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

set<int> s;
int p[100005];
ii res[100005];
void criba(int N, int p[]) {
	for(int i=4; i<N; i+=2) p[i] = 2 ;
	
	for (int i=3; i*i < N; i+=2)
		if (!p[i]) 
			for (int j=i*i; j<N;j+=2*i)
				p[j] = i ;

}

int fact (int n, set<int> &s) {
	int F = 0 ;
	while(p[n]) {
		s.insert(p[n]);
		F++;
		n /= p[n] ;
	}
	s.insert(n);
	F++;
	return F ;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	criba(100005,p);
	
	s.clear();
	fore(i,2,100005) {
		res[i].first = res[i-1].first + fact(i,s);
		res[i].second = s.size();
	}
	int test,n;
	
	cin >> test;
	
	while(test--) {
		cin >> n;
		
		cout << res[n].second << " " << res[n].first << endl;
	}
	
}
