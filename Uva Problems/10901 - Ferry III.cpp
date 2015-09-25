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
#include <sstream>
#include <stack>

using namespace std;

struct ferry{
    string estado;
    int cargados,tiempo;
    
    ferry()
    {
        estado = "left";
        cargados = tiempo = 0;
    }
};
vector<pair<int,string> > salida;
vector<string> ordenes;
ferry f;
int n,t;
void cargar(queue<pair<int,string> >& Q,int temp,string pestado)
{
    f.cargados = 0;
    string s;
    if(f.estado != pestado)
    {
        if(f.tiempo < temp)
            f.tiempo = temp + t;
        else 
            f.tiempo += t;
        f.estado = pestado;
    }
    else if(f.tiempo < temp)
            f.tiempo = temp;
        
    s = f.estado;
    while(!Q.empty() && f.cargados<n && f.tiempo >= Q.front().first)
    {
        f.cargados++;
        Q.pop();
    }
    
    if(f.estado == "left")
        f.estado = "right";
    else
        f.estado = "left";
    
    f.tiempo += t;
    for(int i=0;i<f.cargados;i++)
    {
        salida.push_back(make_pair(f.tiempo,s));
    }
}
int main()
{
    ifstream fin ("test.in");
    ofstream fout ("test.out");
    
    int test;

    scanf("%d\n",&test);
    
    while(test--)
    {
        int m;
        f.tiempo = 0;
        f.cargados = 0;
        f.estado = "left";
        ordenes.clear();
        salida.clear();
        queue<pair<int,string> > L,R;
        cin >> n >> t >> m;
        
        while(m--)
        {
            int tempInt;
            string tempString;
            cin >> tempInt >> tempString;
            ordenes.push_back(tempString);
            if(tempString == "left")
                L.push(make_pair(tempInt,tempString));
            else
                R.push(make_pair(tempInt,tempString));
        }
        while(!L.empty() || !R.empty())
        {
            if(!L.empty() && f.tiempo>=L.front().first && f.estado=="left")
            {
                cargar(L,L.front().first,"left");
                continue;
            }
            if(!R.empty() && f.tiempo>=R.front().first && f.estado == "right")
            {
                cargar(R,R.front().first,"right");
                continue;
            }
        
        
            if(!L.empty() && !R.empty() && L.front().first == R.front().first)
            {
                if(f.estado == "right")
                {
                     cargar(R,R.front().first,"right");
                }
                else
                    cargar(L,L.front().first,"left");
            }
            else 
            {   
                if(R.empty() || L.empty())
                {
                    if(R.empty())
                        cargar(L,L.front().first,"left");
                    else
                        cargar(R,R.front().first,"right");
                }
                else
                {
                    if(L.front().first<R.front().first)
                        cargar(L,L.front().first,"left");
                    else
                        cargar(R,R.front().first,"right");
                }
           }
                   
        } 
        for(int i=0;i<ordenes.size();i++)
            for(int j=0;j<salida.size();j++)
            {
                if(ordenes[i] == salida[j].second)
                {
                    cout << salida[j].first << endl;
                    salida.erase(salida.begin()+j);
                    break;
                }
            }
       
        if(test>=1)
            cout << endl;
    }
}
