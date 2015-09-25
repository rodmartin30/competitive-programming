#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <queue>
#define T 500
#define fore(i,m,n) \
for(int i = m;i<n;i++)

using namespace std;


int main(){
	int n;
	cin >> n;
	fore(i,0,n)
		fore(j,0,n)
		{
			cin >> matriz[i][j];	
			if(i>0)
				matriz[i][j] += matriz[i-1][j];
			if(j>0)
				matriz[i][j] += matriz[i][j-1];
			if(i>0 && j>0)
				matriz[i][j] -= matriz[i-1][j-1];
		}
	int subRect=0,maxSubRect=INT_MIN;
	
	fore(i,0,n)
		fore(j,0,n)
			fore(k,i,n)
				fore(l,j,n)
					{
						subRect = matriz[k][l];
						
						if(i>0)
							subRect-= matriz[i-1][l];
						if(j>0)
							subRect-= matriz[k][j-1];
						if(i>0 && j>0)
							subRect+= matriz[i-1][j-1];
						
						maxSubRect = max(maxSubRect,subRect);
					}
	cout << maxSubRect << endl;
}
