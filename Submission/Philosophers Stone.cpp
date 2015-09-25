#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define fore(i,p,k) \
for(int i=p;i<k;i++)
#define T 105
using namespace std;

int maximo(int a, int b,int c)
{
	return max(max(a,b),c);
}
int table[T][T];
int n,m;
int memo[T][T];
int DP(int i,int j)
{
	if(memo[i][j]!=-1)
		return memo[i][j];
	if(i==n)
		return 0;
		
	if(j!=0 && j!= m-1)
		return memo[i][j] = maximo(DP(i+1,j-1)+table[i][j],DP(i+1,j)+table[i][j],DP(i+1,j+1)+table[i][j]);
		
	else if(j==0)
		return memo[i][j] = max(DP(i+1,j)+table[i][j],DP(i+1,j+1)+table[i][j]);
		
	else
		return memo[i][j] = max(DP(i+1,j)+table[i][j],DP(i+1,j-1)+table[i][j]);
}
int main()
{
	int test;
	
	cin >> test;
	
	while(test--)
	{
		fore(i,0,T)
			fore(j,0,T)
				memo[i][j] = -1;
		
		cin >> n >> m;
		
		fore(i,0,n)
			fore(j,0,m)
				cin >> table[i][j];
				
		int maxx = 0;
		fore(j,0,m)
			maxx = max(maxx,DP(0,j));
			
		cout << maxx << endl;
	}
}
