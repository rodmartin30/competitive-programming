#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,total,temp,diferencia,t;
vector<int> entrada,pila;
int main()
{
	cin >> n;
	for(int i =0;i<n;i++)
	{
		cin >> temp;
		entrada.push_back(temp);
		total += temp;
	}
	for(int i=0;i<n;i++)
	{
		temp =0;
		for(int j=i;j<n;j++)
		{
			temp += entrada[j];
			cout << temp << endl;
			if(total-temp >= temp)
			{
				diferencia = (total-temp)-temp;
			}			
			else 
			{
			
				diferencia = temp - (total-temp);
			}
			pila.push_back(diferencia);
		}
	}
	

	
	t = pila.size();
	cout << "Con sort" << endl;
	for(int i =0;i<t;i++) cout << pila[i] << endl;
}
