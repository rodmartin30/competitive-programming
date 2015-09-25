#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,g,e1,e2,indice;
vector<int> dif;
int puntos;
int main()
{
	while(cin >> n >> g)
	{
		dif.clear();
		indice=0;
		puntos=0;
		for(int i =0;i<n;i++)
		{
			cin >> e1 >> e2;
			if(e1 > e2) puntos += 3;
			else dif.push_back(e2-e1);
		}
		sort(dif.begin(),dif.end());
		
		for(int i=g;(i>0) && (dif.size() != 0) && (indice < dif.size());i--)
		{
			dif[indice] -= 1;
			if(dif[indice] <0)
			{
				indice++;
				puntos+=3;

			}
		}
		for(int i =0;i<dif.size()&& dif.size() != 0 && indice < dif.size();i++)
		{
			if(dif[i]==0) puntos+=1;
		}
	

	cout << puntos << endl;
	

	}



	return 0;
}
