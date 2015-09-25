/*
ID: tinrodr1
PROG: gift1
LANG: C++                  
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <fstream>
#include <math.h>

using namespace std;
map<string,int> personas;
vector<string> p;
string s;
int n,dinero,cantidaPersonas;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    fin >> n;
    
    for(int i=0;i<n;i++)
    {
        fin >> s;
        p.push_back(s);
        personas[s] = 0;
    }
    
    for(int i=0;i<n;i++)
    {
        fin >> s;
        fin >> dinero >> cantidaPersonas;
        if(cantidaPersonas!=0)
            personas[s] -= (dinero - (dinero % cantidaPersonas));
        for(int j=0;j<cantidaPersonas;j++)
        {
            fin >> s;
            if(cantidaPersonas !=0)
                personas[s] += dinero / cantidaPersonas;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        fout << p[i] << " " << personas[p[i]] << endl;
    }
    return 0;
}
