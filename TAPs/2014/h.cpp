#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define N 500005
#define EPS 1e-9
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

set<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	int test,n,tmp;
	cin >> test;
	
	while(test--) {
		cin >> n;
		s.clear();
		set<int>::iterator it;
		fore(i,0,n) {
			cin >> tmp;
			tmp = -tmp;
			if(s.empty()) {
				s.insert(tmp);
			}
			else {
				it = s.lower_bound(tmp);
				if(it == s.end())  {
					s.insert(tmp);
				}
				else{
					s.erase(it);
					s.insert(tmp);
				}
			}
		
		}
		cout << s.size() << endl;
		
	
	
	}
}
