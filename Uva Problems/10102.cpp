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

#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define all(v) v.begin(),v.end()

#define T 10000
#define M 100000000000000
#define E 1e-12
using namespace std;

char a[T][T];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF) {
		long long res = 0,mn = M;
		fore(i,n)
			scanf("%s",a[i]);
			
		for(long long i=0;i<n;i++)
			for(long long j=0;j<n;j++)
				if(a[i][j] == '1') {
					mn = M;
					for(long long g=0;g<n;g++)
						for(long long h=0;h<n;h++)
							if(a[g][h] == '3') {
								mn = min(mn,abs(i-g)+abs(j-h));
							}
							
					res = max(res,mn);
				
				}
		
		
		printf("%lld\n",res);
	    
	
	
	}
	return 0;
}	


