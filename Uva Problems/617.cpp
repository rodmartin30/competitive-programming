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
#include <fstream>
#include <cstring>
#include <bitset>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
for(int i=m;i<=n;i++)
#define T 32
#define M 9999999
#define ii pair<int,int>
using namespace std;

struct signal{
	double mp;
	int green,yellow,red,allow,total;
} sig;
vector<signal> s;
vector<int> sol;
int main()
{
	int n,res,t,caso=0,timei;
	bool flag;
	double time;
	while(scanf("%d",&n)!=EOF && n!=-1)
	{
		s.clear();
		s.resize(n);
		sol.clear();
		fore(i,0,n){
			cin >> sig.mp >> sig.green >> sig.yellow >> sig.red;
			sig.allow = sig.green + sig.yellow;
			sig.total = sig.allow + sig.red;
			s[i] = sig;
		
		}
		
		fori(i,30,60)
		{
			flag=true;
			fore(j,0,n)
			{
				time = s[j].mp*3600/i;
				timei=time;
				if(s[j].red && ((time-timei)+(timei%s[j].total))>(double)s[j].allow)
				{
					flag=false;
					break;
				}
			}
			if(flag)
					sol.push_back(i);
		}
		t = sol.size();
		if(t){
			res = sol[0];
			printf("Case %d:",++caso);
		}
		else
			printf("Case %d: No acceptable speeds.\n",++caso);
		
		fore(i,0,t-1)
		{
			if(abs(sol[i]-sol[i+1])>1){
				if(res!=sol[i])
					printf(" %d-%d,",res,sol[i]);
				else
					printf(" %d,",res);
				
				res = sol[i+1];
			}
			if(i==t-2){
				if(res==sol[t-1])
					printf(" %d\n",res);
				else
					printf(" %d-%d\n",res,sol[t-1]);
			
			}
			//printf("%d\n",i);
		}
		
	}
	
	
}
