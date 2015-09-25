#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#define filas 12
#define columnas 12

using namespace std;

int tablero[filas][columnas];
int n,f,c;
string s;
char col;

int caballero(int f, int c)
{
    int cantidad = 0;
    if(tablero[f+2][c+1] == 1) cantidad++;
    if(tablero[f+2][c-1] == 1) cantidad++;
    if(tablero[f-2][c+1] == 1) cantidad++;
    if(tablero[f-2][c-1] == 1) cantidad++;
    if(tablero[f+1][c+2] == 1) cantidad++;
    if(tablero[f-1][c+2] == 1) cantidad++;
    if(tablero[f+1][c-2] == 1) cantidad++;
    if(tablero[f-1][c-2] == 1) cantidad++;
    
    return cantidad;
}

int main()
{   
    
    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
        {
            if(j>1 && j<10 && i>1 && i<10)
                tablero[i][j] = 1;
            else
                tablero[i][j] = 0;
        }
       
    
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        cin >> s;
        col = s[0];
        c = col - 'a';
        f = s[1] - '0';
        
        cout << caballero(c+2,f+1) << endl;
        
    }/*
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
        }*/
}
