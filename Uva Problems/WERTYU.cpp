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
    string l1 = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./",linea;
    
    while(getline(cin,linea))
    {
        for(int i=0;i<linea.size();i++)
        {
            if(linea[i] != ' ')
            {
                for(int j=0;j<l1.size();j++)
                {
                    if(l1[j] == linea[i])
                    {
                        cout << l1[j-1];
                        break;
                    }
                }
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}
