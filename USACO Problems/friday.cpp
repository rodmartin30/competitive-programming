/*
ID: tinrodr1
PROG: friday
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
#define ANO 1900
#define ANOBICESTO 2000

using namespace std;

int ano,mes,dia,n,diaActual;
int semana[] = {0,0,0,0,0,0,0};

void calcular(int febrero)
{
    switch(mes)
    {
        case 1:
            if(dia==31)
            {
                mes = 2;
                dia = 1;
            }
            else dia++;
            break;
            
        case 2:
            if(dia==febrero)
            {
                mes = 3;
                dia = 1;
            }
            else dia++;
            break;
        case 3:
            if(dia==31)
            {
                mes = 4;
                dia = 1;
            }
            else dia++;
            break;
        
        case 4:
            if(dia==30)
            {
                mes = 5;
                dia = 1;
            }
            else dia++;
            break;
        
        case 5:
            if(dia==31)
            {
                mes = 6;
                dia = 1;
            }
            else dia++;
            break;
        
        case 6:
            if(dia==30)
            {
                mes = 7;
                dia = 1;
            }
            else dia++;
            break;
        
        case 7:
            if(dia==31)
            {
                mes = 8;
                dia = 1;
            }
            else dia++;
            break;
        
        case 8:
            if(dia==31)
            {
                mes = 9;
                dia = 1;
            }
            else dia++;
            break;
        
        case 9:
            if(dia==30)
            {
                mes = 10;
                dia = 1;
            }
            else dia++;
            break;
        
        case 10:
            if(dia==31)
            {
                mes = 11;
                dia = 1;
            }
            else dia++;
            break;
        
        case 11:
            if(dia==30)
            {
                mes = 12;
                dia = 1;
            }
            else dia++;
            break;
        
        case 12:
            if(dia==31)
            {
                mes = 1;
                dia = 1;
                ano++;
            }
            else dia++;
            break;
        
            
    }
}

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    
    fin >> n;
    mes = dia = 1;
    ano = ANO;
    while(mes!=12 || dia !=31 || ano != ANO+n-1)
    {
        if(dia==13)
            semana[diaActual]+=1;
                    
        if(diaActual<6)
            diaActual++;
        else
            diaActual = 0;
            
        if(ano== ANOBICESTO || (ano%4==0 && ano!=1900 && ano!=2100 && ano!=2200 && ano!=2300))
            calcular(29);
        else
            calcular(28);
            
    }
    fout << semana[5] << " " << semana[6] << " " << semana[0] << " " << semana[1] << " " << semana[2] << " " << semana[3] << " " << semana[4] << endl;
    
    return 0;
    
    
}
