#include <stdio.h>
#include <vector>
using namespace std;
int cantidad,n;
vector <int> numeros(170000,0);
vector<int> primos,entrada;
int cribaEratostenes()
{
    
    for(int i = 2;i<412;i++)
    {
        
        for(int j=i+i;j<170000;j+=i) 
        {
            numeros[j] = 1;
        }
        
        
    }
    return 0;
}
void ponerPrimos()
{
    int t = 0;
    for(int i =2;i<170000;i++)
    {
        if(numeros[i]==0)
        {
            primos.push_back(i);
        }
    }
}
int main()
{
    cribaEratostenes();
    ponerPrimos();
    scanf("%d",&cantidad);
    for(int i=0;i<cantidad;i++)
    {
        scanf("%d",&n);
        entrada.push_back(n);
    }
    for(int i=0;i<entrada.size();i++)
    {
        printf("%d\n",primos[entrada[i]-1]);
    }
    
    return 0;
}

