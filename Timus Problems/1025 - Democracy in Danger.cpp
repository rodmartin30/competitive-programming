#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>

using namespace std;

vector<int> grupos;

int main()
{
    int n,k,mismoPartido;
    mismoPartido = 0;
    
    cin >> n;
    
    for(int i = 0;i<n;i++)
    {
        cin >> k;
        grupos.push_back(k);
    }
    
    sort(grupos.begin(),grupos.end());
    
    for(int i = 0;i<(n/2)+1;i++)
    {
        mismoPartido += ((grupos[i]/2)+1);
    }
    
    cout << mismoPartido << endl;
}
