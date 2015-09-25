#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n,m,piso;
char aux;
double fichas,raiz;
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> aux;
			if(aux=='o')
			{
				fichas++;
			}
		}
	}
	
	raiz = sqrt(fichas);
	piso = floor(sqrt(fichas));
	if(raiz-piso==0 && fichas!=0 && fichas == raiz*raiz && raiz <= n && raiz<=m) cout << 1 << endl;
	else cout << 0 << endl;

}
