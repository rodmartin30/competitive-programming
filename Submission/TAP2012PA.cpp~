#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n,aux;
bool s,o;
vector<int> ent;
int main()
{	
	scanf("%d",&n);
	while(n!= -1)
	{
		s=true;
		ent.clear();
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",&aux);
			ent.push_back(aux);
			if(aux>i)
			{
				s=false;
				
			}			
		}
		if(s)
		{
			for(int i = 1;i<=n;i++)
			{
				
				if(i==ent[i-1])
				{
					
					ent[i-1] = 0;
					for(int j =1;j<i;j++)
					{
						ent[j-1] +=1;
						if(ent[j-1]>j)
						{
							s=false;
							break;
						}
					}
					ent[0] = 0;
					
					i=1;
					if(!s) break;
					
				}
				
				
			}			
			
		}
		if(s)
		{
			for(int i = 0; i<n;i++)
			{
				if(ent[i]!=0) 
				{
					s=false;
					break;
				}
			}
		}
		
		if(s) printf("S\n");
		else printf("N\n");

		scanf("%d",&n);
	}


	return 0;
}
