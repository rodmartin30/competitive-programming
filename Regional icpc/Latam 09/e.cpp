#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

long long toM(long long x){
	long long r;
	if(x<=100)r=2*x;
	else if(x<=10000)r=200+(x-100)*3;
	else if(x<=1000000)r=29900+(x-10000)*5;
	else r=4979900+(x-1000000)*7;
	return r;
}
long long toW(long long x){
	long long r;
	if(x<=200)r=x/2;
	else if(x<=29900)r=(x-200)/3+100;
	else if(x<=4979900)r=(x-29900)/5+10000;
	else r=(x-4979900)/7+1000000;
	return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  ll a,b;
  while(cin >> a >> b && a && b) {
  	ll total = toW(a);
  	ll mn = 0,mx = total/2,he;
  	bool flag = true;
  	while(mx-mn > 1) {
  		ll mid = (mx+mn)/2;
  		he = total-mid;
  		he = toM(he);
  		if(abs(he - toM(mid)) > b)
  			mn = mid;
  		else if(abs(he - toM(mid)) < b)
  			mx = mid;
  		else {
  			cout << toM(mid) << endl;
  			flag = false;
  			break;
  		}
  			
  	}
  	if(toM(total - mn-mn) && flag == b)
  		cout << toM(mn) << endl;
  	else if(flag)
  		cout << toM(mx) << endl;
  
  }
}


