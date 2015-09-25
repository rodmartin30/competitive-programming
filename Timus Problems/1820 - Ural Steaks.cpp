#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <math.h>
#include <string.h>

using namespace std;
int n,k;

int main()
{
    cin >> n >> k;
    if(n>=k){
        if(n*2%k==0)
            cout << n*2/k << endl;
        else
            cout << (n*2/k)+1 << endl;
    }
    else
        cout << 2 << endl;
}
