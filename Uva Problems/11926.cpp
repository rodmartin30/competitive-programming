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
#define T 1005
#define M 1000000
#define ii pair<int,int>
using namespace std;



bitset<1000005> k;
int main()
{
	
	int n,m;
	while(scanf("%d %d",&n,&m) && n+m != 0) {
		k.reset();
		int a,b,c;
		bool flag = false;
		
		fore(i,n) {
			scanf("%d %d",&a,&b);
			for(int j=a;j<b && i<M && !flag;j++) {
				if(k[j])
					flag = true;
				k[j] = 1;
			}
		}
		
		fore(i,m) {
			scanf("%d %d %d",&a,&b,&c);
			int dif = b-a;
			while(a<M && !flag){
				for(int j=a;j<b && !flag && j<M;j++) {
					if(k[j])
						flag = true;
					k[j] = 1;
				}
				a+=c;
				b+=c;
			}
		
		}
		if(!flag)
			printf("NO CONFLICT\n");
		else
			printf("CONFLICT\n");
			
	
	}
	
}
