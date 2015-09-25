#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define MAX 500005
using namespace std;

int in[MAX],pos[MAX];
char res[MAX];
int main() {
  ios_base::sync_with_stdio(false);
  int test,n,ant;
  char c;
  cin >> test;
  while(test--) {
    cin >> n;

    fore(i,0,n) {
      cin >> in[i];
      in[i]--;
      pos[in[i]] = i;
    }
   
    c = 'a';
    ant = in[0];
    res[ant] = c;
    
    fore(i,1,n) {
      int pri = ant+1,seg = in[i]+1;
      if(c>'z')
	break;
      if(pri != n && seg!= n) {
	if(pos[pri]  > pos[seg]) {
	  res[in[i]] = ++c;
	} 
	else
	  res[in[i]] = c;
      }
      else if(pri == n) {
	res[in[i]] = c;
      }
      else if(seg == n) {
	res[in[i]] = ++c;
      }

      ant = in[i];
    }
    if(c<='z') {
      fore(i,0,n)
	cout << res[i];
      cout << endl;
    }
    else
      cout << -1 << endl;
  }
}

