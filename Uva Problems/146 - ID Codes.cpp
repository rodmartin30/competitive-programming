#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <math.h>
#include <utility>
#include <queue>
#include <set>
#include <string.h>
#include <fstream>

using namespace std;
 
int main()
{
    string s,seq;
    
    while(cin >> s && s!="#")
    {
        seq = s;
        sort(seq.begin(),seq.end());
        next_permutation(s.begin(),s.end());
        if(s != seq)
            cout << s << endl;
        else
            printf("No Successor\n");
    }
    
    
    
}
