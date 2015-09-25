#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int n,k,aux;
int sum;
vector<int> floor;
int main()
{
	scanf("%d" "%d",&n,&k);
	for(int i =0;i<n;i++)
	{
		scanf("%d",&aux);
		floor.push_back(aux);

	}
	sort(floor.begin(),floor.end());
	reverse(floor.begin(),floor.end());
	if(n%k !=0)
	{
		
		for(int i =0;i<=n/k;i++)
		{
			sum += (floor[i*k] - 1);
		}
		sum = 2 * sum;
	}
	else
	{
	
		for(int i =0;i<n/k;i++)
		{
			sum += (floor[i*k] - 1);
		}
		sum = 2 * sum;
	

	}
	cout << sum << endl;


	return 0;
}

// LUCAS CRACK
