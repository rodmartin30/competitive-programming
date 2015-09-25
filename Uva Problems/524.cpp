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
#define T 10000
#define M 25
using namespace std;

int res[M];
bitset<30> b;
int c;
int primo[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0};
void permutation(int i,int n)
{
	int tmp;
	if(i==n && primo[res[n-1]+res[0]])
	{
		c++;
		fore(k,0,n)
		{
			printf("%d",res[k]);
			if(k==n-1)
				printf("\n");
			else
				printf(" ");
		}
	}
	else
	{
		fori(j,2,n)
			if(!b[j] && primo[j+res[i-1]])
			{
				b.flip(j);
				res[i] = j;
				permutation(i+1,n);
				b.flip(j);
			}
	}
}
int main()
{
	int n,flag=0,caso=1;
	while(scanf("%d",&n)!=EOF)
	{
		c=0;
		b.reset();
		if(flag)
			printf("\n");
		flag=1;
		printf("Case %d:\n",caso++);
		res[0] = res[n] = 1;
	
		permutation(1,n);
	}
	
}	


