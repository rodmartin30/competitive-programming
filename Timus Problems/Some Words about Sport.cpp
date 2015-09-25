#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#define N 105

using namespace std;

int n;
int matrix[N][N];

int main()
{
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        int p = i;
        int k = 0;
        cout << matrix[p][k] << " ";
        while(p!=0)
        {
            p--;
            k++;
            cout << matrix[p][k] << " ";
        }
        
    }
    
    for(int j = 1;j<n;j++)
    {
        int p = n-1;
        int k = j;
        if(k!=n-1)
        cout << matrix[p][k] << " ";
        else
        cout << matrix[p][k] << endl;
        while(p!=j)
        {
            p--;
            k++;
            cout << matrix[p][k] << " ";
        }
    }
    
    
}
