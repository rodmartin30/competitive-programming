#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int toInt(string s) {
  istringstream in(s);
  int i;
  in >> i;
  return i;
}
long long exp(int k,int e) {
  long long res = 1;
  fore(i,0,e)
    res*=k;
  return res;
}
string toNegativeBase(string base, string decimal) {
  int tb = base.size(),td = decimal.size(),cur,num = toInt(decimal),b = toInt(base);
  string res="";
  if(decimal == "0")
    return "0";
  while(num) {
    cur = num%b;
    num/=b;
    while(cur<0) {
      cur+=abs(b);
      num++;
    }
    res+=cur+'0';
  }
  reverse(res.begin(),res.end());
  return res;
}
int fromBase(string base,string N) {
  int res=0;
  int b = toInt(base),tn = N.size();
  if(N == "0")
    return 0;
  reverse(N.begin(),N.end());
  fore(i,0,tn) {
    res+=(N[i]-'0')*exp(b,i);
  }
  return res;
}
int main() {
  string s,t,base,ress;
  int n,k,num,cur;
  long long res;
  while(cin >> s && s!="end") {
    cin >> t;
    ress="";
    res =0;
    num = toInt(t);
    k = s.size();
    base = "";
    if(s[0] == 't') {
      fore(i,2,k)
	base+=s[i];
      cout << toNegativeBase(base,t) << endl;
    } else {
      fore(i,4,k)
	base+=s[i];
      cout << fromBase(base,t) << endl;
    }
  }
}
