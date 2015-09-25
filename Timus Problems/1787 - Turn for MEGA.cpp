#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <math.h>
#include <string.h>

using namespace std;
int n,k,totalAutos,temp,cola;

int main()
{
    cin >> k >> n;
    totalAutos=cola=0;
    
    for(int i = 0;i<n;i++)
    {
        cin >> temp;
        cola += temp-k;
        if(cola < 0)
            cola = 0;
    }
    
    cout << cola << endl;
    
}
