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
    string linea,palabra = "";
    int comienzo = 0,contador;
    while(getline(cin,linea))
    {
        comienzo = 0;
        for(int i=0;i<=linea.size();i++)
        {
            if(linea[i] == ' ' || i==linea.size())
            {   
                contador =0;
                for(int j=comienzo;j<=i-1;j++)
                {
                    palabra += linea[j];
                }
                comienzo = i+1;
                reverse(palabra.begin(),palabra.end());
                cout << palabra;
                if(i!=linea.size())
                    cout << " ";
                palabra = "";
                
            }
            
        }
        cout << endl;
    }    
}
