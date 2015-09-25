#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdio>
using namespace std;
double a;
vector<double> salida;
int main()
{
	while(scanf("%lf",&a) != EOF)
	{
		salida.push_back(a);
	}
	for(int i=salida.size()-1;i>=0;i--) printf("%.4lf\n", sqrt(salida[i]));
	
	

}
