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

int devices[100];

int main()
{
    ofstream fout ("word.out");
    ifstream fin ("word.in");
    vector<int> opp;
    int n,m,c,op,maax,actual,sequence = 0;
    set<int> myset;
    bool exploto;
    while(cin >> n >> m >> c && n!=0)
    {
        sequence++;
        opp.clear();
        maax = actual = 0;
        myset.clear();
        exploto = false;
        for(int i=1;i<=n;i++)
            cin >> devices[i];
        
        for(int i=0;i<m;i++)
        {
            cin >> op;
            opp.push_back(op);
        }
        for(int i =0;i<m;i++)
        {
            op = opp[i];
            
            if(myset.find(op)!= myset.end())
            {
                actual -= devices[op];
                myset.erase(myset.find(op));
            }
            else
            {
                actual += devices[op];
                if(actual>c)
                {
                    exploto = true;
                    break;
                }
                maax = max(maax,actual);
                myset.insert(op);
            }
        }
        if(exploto)
            cout << "Sequence " << sequence << endl << "Fuse was blown." << endl << endl;
        else
            cout << "Sequence " << sequence << endl << "Fuse was not blown." << endl << "Maximal power consumption was " << maax << 
            " amperes." << endl << endl;
        
    }
}
