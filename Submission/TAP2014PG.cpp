#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int n,s,e,contador,german,gianina;
int e1,e2,e3,e4;
vector<int> entrada,entrada4;
vector<int> difPares,n4;
int cantidad,tamano,eComparacion;
bool entradasIguales=true;
bool diferenciasIguales=true;
int main()
{
	cin >> n;
	if(n==2)
	{
		cin >> e1 >> e2;
		if(e1 == e2)
		{
			cout << "-1" << endl;
			return 0;
		}
		else
		{
			cout << "0" << endl;
			return 0;

		}
	}
	else
	{
		if(n==4)
		{
			cin >> e1 >> e2 >> e3 >> e4;
			entrada4.push_back(e1);
			entrada4.push_back(e2);
			entrada4.push_back(e3);
			entrada4.push_back(e4);
			sort(entrada4.begin(),entrada4.end());
			reverse(entrada4.begin(),entrada4.end());
			n4.push_back(entrada4[0] - entrada4[1]);
			n4.push_back(entrada4[2] - entrada4[3]);
			sort(n4.begin(),n4.end());
			reverse(n4.begin(),n4.end());
			if(n4[0] == n4[1])
			{
				cout << "-1" << endl;
				return 0;
			}
			else
			{
				cout << "0" << endl;
				return 0;
			}

		}
	}
	cin >> e;
	eComparacion = e;
	entrada.push_back(e);
	for(int i =1;i<n;i++)
	{
		cin >> e;
		if(e != eComparacion)
		{
			entradasIguales = false;
		}
		entrada.push_back(e);


	}

	if(entradasIguales) cout << "-1" << endl;
	else
	{
		sort(entrada.begin(),entrada.end());
		reverse(entrada.begin(),entrada.end());
		for(int i =0;i<n;i+=2)
		{
			difPares.push_back(entrada[i]-entrada[i+1]);
		}
		sort(difPares.begin(),difPares.end());
		reverse(difPares.begin(),difPares.end());
		for(int i =0;i<n-1;i++)
		{
			
			if(difPares[i] != difPares[i+1]) 
			{
				
				diferenciasIguales = false;
				break;
			}
		}
		if(diferenciasIguales) cout << "0" << endl;
		else
		{
			for(int i=0;i<n/2;i++)
			{
				s=0;
				for(int k=0;k<=i;k++)
				{
					german += difPares[k];
				}
				for(int j=i+1;j<n/2;j++)
				{
					gianina += difPares[j];
					s++;
				}
				if(german>gianina)
				{
					cout << s << endl;
					break;
				}

			}

		}
		

	}
	
	


	return 0;

}
