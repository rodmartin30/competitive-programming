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
#define M 10000000
using namespace std;

int books[T];
int main()
{
	int n,money,rest,a,b,mid,tmp;
	while(scanf("%d",&n)!=EOF)
	{
		fore(i,0,n)
			scanf("%d",&books[i]);
		
		scanf("%d",&money);
		sort(books,books+n);
		mid = money/2+1;
		a = 0;
		b = M;
		fore(i,0,n)
		{
			if(books[i]>mid)
				break;
			tmp = (int)(lower_bound(books+i+1,books+n,money-books[i])-books);
			if(books[tmp]+books[i]==money && abs(b-a)>abs(books[tmp]-books[i]))
			{
				a=books[i];
				b=books[tmp];
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n",a,b);
		printf("\n");
	}
}	


