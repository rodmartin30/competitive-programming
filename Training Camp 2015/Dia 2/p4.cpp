#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)

using namespace std;
char a[6][5],b[6][5];
bool m[6][5];
set<string> mys;
string s;
int main() {
  int test,k;
  char c;
  cin >> test;
  
  while(test--) {
    cin >> k;
    
    fore(i,0,6)
      fore(j,0,5)
      cin >> a[i][j];

    fore(i,0,6)
      fore(j,0,5)
      cin >> b[i][j];

    memset(m,false,sizeof m);
    
    fore(j,0,5) {
      fore(i,0,6) {
	c = a[i][j];

	fore(g,0,6) {
	  if(c == b[g][j]) 
	    m[i][j] = true;
	}
      }
    }

    mys.clear();
    fore(i,0,6) {
      if(m[i][0])
	fore(j,0,6) {
	  if(m[j][1])
	    fore(g,0,6) {
	      if(m[g][2])
		fore(h,0,6) {
		  if(m[h][3])
		    fore(l,0,6) {
		      if(m[l][4]) {
			s = "";
			s+= a[i][0]; s += a[j][1]; s += a[g][2]; s+= a[h][3]; s += a[l][4];
			mys.insert(s);
		      }
		    }
		}
	    }
	}
    }


    set<string>::iterator it = mys.begin();
    if(k>(int)mys.size()) 
      cout << "NO\n";
    else {
      int t = mys.size();
      fore(i,1,t+1) {
	if(i==k) {
	  cout << *it << endl;
	  break;
	}
	it++;
      }
    }
    
  }
}
