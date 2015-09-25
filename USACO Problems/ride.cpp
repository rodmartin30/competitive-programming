/*
ID: tinrodr1
PROG: ride
LANG: C++                  
*/
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <fstream>
#include <math.h>

using namespace std;
string s1,s2;
int i1,i2;
int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    fin >> s1 >> s2;
    i1 = i2 = 1;
    for(int i=0;i<s1.size();i++)
    {
        i1 *= (s1[i] - 'A' + 1);
    }
    for(int i=0;i<s2.size();i++)
    {
        i2 *= (s2[i] - 'A' + 1);
    }
    if(i1 %47 == i2%47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}
