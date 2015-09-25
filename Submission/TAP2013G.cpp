#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int s,aux,w;
bool t;
vector<int> n,q;

int main()
{
	scanf("%d",&s);
	for(int i = 0;i<s;i++)
	{
		scanf("%d",&aux);
		q.push_back(aux);
	}
	for(int i = 0;i<s;i++)
	{
		scanf("%d",&aux);
		n.push_back(aux);
	}
	
	sort(n.begin(),n.end());
	sort(q.begin(),q.end());
	for(int i =0;i<s;i++)
	{
		if(n[i]>q[0]) 
		{	
			q.erase(q.begin());
			w++;
		}
	}
	printf("%d \n",w);





	return 0;
}