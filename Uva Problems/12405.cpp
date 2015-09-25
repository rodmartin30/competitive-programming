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
#define T 105
#define M 9999999
#define ii pair<int,int>
using namespace std;

char field[T];
int crow(int n)
{
	int cant=0;
	bool flag=0;
	fore(i,0,n)
	{
		if(flag)
		{
			field[i]='#';
			if(i>0)
				field[i-1] = '#';
			if(i<n-1)
				field[i+1] = '#';
			cant++;
			flag=false;
		}
		if(field[i]=='.')
			flag=true;
	}
	if(flag)
		cant++;
	return cant;
}
int main()
{
	int test,n,res,caso=0;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		scanf("%s",field);
		
		res= crow(n);
		printf("Case %d: %d\n",++caso,res);
		
		
	}
}
