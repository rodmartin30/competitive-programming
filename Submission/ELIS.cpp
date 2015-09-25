#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#define T 10000

using namespace std;

vector<int> S;
int memo[T][T];

int DP(int i,int k)
{
 
    if(memo[i][k] != -1)
        return memo[i][k]; 
    if(i==S.size())
        memo[i][k] = 0;          
    else if(k<S[i])
        memo[i][k] =  max(DP(i+1,S[i])+1,DP(i+1,k));    
    else
        memo[i][k] = DP(i+1,k);
    
    return memo[i][k];
}

void initialize()
{
    for(int i=0;i<T;i++)
        for(int j = 0;j<T;j++)
            memo[i][j] = -1;
}
int main()
{
    int n,temp;
    
    cin >> n;
    S.resize(n);
    
    initialize();
    
    for(int i=0;i<n;i++)
        cin >> S[i];

     cout << DP(0,0) << endl;
}
