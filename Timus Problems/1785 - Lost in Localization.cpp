#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <math.h>
#include <string.h>
#define N 200000
#define M 100

using namespace std;
int n;

int main()
{
    cin >> n;
    if(n<=4) cout << "few" << endl;
    if(n>=5 && n<=9) cout << "several" << endl;
    if(n>=10 && n<=19) cout << "pack" << endl;
    if(n>=20 && n<=49) cout << "lots" << endl;
    if(n>=50 && n<=99) cout << "horde" << endl;
    if(n>=100 && n<=249) cout << "throng" << endl;
    if(n>=250 && n<=499) cout << "swarm" << endl;
    if(n>=500 && n<=999) cout << "zounds" << endl;
    if(n>=1000) cout << "legion" << endl;
    
}
