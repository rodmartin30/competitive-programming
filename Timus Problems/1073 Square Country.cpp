#include<iostream>
#include<cmath>
#define T 60005
#define fore(i,s,n) \
for(int i=s;i<n;i++)
using namespace std;

int memo[T];

int n,c;
void initialize()
{
	for(int i=0;i<T;i++)
		memo[i] = T;
}
int dp(int squares)
{
	int temp = T;
	if(memo[squares] !=T)
		return memo[squares];
		
	if(squares==0)
		return 0;
		
	for(int i=1;i<=floor(sqrt(squares));i++)
	{
		temp = dp(squares-pow(i,2))+1;
		memo[squares] = min(memo[squares],temp);
	}
		
	
	return memo[squares];
}

int main()
{
	cin >> n;
	initialize();
	cout << dp(n) << endl;
}
