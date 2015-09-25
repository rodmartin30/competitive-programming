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
#define M 1000000005
using namespace std;

int milk[T],n;
bool Ican(int k,int con)
{
	bool flag=true;
	int tmp=0,m=con-1;
	fore(i,0,n)
	{
		if(milk[i]>k)
		{
			flag = false;
			break;
		}
		else if(tmp+milk[i]>k && m==0)
		{
			flag = false;
			break;
		}
		else if(tmp+milk[i]>k)
		{
			if(m>0)
			{
				m--;
				tmp=milk[i];
			}
			else
			{
				flag = false;
				break;
			}
		}
		else 
			tmp+=milk[i];
	}
	return flag;
}

int whichK(int m)
{
	int mn=1,mid,mx=M;
	while(mx-mn>1)
	{
		mid = (mn+mx)/2;
		if(Ican(mid,m))
			mx=mid;
		else
			mn = mid;
	}
	if(Ican(mn,m))
		return mn;
	else
		return mx;
}
int main()
{
	int m,res;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		fore(i,0,n)
			scanf("%d",&milk[i]);
		
		res =whichK(m);
		printf("%d\n",res);
	}
}	


