#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int n,m;

int main()
{
    cin >> n >> m;
    
    if(n*m%2==0) 
        cout << "[:=[first]" << endl;
    else
        cout << "[second]=:]" << endl;
    
}
