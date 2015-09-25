#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'

using namespace std;
long long n,in[2005],proc[2005],total;
int memo[2005][25];

int dp(int j,int k) {
  int sum = 0,last,mn= 100000000,cur,plus;
  if(j == n)
    return 0;
  if(k==0) {
    if(j)
      sum = total - proc[j-1];
    else
      sum = total;

    last = sum%10;
    if(last<5)
      return memo[j][k] = sum-last;
    else
      return memo[j][k] = sum-last+10;
  }
  if(memo[j][k] != -1)
    return memo[j][k];
  else {
    fore(i,j,n) {
      sum+=in[i];

      cur = sum%10;
      if(cur<5)
	plus = sum - cur;
      else
	plus = sum-cur+10;

      mn = min(mn,dp(i+1,k-1)+plus);
    }
  }

  return memo[j][k] = mn;
}

int main() {
  int k;
  ios_base::sync_with_stdio(false);
  while(cin >> n >> k) {
    total = 0;
    
    memset(memo,-1,sizeof memo);

    fore(i,0,n) {
      cin >> in[i];
      total += in[i];
      proc[i] = total;
    }
    int cur = total%10,to = total;
    if(cur<5)
      to -= cur;
    else
      to = to-cur+10;

    cout << min(to,dp(0,k)) << endl;

  }

}
