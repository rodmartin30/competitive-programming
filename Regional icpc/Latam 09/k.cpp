#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
using namespace std;

typedef long long ll;
short course[10005][1005],sum[10005];
short kk[10005];

int main(){
	ios_base::sync_with_stdio(false);
	short n;
	while(cin >> n && n) {
		fore(i,0,n) {
			short k,tmp;
			cin >> k;
			kk[i] = k;
			memset(course[i],0,sizeof course[i]);
			
			fore(j,0,k) {
				cin >> tmp;
				course[i][tmp]++;
			}
	
		}
		
		int res = 1e5,cur,a,b;
		fore(i,0,n)
			sum[i] = 0;
		fore(i,0,1001) {
			cur = 0;
			fore(j,0,n) {
				a = kk[j]-sum[j];
				b = sum[j];
				if(a>b)
					cur += a-b;
				else
					cur += b-a;
				sum[j] += course[j][i];
			}
			res = min(res,cur);
		}
		cout << res << endl;
	}
		
}
		

