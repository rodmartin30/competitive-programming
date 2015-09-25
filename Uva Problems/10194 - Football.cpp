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
#include <cctype>
#include <locale>

using namespace std;

struct equipo{
    string nombre;
    int partidosGanados,partidosEmpatados,partidosPerdidos,golesFavor,golesContra;
    
    equipo(string name)
    {
        partidosGanados = partidosEmpatados = partidosPerdidos = golesFavor = golesContra = 0;
        nombre = name;
    }
    equipo()
    {
        partidosGanados = partidosEmpatados = partidosPerdidos = golesFavor = golesContra = 0;
    }
};
vector<equipo> vteam;
locale loc;
map<string,equipo> mteam;
bool compare(pair<string,equipo> e1, pair<string,equipo> e2)
{
    equipo i,j;
    i = e1.second;
    j= e2.second;
    int pointI,pointJ,gDI,gDJ,totalGamesI,totalGamesJ;
    pointI = i.partidosGanados*3 + i.partidosEmpatados;
    pointJ = j.partidosGanados*3 + j.partidosEmpatados;
    gDI = i.golesFavor - i.golesContra;
    gDJ = j.golesFavor - j.golesContra;
    totalGamesI = i.partidosGanados + i.partidosEmpatados + i.partidosPerdidos;
    totalGamesJ = j.partidosGanados + j.partidosEmpatados + j.partidosPerdidos;
    
    if(pointI != pointJ) 
        return pointI > pointJ;
    
    if(i.partidosGanados != j.partidosGanados) 
        return i.partidosGanados > j.partidosGanados;
       
    if(gDI != gDJ) 
        return gDI > gDJ;
           
    if(i.golesFavor != j.golesFavor) 
        return i.golesFavor > j.golesFavor;
               
    if(totalGamesI != totalGamesJ) 
        return totalGamesI < totalGamesJ;
                 
    for(int k=0; k<i.nombre.length(); k++) i.nombre[k] = tolower(i.nombre[k]);
    for(int k=0; k<j.nombre.length(); k++) j.nombre[k] = tolower(j.nombre[k]);
 
    return i.nombre < j.nombre;
                    
        
}

int toInt(string s)
{
    istringstream in(s);
    int i;
    in >> i;
    
    return i;
}

int main()
{
    ifstream fin ("test.in");
    ofstream fout ("test.out");
    
    //-------------------------INICIALIZACIONES-------------------------
    
    int n,teams,games,res1,res2;
    string teamA,teamB;
    //-------------------------FIN INICIALIZACIONES-------------------------
    
    scanf("%d\n",&n);
    
    for(int h=0;h<n;h++)
    {
        //-------------------------RE-INICIALIZACIONES-------------------------
        
        vteam.clear();
        mteam.clear();
        //-------------------------FIN RE-INICIALIZACIONES-------------------------
        
        //-------------------------INPUT-------------------------
        char torneo[1000];
        gets(torneo);
        
        scanf("%d\n",&teams);
        
        for(int i =0;i<teams;i++)
        {
            char nombreEquipo[1000];
            gets(nombreEquipo);
            equipo team(nombreEquipo);
            
            mteam.insert(make_pair(nombreEquipo,team));
        }
        
        scanf("%d",&games);
        
        char game[1000];
 
        gets(game);
        
        for(int i=0;i<games;i++)
        {
            gets(game);
            
            teamA = teamB = "";
            char buff;
            istringstream is(game);
            
            getline(is,teamA,'#');
            is >> res1 >> buff >> res2 >> buff;
            getline(is,teamB);
            
                   
            
            //-------------------------UPDATE TABLE -------------------------
            mteam[teamA].golesFavor += res1;
            mteam[teamB].golesFavor += res2;
            
            mteam[teamA].golesContra +=res2;
            mteam[teamB].golesContra += res1;
            
            if(res1>res2)
            {   
                mteam[teamA].partidosGanados++;
                mteam[teamB].partidosPerdidos++;
            }
            else
            {
                if(res1<res2)
                {
                    mteam[teamA].partidosPerdidos++;
                    mteam[teamB].partidosGanados++;
                }
                else
                {
                    mteam[teamA].partidosEmpatados++;
                    mteam[teamB].partidosEmpatados++;
                }
            }
            
            //-------------------------END UPDATE TABLE-------------------------
        }
        
        
        //-------------------------FIN INPUT-------------------------
        vector< pair<string, equipo> > vteam;
        copy(mteam.begin(), mteam.end(), back_inserter(vteam));
        
        sort(vteam.begin(),vteam.end(),compare);
        
        printf("%s\n", torneo);
        for(int i=0;i<vteam.size();i++)
        {
            int puntos= vteam[i].second.partidosGanados*3 + vteam[i].second.partidosEmpatados;
            int partidosJugados = vteam[i].second.partidosGanados + vteam[i].second.partidosEmpatados + vteam[i].second.partidosPerdidos;
            int difGoles = vteam[i].second.golesFavor - vteam[i].second.golesContra;
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,vteam[i].first.c_str(),puntos,partidosJugados,vteam[i].second.partidosGanados,vteam[i].second.partidosEmpatados,vteam[i].second.partidosPerdidos,difGoles,vteam[i].second.golesFavor,vteam[i].second.golesContra);
            
        }
        if(h!=n-1)
            cout << endl;
            
        
    }
    
    
}
