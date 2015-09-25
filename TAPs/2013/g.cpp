#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int a[100005];
multiset<int> b;
int main() {
  ios_base::sync_with_stdio(false);
  int n,res=0,tmp;
  cin >> n;

  fore(i,0,n)
    cin >> a[i];
  fore(i,0,n) {
    cin >> tmp;
    b.insert(tmp);
  }

  sort(a,a+n);

  int i=0,j=0;
  set<int>::iterator it;
  while(i < n) {
    it = b.upper_bound(a[i]);
    if(it != b.end()) {
      b.erase(it);
      res++;
    }
    i++;
    
  }
  cout << res << endl;

}

