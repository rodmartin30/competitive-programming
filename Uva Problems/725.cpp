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
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
for(int i=m;i<=n;i++)
#define T 1005
#define ii pair<int,int>
using namespace std;

int main()
{
	int n,abcde,tmp,to,flag,tt=0;
	
	while(scanf("%d",&n) && n!=0)
	{
		flag = 0;
		if(tt)
			printf("\n");
		tt = 1;
		to = 98765/n;
		fori(fghij,1234,to)
		{
			abcde = fghij * n;
			int used = fghij<10000;
			
			tmp = abcde;
			while(tmp)
			{
				used |= 1 << (tmp%10);
				tmp/=10;
			}
			
			tmp = fghij;
			while(tmp)
			{
				used |= 1 << (tmp%10);
				tmp/=10;
			}
			if(used == (1 << 10) -1)
			{
				printf("%.5d / %.5d = %d\n",abcde,fghij,n);
				flag = 1;
			}
			
		}
		if(!flag)
				printf("There are no solutions for %d.\n",n);
	}
}
