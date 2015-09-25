#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include <math.h>
#define T 1002

using namespace std;
string s;
int precio;

int main()
{
    
    
    char s[T];
    cin.getline (s, T);
    for(int i=0;i<T;i++)
    {
        if(s[i] == '\0') break;
        if(s[i] == ' ') precio++;
        else
        {        
            if(s[i] == ',') precio +=2;
            else
            {
                if(s[i] == '!') precio +=3;
                else
                {
                    if((s[i] - 'a')%3==0 ) precio++;
                    else
                    {
                        if(abs((s[i] - 'a')%3)==1 ) precio += 2;
                        else
                        {
                            if(abs((s[i] - 'a')%3)==2 ) precio+=3;
                        }
                    }
                }
            }
        }
    }

    
    cout << precio << endl;
}
