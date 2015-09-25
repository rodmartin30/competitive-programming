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
#define T 1005
#define M 9999999
#define ii pair<int,int>
using namespace std;

int coins[T],n;
int withdraw(long long x,int coin)
{
	int res=0;
	if( x == 0) return 0;
	fore(i,1,n)
	{
		if(coins[i]>x)
		{
			res=i-1;
			break;
		}
		else if(i==n-1)
			res = i;
	}
	if(coin!=res)
		return 1+withdraw(x-coins[res],res);
	else 
		return withdraw(x-coins[res],res);
}
int main()
{
	long long money;
	int test,cant,tmp;
	scanf("%d",&test);
	while(test--)
	{
		cant=0;
		money=0;
		tmp=INT_MAX;
		scanf("%d",&n);
		fore(j,0,n)
			scanf("%d",&coins[j]);
		
		money=coins[0];
		fore(i,1,n)
		{
			
			if(i<n-1 && money+coins[i]<2*coins[i] && money+coins[i]<coins[i+1])
				money+=coins[i];
			else if(i==n-1 && money+coins[i]<2*coins[i])
				money+=coins[i];
		}
		
		cant = withdraw(money,n);
		
		printf("%d\n",cant);
	}
}
