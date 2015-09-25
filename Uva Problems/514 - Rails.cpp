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


int main()
{
    ifstream fin ("test.in");
    ofstream fout ("test.out");
    
    int n,s,temp,contador;
    vector<int> trenE,trenS,tren;
    stack<int> pila;
    bool yes = true;
    while(cin >> n && n != 0)
    {
        while(cin >> s && s!=0)
        {
            contador = 0;
            temp = n;
            tren.clear();
            trenE.clear();
            trenS.clear();
            trenE.push_back(s);
            yes = true;
            
            while(--temp && cin >> s)
                trenE.push_back(s);
                
            for(int i =1;i<=n;i++)
                tren.push_back(i);
                
            for(int i=0;i<trenE.size();i++)
            {
                while(contador<n)
                {
                    if(trenE[i]<tren[contador])
                    {
                        if(!pila.empty())
                        {
                            trenS.push_back(pila.top());
                            pila.pop();
                            break;
                        }
                    }
                    else
                    {    
                        if(tren[contador] == trenE[i])
                        {
                            trenS.push_back(trenE[i]);
                            contador++;
                            break;
                        }
                        else
                            pila.push(tren[contador]);
                        
                        contador++;
                    
                    }
                }
            }
            while(!pila.empty())
            {
                trenS.push_back(pila.top());
                pila.pop();
            }
            
            for(int i =0;i<n;i++)
                if(trenE[i] != trenS[i])
                    yes = false;
                
            if(yes)
                printf("Yes\n");
            else
                printf("No\n");
        }
        cout << endl;
    }
    
}
