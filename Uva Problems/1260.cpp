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
#include <string>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
fore(int i=m;i<=n;i++)
#define T 1000005



using namespace std;

int a[T];
int main()
{
	int test,n;
	long b;
	scanf("%d",&test);
	while(test--)
	{
		b = 0;
		scanf("%d",&n);
		fore(i,0,n)
			scanf("%d",&a[i]);
			
		fore(i,1,n)
			fore(j,0,i)
				if(a[j] <= a[i])
					b++;
					
		printf("%ld\n",b);
				
	}
		
}	
