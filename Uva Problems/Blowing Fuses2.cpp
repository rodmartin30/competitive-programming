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

int devices[100][2];
int potencia(int N)
{
    int actual = 0;
    for(int i=1;i<=N;i++)
    {
        if(devices[i][0] == 1)
            actual += devices[i][1];
    }
    return actual;
}

vector<int> opp;
int main()
{
    ofstream fout ("word.out");
    ifstream fin ("word.in");
    int n,m,c,maax=0,sequence = 0,op;
    bool exploto = false;
    
    while(cin >> n >> m >> c && n!=0)
    {
        sequence++;
        opp.clear();
        exploto = false;
        maax = 0;
        for(int i=1;i <= n;i++)
        {
            devices[i][0] = 0;
            cin >> devices[i][1];
            
        }
        for(int i =0;i<m;i++)
        {
            cin >> op;
            opp.push_back(op);
        }
        for(int i =0;i<opp.size();i++)
        {
            op = opp[i];
            if(devices[op][0] == 0)
                devices[op][0] = 1;
            else
                devices[op][0] = 0;
                
            maax = max(maax,potencia(n));
            
            if(potencia(n)> c)
            {
                exploto = true;
                break;
            }
        }
        
        if(exploto)
            cout << "Sequence " << sequence << endl << "Fuse was blown." << endl << endl;
        else
            cout << "Sequence " << sequence << endl << "Fuse was not blown." << endl << "Maximal power consumption was " << maax << 
            " amperes." << endl << endl;
        
    }
}
