#include <iostream>
#include <cstdio>
using namespace std;

int f91(int n)
{
	if(n<=100)
		return f91(f91(n+11));
	else
		return n-10;
}
int main()
{
	int k;
	while(cin >> k && k!=0)
		cout << "f91(" << k <<") = " << f91(k) << endl;
}
