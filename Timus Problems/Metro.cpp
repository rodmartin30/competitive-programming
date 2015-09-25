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
#define T 1005
#define cuad 100.0
#define diag 141.421356237
using namespace std;

double memo[T][T];
bool diagonales[T][T];

double minimo(double a,double b,double c)
{
	return min(a,(min(b,c)));
}
void initialize()
{
	for(int i =0;i<T;i++)
		for(int j=0;j<T;j++)
		{
			memo[i][j] = -1;
			diagonales[i][j] = false;
		}
}

double dp(int x,int y)
{
	double temp;
	
	if(memo[x][y]!= -1)
		return memo[x][y];
	
	if(x==0 && y==0)
		temp = 0;
	
	
	else if(diagonales[x][y])
		temp = minimo(dp(x-1,y-1)+diag,dp(x-1,y)+cuad,dp(x,y-1)+cuad);
		
	else 
	{
		if(x!=0 && y!=0)
			temp =min(dp(x-1,y)+100,dp(x,y-1)+100);
		else if(x!=0)
			temp = dp(x-1,y)+100;
		else if(y!=0)
			temp = dp(x,y-1)+100;
	}
		
	memo[x][y] = temp;
	return temp;
}

int main()
{
   int n,m,d,p1,p2;
   
   cin >> n >> m >> d;
   initialize();
   for(int i=0;i<d;i++)
   {
		cin >> p1 >> p2;
		diagonales[p1][p2] = true;
   }
   
   cout << (int)round(dp(n,m)) << endl;
    
}
