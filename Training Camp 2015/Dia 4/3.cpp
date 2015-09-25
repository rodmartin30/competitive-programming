#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;

ii res[505];

bool compare(ii i, ii j) {
	if(i.first == j.first)
		return i.second > j.second;
	return i.first > j.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n,m,k,a,b;
  
  while(cin >> n >> m) {
  	
  	k = 0;
  	fore(i,0,m) {
  		cin >> b >> a;
  		if(a > b) {
  			res[k].first = a;
  			res[k++].second = b;
  		}
  	}
  		
  	sort(res,res+k,compare);
  	int sol = 0,mn,g;
  	
  	fore(i,0,k) {
  		g = i;
  		mn = res[i].second;
  		fore(j,i+1,k) {
  			if(mn <= res[j].first) {
  				mn = min(res[j].second,mn);
  				if(j == k-1)
  					i = j;
  			}
  			else {
  				i = j-1;
  				break;
  			}
  		}
  		sol+= (res[g].first - mn) << 1;
  	}
  	sol+=n+1;
 		cout << sol << endl; 
  
  }
}
