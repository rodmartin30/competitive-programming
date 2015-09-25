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
    ofstream fout ("word.out");
    ifstream fin ("word.in");
    
    int dia;
    float h,d,u,f,altura,climb,fatiga;
    
    while(cin >> h >> d >> u >> f && h!=0)
    {
        dia = 0;
        altura = 0;
        climb = d;
        fatiga = d*f/100;
        while(altura <= h && altura >= 0)
        {
            dia++;
            altura += climb;
            climb -= fatiga;
            if(climb <0)
                climb = 0;
            if(altura > h)
                break;
            altura -= u; 
        }
        if(altura > h)
            cout << "success on day " << dia << endl;
        else
            cout << "failure on day " << dia << endl;
    }
}
