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
    
    int n;
    string s;
    scanf("%d\n",&n);
    bool yes = true;
    
    while(n--)
    {
        stack<char> pila;
        yes = true;
        getline(cin,s);
        
        if(s.empty())
        {
            printf("Yes\n");
            continue;
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ')' || s[i] == ']')
            {
                if(pila.empty())
                {
                    yes = false;
                    break;
                }
                else
                {
                    if(s[i] == ')' && pila.top() != '(')
                    {
                        yes = false;
                        break;
                    }
                    else
                    {
                        if(s[i] == ']' && pila.top() != '[')
                        {
                            yes = false;
                            break;
                        }
                        else
                        {
                            pila.pop();
                        }
                    }
                }
            }
            else
            {
                pila.push(s[i]);
            }
        }
        
        if(yes && pila.empty())
            printf("Yes\n");
        else
            printf("No\n");
        
    }
    
}
