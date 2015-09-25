#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <utility>
#include <map>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#include <bitset>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
for(int i=m;i<=n;i++)
#define T 105
#define M 64
using namespace std;


pair<int,int> q;
vector<int> v;
int factorial(int n)
{
	int i=1;
	if(n==1)
		return 1;
	return n*factorial(n-1);
}
int query[T][3];
int main()
{
	//ofstream cout("t.txt");
	int n,m,a,b,sum;
	while(cin >> n >> m && n)
	{
		fore(i,0,m)
			cin >> query[i][0] >> query[i][1] >> query[i][2];
		
		int cant=0;
		v.clear();
		v.resize(n);
		fore(i,0,n)
			v[i] = i;
		
		do
		{
			sum=1;
			fore(i,0,m)
			{
				fore(j,0,n)
				{
					if(v[j]==query[i][0])
						a = j;
					else if(v[j]==query[i][1])
						b = j;
				}
			
				if(query[i][2]>0 && abs(a-b)>query[i][2])
				{
					sum=0;
					break;
				}
				if(sum && query[i][2]<0 && abs(a-b)<-query[i][2])
				{
					sum=0;
					break;
				}
			
			
			
			}
			cant+=sum;
		}
		while(next_permutation(v.begin(),v.end()));
		
		cout << cant << endl;				
			
	
		
	}
}	


