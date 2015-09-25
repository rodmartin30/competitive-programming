#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
string s,t;
int kmp_table[2];

void fill_table()
{
	int pos = 2;
	int cnd = 0;
	kmp_table[0] = -1;
	kmp_table[1] = 0;
	while(pos<s.size())
	{
		if(s[pos-1] == s[cnd]) kmp_table[pos++] = (++cnd);
		else if(cnd>0) cnd = kmp_table[cnd];
		else kmp_table[pos++] = 0;
	}
}
int kmp(){
	fill_table();
	int m=0;
	int i =0;
	while(m +i<t.size())
	{
		if(s[i] == t[m+i])
		{
			if(i==s.size()-1)
			return m;
			i++;
		}
		else
		{
			m = m + i - kmp_table[i];
			if (kmp_table[i]>-1) i = kmp_table[i];
			else i = 0;
		}
	}
	return -1;
	}
int main()
{
	
	t= "Hola";
	s = "Ho";
	cout << kmp() << endl;
	




}
