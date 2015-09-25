#include <iostream>
#include <cstdio>
#include <algorithm>
#define ITEM 2005
using namespace std;

long long S[ITEM],V[ITEM];
long long memo[ITEM][ITEM];

long long DP(long long i,long long j)
{
    if(memo[i][j]!=-1)
        return memo[i][j];
    
    if(i==0)
        memo[i][j] = 0;
    
    else if(j-S[i]<0)
        memo[i][j] = DP(i-1,j);
        
    else
        memo[i][j] = max(DP(i-1,j-S[i])+V[i],DP(i-1,j));
        
    return memo[i][j];
}

void initialize()
{
    for(long long i = 0;i<ITEM;i++)
        for(long long j=0;j<ITEM;j++)
            memo[i][j] = -1;
}
int main()
{
    long long s,n,value,size;
    
    cin >> s >> n;
    
    for(long long i=1;i<=n;i++)
        cin >> S[i] >> V[i];
        
    initialize();
    
    cout << DP(n,s) << endl;
    
    
}
