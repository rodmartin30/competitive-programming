#include <iostream>
#include <vector>
using namespace std;
int e1,a,n,t;
char e2,b;
vector<char> sal;
bool salida;
int tamano;
int main()
{

	cin >> t;
	for(int j = 0;j<t;j++)
	{
	salida = true;
	cin >> n;
	cin >> e1 >> e2;
	a = e1;
	b= e2;
	
	for(int i = 0;i<n-1;i++)
	{
		cin >> e1 >> e2;
		if(e1 == a || e2 == b)
		{
			
			salida = false;
		}
		a = e1;
		b=e2;
		
	
	}
	if(salida) cout << 'B' << endl;
	else cout << 'M' << endl;
	}
	
	return 0;
}	
