#include <iostream>
#define T 19
using namespace std;

int n,k;
int memo[T];
int DP(int n)
{
	int res;
	if(memo[n]!=-1)
		return memo[n];
	if(n==0)
		res = 1;
	else if(n==1)
		res = k-1;
		
	else
		res = (k-1)*(DP(n-1)+DP(n-2));
	
	memo[n] = res;
	return res;
	
	
}
int main()
{
	cin >> n >> k;
	
	for(int i =0;i<T;i++)
		memo[i] = -1;
	
	cout << DP(n) << endl;
}
