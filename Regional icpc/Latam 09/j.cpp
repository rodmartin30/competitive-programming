#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int m[300];

int main() {
	ios_base::sync_with_stdio(false);
	m['W'] = 64;
	m['H'] = 32;
	m['Q'] = 16;
	m['E'] = 8;
	m['S'] = 4;
	m['T'] = 2;
	m['X'] = 1;
	
	string s;
	while(cin >> s && s != "*") {
		int cant,t = s.size(),res=0;
		
		fore(i,0,t) {
			if(s[i] == '/') {
				if(cant == 64)
					res++;
				cant = 0;
			}
			else
				cant+= m[s[i]];
		}
		cout << res << endl;
	
	}
	
}
