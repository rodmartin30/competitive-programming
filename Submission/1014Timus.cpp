#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int n,s;
int main()
{
	cin >> n;
	s=n;
	if(n<1)for(int i =1;i>n;i--) s+=i;
	else for(int i=1;i<n;i++) s+=i;
	cout << s << endl;

}
