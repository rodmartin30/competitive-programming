#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;


int n,m0,m1,m2,m3,m4,m5,m6,s;
vector<int> entrada;
vector<char> salida,vsalida;
int tamano;
int casos;


int main()
{
	cin >> casos;
	for(int l =0;l<casos;l++)
	{
		salida.clear();
		cin >> n;
		m0 = n%3;
		m1 = n%9;
		m2 = n%27;
		m3 = n%81;
		m4 = n%243;
		m5 = n%(729);
		m6 = n%(2187);



		// 3 a la 6
		if((m6>1822 && m6<2187) || (m6>-1 && m6<365)) salida.push_back('0');
		else
		{
			if(m6>364 && m6<1094) salida.push_back('+');
			else salida.push_back('-');
		}
		// 3 a la 5
		if((m5>607 && m5<729) || (m5>-1 && m5<122)) salida.push_back('0');
		else
		{
			if(m5>121 && m5<365) salida.push_back('+');
			else salida.push_back('-');
		}	
		// 3 a la 4
		if((m4>202 && m4<243) || (m4>-1 && m4<40)) salida.push_back('0');
		else
		{
			if(m4>40 && m4<122) salida.push_back('+');
			else salida.push_back('-');
		}
		// 3 a la 3
		if((m3>67 && m3<81) || (m3>-1 && m3<14)) salida.push_back('0');
		else
		{
			if(m3>13 && m3<41) salida.push_back('+');
			else salida.push_back('-');
		}
		// 3 a la 2
		if((m2>22 && m2<27) || (m2>-1 && m2<5)) salida.push_back('0');
		else
		{
			if(m2>4 && m2<14) salida.push_back('+');
			else salida.push_back('-');
		}
		//3 a la 1
		if((m1>-1 && m1<2) || m1==8) salida.push_back('0');
		else
		{
			if(m1>1 && m1<5) salida.push_back('+');
			else salida.push_back('-');
		}
		// 3 a la 0
		if(m0==1) salida.push_back('+');
		else
		{
			if(m0==2) salida.push_back('-');
			else salida.push_back('0');
		}
	
		tamano = salida.size();
		
		for(int i =0;i<tamano;i++)
		{
			s=0;
			if(salida[i]!='0') 
			{
				s=i;
				break;
			}
		}
		for(int i =s;i<tamano;i++)
		{
			printf("%c",salida[i]);
		}
		printf ("\n");

	}
	return 0;

}
