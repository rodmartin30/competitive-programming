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

using namespace std;

int main()
{
    int n,suma,resta,a,b;
    vector<int> ab;
    cin >> n;
    
    while(n--)
    {
        ab.clear();
        suma = resta = a = b = 0;
        
        cin >> suma >> resta;
        
        b = (suma - resta)/2;
        a = suma - b;
        ab.push_back(a);
        ab.push_back(b);
        sort(ab.begin(),ab.end());
        
        if(ab[0] > suma || ab[1] > suma || ab[0] + ab[1]!=suma || ab[1]-ab[0] != resta)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << ab[1] << " " << ab[0] << endl;
        }       
    }
}
