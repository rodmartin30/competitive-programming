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

int toInt(string s)
{
	istringstream in(s);
	int i;
	in >> i;
	return i;
}
char buff[T];
long long ceros[T];
int main()
{
	int t,j,yes,used,caso=1,m;
	long long put=1;
		
		

		for(int i=9876543;i>=10;i--)
		{
			put = 1;
			memset(ceros,0,sizeof(ceros));
			yes =1;
			used =0;
			snprintf(buff,T,"%d",i);
			t=0;int tmp = i;
			while(tmp)
			{
				tmp/=10;
				t++;
			}
			fore(k,0,t)
			{
				used |= 1 << (int)(buff[k]-'0');
			}
			bitset<T> foo(used);
			if(foo.count() != t)
				continue;
			
			j = (0+ ( ( (int)(buff[0]-'0') )%t) )%t;
			while(true)
			{
				if(ceros[j] == put)
					break;
				ceros[j] = put;
				j = (j + ( ( (int)(buff[j]-'0') )%t) )%t;
			}
			
			fore(k,0,t)
				if(ceros[k]!=put)
					yes = 0;
					
			if(yes)
			{
				printf("Case %d: %d\n",caso,i);
				caso++;
				break;
			}
			
			put++;
		}
	}
}
