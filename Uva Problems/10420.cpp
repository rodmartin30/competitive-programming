#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <math.h>
#include <utility>
#include <queue>
#include <string.h>
#include <set>
#include<sstream>

using namespace std;

vector<string> input;


int main()
{
    int n,cant;
    cin >> n;
    
    string s,linea,s1;
    set<string> myset;
    

    while(n--)
    {
        cin >> s;
        getline(cin,linea);
        
        input.push_back(s);
        myset.insert(s);
    }
    
    for(set<string>::iterator it=myset.begin(); it!=myset.end(); ++it)
    {
        cant = 0;
        for(int i =0;i<input.size();i++)
        {
            if(*it == input[i])
                cant++;
        }
        cout << *it << " " << cant << endl;
    }
   
}
