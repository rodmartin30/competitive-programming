#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <utility>
#include <set>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#define T 110

int memo[T][T],tablero[T][T];
int n,temp,maxi=INT_MIN;
void initialize()
{
	for(int i=0;i<T;i++)
		for(int j=0;j<T;j++)
			memo[i][j] = 0;
}
using namespace std;

int main()
{
	cin >> n;
	initialize();
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> tablero[i][j];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int h=1;h<=i;h++)
				for(int k=1;k<=j;k++)
					memo[i][j] += tablero[h][k];
					
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int h=1;h<=i;h++)
				for(int k=1;k<=j;k++)
				{
					temp = memo[i][j] - memo[i][k-1] - memo[h-1][j] + memo[h-1][k-1];
					
					maxi = max(temp,maxi);
				}
	
	cout << maxi << endl;
}			
