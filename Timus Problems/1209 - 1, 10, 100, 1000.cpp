#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <math.h>
#define N 65535


using namespace std;

int n;
long long unos,suma,posicion;
long long unosArray[N];

bool busqueda_binaria(long long num)
{
    long mn = 0;
    long mx = N; 
    
    while(mx-mn > 1)
    {
        long med = (mx + mn) /2;
        if(unosArray[med] > num)
            mx = med;
        else
            mn = med;
    }
    
    if(unosArray[mn] == num)
        return true;
    return false;
}

int main()
{
    unos = 1;
    for(int i = 0;i<N;i++)
    {
        unosArray[i] = unos;
        unos+= ++suma;
    }
    
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin >> posicion;
        if(i!=n-1)
        {
            
            if(busqueda_binaria(posicion))
                cout << "1 ";
            else
                cout << "0 ";
        }
        else
        {
            if(busqueda_binaria(posicion))
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }
    
}
