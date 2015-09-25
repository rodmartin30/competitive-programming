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
#define fore(i,n) for(int i=0;i<n;i++)
#define fori(i,n) for(int i=0;i<=n;i++)
#define T 30
#define M 1000000
#define ii pair<int,int>
using namespace std;

int a[T];
int main()
{
	bool ahora = false;
	int n,caso=0;
	long long cant=0, tmp;
	while(scanf("%d",&n) != EOF) {
		cant = 0;
		fore(i,n)
			scanf("%d",&a[i]);
			
		fore(i,n) {
			tmp = 1;
			for(int j =i;j<n;j++) {
				tmp*=a[j];
				cant = max(cant,tmp);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n",++caso,cant);
	}
	
	
}
