#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <math.h>

using namespace std;

int n,c,p;
string s;

int main()
{
    
    p=1;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        cin >> s;
        if(s[0] == 'A' || s[0] == 'P' || s[0] == 'O' || s[0] == 'R' )
        {
            c+=abs(p-1);
            p=1;
        }
        else
        {
            if(s[0] == 'B' || s[0] == 'M' || s[0] == 'S')
            {
                c+=abs(p-2);
                p=2;
            }
            else
            {
                c+=abs(p-3);
                p=3;
            }
        }
    }
    cout << c << endl;
}
