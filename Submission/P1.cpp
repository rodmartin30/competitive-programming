#include <iostream>

using namespace std;
int n,s,max;
int main()
{
	cin >> n >> s;
	int sugar[n][2]
	for(int I = 0; I < n ; I++)
	{
		cin >> sugar[I][0] >> sugar[I][1];
	}
	for(int I = 0; I < n ; I++)
	{
		while(s>sugar[I][0])
		{
			if(max < 100 - sugar[I][1])
			{
				max = 100 - sugar[I][1];
			}
			sugar[I][0] = sugar[I][0]*2 + ((sugar[I][1]*2)/100);
			if(sugar[I][1] > 49)
			{
			
				sugar[I][1] = sugar[I][1]*2 - 100;
			}
			else
			{	
				sugar[I][1] = sugar[I][1]*2;
			}
		}
	}
	

	return 0;
}
