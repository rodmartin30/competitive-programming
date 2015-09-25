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
#define white 0
#define blue 1
#define red 2
#define T 60

using namespace std;

long long memo[T][T][T];
int n;
void initialize()
{
	for(int i=0;i<T;i++)
		for(int j=0;j<T;j++)
			for(int k=0;k<T;k++)
				memo[i][j][k] = -1;
}
long long DP(int i,int j,int k)
{
	long long temp = 0;
	if(memo[i][j][k]!=-1)
		return memo[i][j][k];
    if(i==0)
        temp = DP(1,k,red) + DP(1,k,white);
    
    else if(i==n)
        temp = 1;
        
    else if(i==n-1)
    {
        if(k==white)
            temp = DP(i+1,k,red);
        if(k==red)
        	temp = DP(i+1,k,white);
       	if(k==blue)
       	{
       		if(j==red)
       			temp = DP(i+1,k,white);
       		if(j==white)
       			temp = DP(i+1,k,red);
       	
   		}
   	}
   	else
   	{
   		if(k==white)
   			temp = DP(i+1,k,blue) + DP(i+1,k,red);
   		if(k==red)
   			temp = DP(i+1,k,blue) + DP(i+1,k,white);
   		if(k==blue)
   		{
   			if(j==white)
   				temp = DP(i+1,k,red);
   			if(j==red)
   				temp = DP(i+1,k,white);
   		}
   	}
    
    memo[i][j][k] = temp;
    return temp;
}

int main()
{
   
    cin >> n;
    initialize();
    
    cout << DP(0,3,3) << endl;
}
