/*
ID: tinrodr1
PROG: beads
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

int n,maxx,temp,tempmaxx;
string s,s3;
char c,l,r;

bool existe(char c,string s)
{
    for(int i =0;i<s.size();i++)
    {
        if(s[i] == c)
            return true;
    }
    return false;
}
int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    
    fin >> n;
    fin >> s;
    s3 = s + s + s;
    if(!(existe('r',s) && existe('b',s)))
        fout << n << endl;
    else
    {   
        for(int i =n;i<2*n;i++)
        {
            tempmaxx = 0;
            temp = i;
            while(s3[temp] == 'w')
                temp++;
            c = s3[temp];
            temp = i;
            while(s3[temp] == c || s3[temp] == 'w')
            {
               tempmaxx++;
               temp++;            
            }
            
            
            temp = i-1;
            while(s3[temp] == 'w')
                temp--;
            c = s3[temp];
            temp=i-1;
            while(s3[temp] == c || s3[temp] == 'w' )
            {
               tempmaxx++;
               temp--;            
            }
            
            maxx = max(maxx,tempmaxx);
        }
        if(maxx < n)
            fout << maxx << endl;
        else 
            fout << n << endl;
    }
    return 0;
}
