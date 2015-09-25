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
#define T 10005
#define M 10000005
using namespace std;

int step[M],n;
bool Ican(int v)
{
	bool yes = true;
	int k = v;
	if(step[0]==k)
		k--;
	else if(step[0]>k)
		yes = false;
	if(yes)
		fore(i,0,n-1)
		{
			if(step[i+1]-step[i]>k)
			{
				yes = false;
				break;
			}
			else if(step[i+1]-step[i] == k)
				k--;
		}
	return yes;
}

int whichK()
{
	int mn=1,mx=M,mid;
	while(mx-mn>1)
	{
		mid = (mn+mx)/2;
		if(Ican(mid))
			mx= mid;
		else
			mn = mid;
	}
	if(Ican(mn))
		return mn;
	else 
		return mx;
}
int main()
{
	int tc=0,test,res;
	scanf("%d",&test);
	while(test--){
		
		scanf("%d",&n);
		fore(i,0,n)
			scanf("%d",&step[i]);
		
		
		res = whichK();
		printf("Case %d: %d\n",++tc,res);
		
	}
}	


