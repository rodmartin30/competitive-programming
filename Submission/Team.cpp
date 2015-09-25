#include <iostream>

using namespace std;

int n,s,a1,a2,a3;

int main()
{

 	cin >> n;
	for(int i = 0;i<n;i++)
	{
		cin >> a1 >> a2 >> a3;
		if((a1 == 1 && a2 == 1) || (a1 == 1 && a3 == 1) || (a2 == 1 && a3 == 1)) s++;
		a1 = a2 = a3 = 0;
	}
	cout << s;
	return 0;
}
