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

#define T 60000
#define M 600
#define E 1e-12
using namespace std;


int main()
{
	
	int vt,cant = 0,b;
	bool flag = false;
	double mx = -1,v,l;
	while(scanf("%d %d",&vt,&b) && vt+b != 0) {
		
		mx = -1;
		flag = false;
		double tmp;
		cant = 0;
		for(int i=1;vt>b*i;i++) {
			v = (double)vt/i;
			tmp = 0.3*sqrt(v-b) * i;
			if(tmp-mx > E) {
				mx = tmp;
				flag = false;
				cant = i;
			}
			else if (fabs(tmp-mx)<E) {
					flag = true; 
			}
		}
		if(flag)
			printf("0\n");
		else
			printf("%d\n",cant);
	}      
	
}	


