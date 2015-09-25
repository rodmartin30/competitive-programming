#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <utility>
#include <map>
#include <sstream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
for(int i=m;i<=n;i++)
#define T 1000005
#define M 500
using namespace std;

int pos[M][T];
string s,e;
int main()
{
	cin >> s;
	bool flag;
	int t=s.size(),te,tmp,q,a,b,h;
	fore(i,0,M)
		pos[i][0] = 1;
	fore(i,0,t)
		pos[s[i]][pos[s[i]][0]++] = i;
		
	cin >> q;
	fore(i,0,q)
	{
		cin >> e;
		te = e.size();
		flag=true;
		tmp=1;
		h=0;
		fore(i,0,te)
		{
			tmp = (int)(lower_bound(pos[e[i]]+1,pos[e[i]]+pos[e[i]][0],h)-(pos[e[i]]));
			if(s[pos[e[i]][tmp]]!=e[i] || pos[e[i]][0]<2 || h>pos[e[i]][pos[e[i]][0]-1])
			{
				flag = false;
				break;
			}
			if(i==0)
				a=pos[e[i]][tmp];
			if(i==te-1)
				b=pos[e[i]][tmp];
			
			
			h = pos[e[i]][tmp]+1;
		}
		if(flag)
			printf("Matched %d %d\n",a,b);
		else
			printf("Not matched\n");
	}

		

}	


