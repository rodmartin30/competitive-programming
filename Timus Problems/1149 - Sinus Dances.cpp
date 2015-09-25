#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

int n;


void An(int n)
{
    
    for(int i = 1;i<=n;i++)
    {
        if(i%2!=0 && i!=n)
        {
            cout <<  "sin(" << i << "-";
        }
        else
        {
            if(i%2==0 && i!=n)
               cout <<  "sin(" << i << "+";
            else
            {
                if(i==n)
                {
                   cout <<  "sin(" << i;
                   for(int j=0;j<n;j++)
                   {
                       cout << ")";
                   }
                }
            }
        }
    }
    
}

void Sn(int n)
{
    for(int j=1;j<n;j++)
    {
        cout << "(";
    }
    for(int i = 0;i<n;i++)
    {
        if(i!=n-1)
        {
            An(i+1);
            cout << "+" << n-i << ")";
        }
        else
        {
            An(i+1);
            cout << "+" << n-i << endl;
        }
    }
    
}
int main()
{
    scanf("%d",&n);
    Sn(n);
}
