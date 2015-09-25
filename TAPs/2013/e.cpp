#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define MAX_N 100010
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;



bool mem[300005];
int main() {
	ios_base::sync_with_stdio(false);
	
	
	int test,ans,result;
	string s;
	cin >> test;
	while(test--) {
		cin >> s;
		ans = 0;
		memset(mem,false, sizeof mem);
		mem[0] = 1;
		mem[1] = 1;
		int t = s.size();
		fore(j,0,t) {
			int v = 2;
			fore(k,0,16) {
				if(j+k>=t)
					break;
				v |= (s[j+k]-'0');
				mem[v] = 1;
				v = v << 1;
			}
		}
	
		while(mem[ans]) {
			ans++;
		}
		for(int i = 30;i>=0;i--)
			if(ans & 1 << i) {
				result = i;
				break;
			}
		cout << result << endl;
	}
}
