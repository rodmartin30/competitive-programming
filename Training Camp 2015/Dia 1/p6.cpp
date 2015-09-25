#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int u[1000005],d[1000005],k;
int f(int y,int i) {
  return u[i]*y-(d[i]*(k-y));
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  while(cin >> k >> n) {
    int mn = INT_MAX;
    fore(i,0,n) {
      cin >> u[i] >> d[i];
    }
    fore(i,0,n) {
      int a=0,b=k;
      while(b-a>1) {
	int mid = (a+b)/2;
	if(f(mid,i)>0) {
	  b = mid;
	} else {
	  a= mid;
	}
      }
      if(f(a,i)>0) {
	mn = min(mn,f(a,i));
      } else 
	mn =min(mn,f(b,i));
      
    }
    cout << mn << endl;
  }
}
