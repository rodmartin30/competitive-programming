#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>

using namespace std;

string m;

int main()
{
    int n,k,salida;
    
    cin >> n >> m;
    
    k = m.size();
    salida = 1;
    
    if(n%k==0)
    {
        for(int i = n;i>=k;i-=k)
            salida*= i;
    }
    else
    {
        for(int i = n;i>=n%k;i-=k)
            salida*= i;        
    }
    
    cout << salida << endl;
    
}
