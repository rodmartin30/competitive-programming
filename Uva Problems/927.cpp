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
#include <bitset>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
for(int i=m;i<=n;i++)
#define T 32
#define M 9999999
#define ii pair<int,int>
using namespace std;

vector<int> p;
long long power(long long n,int e)
{
	long long res=1;
	fore(i,0,e)
		res*=n;
	return res;
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		long long n,d,k,c,r; bool flag=true;
		cin >> n;
		p.clear(); p.resize(n);
		fori(i,0,n)
			cin >> p[i];
		cin >> d >> k;
		c=0;
		for(long long i=1;i<=k && flag;i++)
		{
				c+=i*d;
				if(k<=c)
				{
					r=p[0];
					fori(h,1,n)
						r+=p[h]*power(i,h);
					flag=false;
				}
				
		}
		
		printf("%lld\n",r);
	}
}
