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
#include <cstdlib>
#include <iomanip>

using namespace std;

int tabla[30];

int main()
{
    int t = 0;
    char c[10];
    
    ofstream fout ("word.out");
    ifstream fin ("word.in");
    
    for(int i =0;i<30;i++)
        tabla[i] = 0;
    tabla['B'-'A'] = tabla['P'-'A'] = tabla['F'-'A'] = tabla['V'-'A'] = 1;
    tabla['C'-'A'] = tabla['S'-'A'] = tabla['K'-'A'] = tabla['G'-'A'] = tabla['J'-'A'] = tabla['Q'-'A'] = tabla['X'-'A'] = tabla['Z'-'A'] = 2;
    tabla['T'-'A'] = tabla['D'-'A'] = 3;
    tabla['L'-'A'] = 4;
    tabla['M'-'A'] = tabla['N'-'A'] = 5;
    tabla['R'-'A'] = 6;
    
    string nombre,codigo;
    cout << "         NAME                     SOUNDEX CODE" << endl;
    while(cin >> nombre && !cin.eof())
    {
        codigo = "";
        codigo += nombre[0];
        
        for(int i=1;i<nombre.size();i++)
        {
            if(tabla[nombre[i]-'A'] != tabla[nombre[i-1]-'A'] && tabla[nombre[i]-'A'] != 0 && codigo.size()<4)
            {
                snprintf(c, 10, "%d", tabla[nombre[i]-'A']);
                codigo +=c[0];
                
            }
        }
        t = 4-codigo.size();
        for(int i=0;i<t;i++)
            codigo += "0";
            
        cout << "         " << nombre;
        for(int i =0;i<25-nombre.size();i++)
            cout << " ";
        cout << codigo << endl;
    }
    cout << "                   END OF OUTPUT" <<endl;
}
