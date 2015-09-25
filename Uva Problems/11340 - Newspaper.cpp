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
#define T 128
using namespace std;

long long value[260];
    
int main()
{
    ifstream fin ("test.in");
    ofstream fout ("test.out");
    
    int n,characters,val,lineas;
    double cent;
    string linea;
    char c;
    
    cin >> n;
    
    while(n--)
    {  
        cent = 0;
        memset(value, 0, sizeof value);
        
        cin >> characters;
        while(characters--)
        {
            cin >> c >> val;
            value[c+T] = val;
        }
        
        scanf("%d\n",&lineas);
        
       
        while(lineas--)
        {
            
            while((c = getchar()) != '\n')
            {
                value[257] +=value[c+T];
            }
            
        }
        printf("%lld.%02lld$\n", value[257] / 100, value[257] % 100);
        
    }
    
    
    
}
