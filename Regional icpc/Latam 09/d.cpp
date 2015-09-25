#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

pair<int,char> in[64805];

int main() {
  ios_base::sync_with_stdio(false);
 	int n;
 	while(cin >> n && n) {
 		int e=0,x=0,q=0,qe,qx;
 		fore(i,0,n) {
 			char cc,c;
 			int s = 0;
 			cin >> cc >> c;
 			s+= ((cc-'0')*10+(c-'0'))*3600;
 			cin >> c;
 			cin >> cc >> c;
 			s+= ((cc-'0')*10+(c-'0'))*60;
 			cin >> c;
 			cin >> cc >> c;
 			s+= (cc-'0')*10+(c-'0');
 			cin >> c;
 			in[i] = mp(s,c);
 			if(c == 'E')
 				e++;
 			else if(c == 'X')
 				x++;
 			else
 				q++;
 				
 		}
 		sort(in,in+n);
 		int res = 0,cur=0;
 		qe = n/2-e;
 		fore(i,0,n) {
 		
 			if(in[i].second == '?') {
 				if(qe>0) {
 					in[i].second = 'E';
 					qe--;
 				}
 				else
 					in[i].second = 'X';
 			}
 		}
 		fore(i,0,n) {
 			char c = in[i].second;
 			if(c == 'E') {
 				cur++;
 				e--;
 			}
 			else if(c == 'X') 
 				cur--;
 			res = max(res,cur);
 		}
 		
 		cout << res << endl;
 	}
 	
}


