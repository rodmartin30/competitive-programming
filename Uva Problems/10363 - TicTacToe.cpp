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
char tablero[3][3];

bool compare(int f1,int c1, int f2,int c2, int f3,int c3,char c)
{
    bool comp = false;
    if(tablero[f1][c1] == tablero[f2][c2] && tablero[f2][c2]  == tablero[f3][c3] && tablero[f3][c3] == c )
        comp = true;
    
    return comp;
}
int main()
{
    ofstream fout ("word.out");
    ifstream fin ("word.in");
    
	int n;
	int tatetiX, tatetiO,x,o;
    cin >> n;
    bool yes;
    while(n--)
    {
        yes = true;
        tatetiX = tatetiO = x = o = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                cin >> tablero[i][j];
                if(tablero[i][j] == 'X')
                    x++;
                else
                    if(tablero[i][j] == 'O')
                        o++;
            }
        
        for(int i=0;i<3;i++)
        {
            if(compare(i,0,i,1,i,2,'X'))
                tatetiX++;
            if(compare(i,0,i,1,i,2,'O'))
                tatetiO++;
        }
        for(int i=0;i<3;i++)
        {
            if(compare(0,i,1,i,2,i,'O'))
                tatetiO++;
            if(compare(0,i,1,i,2,i,'X'))
                tatetiX++;
        }
        
        if(compare(0,0,1,1,2,2,'X'))
            tatetiX++;
        if(compare(0,0,1,1,2,2,'O'))
            tatetiO++;
        if(compare(0,2,1,1,2,0,'X'))
            tatetiX++;
        if(compare(0,2,1,1,2,0,'O'))
            tatetiO++;
        
        if(tatetiX+tatetiO>1 || o>x || x-o>1)
        {
            if(tatetiX==2 && x==5 && o==4)
            {
                yes=true;
            }
            else
            {
                yes=false;
            }
        }
        else
        {
            if(tatetiX+tatetiO==1)
            {
                if(tatetiX==1)
                {
                    if(x-o==1)
                        yes = true;
                    else
                        yes = false;
                }
                else
                {
                    if(x == o)
                        yes = true;
                    else
                        yes = false;
                }
            }
            else
            {
                if(x-o==1 || x-o == 0)
                    yes = true;
                else
                    yes = false;
            }
        }
        
        if(yes)
            cout << "yes" << endl;
        else
            cout << "no" << endl; 
    }
}
