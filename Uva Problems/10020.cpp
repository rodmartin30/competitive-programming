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
#include <fstream>
#include <cstring>
#include <bitset>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
for(int i=m;i<=n;i++)
#define T 1000005
#define M 9999999
#define ii pair<int,int>
using namespace std;

pair<int,int> seg[T],sol[T];

bool compare(pair<int,int> i,pair<int,int> j)
{
	if(i.first==j.first)
		return i.second>j.second;
	
	return i.first < j.first;
}
int main()
{
	
	int test,m,a,b,k,mx;
	bool blank=false;
	scanf("%d",&test);
	while(test--)
	{
		if(blank)
			printf("\n");
		blank=true;
		int k=0,h=0;
		bool flag=true;
		int max=-T,ind=-1;
		pair<int,int> tmp;
		scanf("%d",&m);
		while(scanf("%d %d",&a,&b) && (a!=0 || b!=0))
		{
			seg[k++] = make_pair(a,b);
		}
		
		sort(seg,seg+k,compare);
		fore(i,0,k)
		{
			if(seg[i].first>0)
				break;
			else if(seg[i].second>0)
				if(seg[i].second>max){
					max = seg[i].second;
					ind = i;
				}
		}
		sol[h++] = tmp = seg[ind];
		mx=0;
		int t=ind+1;
		if(ind!=-1){
			while(tmp.second <m && t<k)
			{
				if(tmp.second >= seg[t].first && seg[t].second >= m)
				{
					sol[h++] = tmp = seg[t];
				}
				else if(tmp.second >= seg[t].first)
				{
					if(tmp.second < seg[t].second && seg[t].second >mx)
					{
						ind =t;
						mx = seg[t].second;
					}
					t++;
				}
				else if(tmp.second < seg[t].first && tmp == seg[t-1])
				{
					break;
				}
				else
				{
					sol[h++] = tmp = seg[ind];
					mx = 0;
				}
			
			}
		}
		
		if(h<=0 || sol[h-1].second<m)
			flag = false;
		if(flag){
			printf("%d\n",h);
			fore(i,0,h)
				printf("%d %d\n",sol[i].first,sol[i].second);
		}
		else
			printf("0\n");
			
	}
}
