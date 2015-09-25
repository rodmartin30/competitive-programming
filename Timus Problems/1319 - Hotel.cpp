#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#define L 105

using namespace std;

int n,p,k,contador;
int hotel[L][L];

int main()
{
    scanf("%d",&n);
    
    for(int i=n-1;i>=0;i--)
    {
        contador++;
        p = i;
        k = 0;
        hotel[k][p] = contador;
        while(p!=n-1)
        {
            contador++;
            p++;
            k++;
            hotel[k][p] = contador;
        }
        
    }
    
    for(int i = 1;i<n;i++)
    {
        contador++;
        k=i;
        p = 0;
        hotel[k][p] = contador;
        while(k!=n-1)
        {
            contador++;
            p++;
            k++;
            hotel[k][p] = contador;
        }
        
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(j!=n-1)
                cout << hotel[i][j] << " ";
            else
                cout << hotel[i][j];
        }
        cout << endl;
        }
}
