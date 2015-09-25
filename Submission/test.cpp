#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<int> m,p,seq;
int c,k,mcs,salida,aux;
bool bandera;
int bs(int L, int num)
{
	int mx = L+1;
	int mn = 0;
	while(mx-mn>1)
	{
		int mid = (mx+mn) /2;
		if(seq[m[mid]]<num)
		mn = mid;
		else
		mx = mid;
	}
	return mn;
}
vector<int> lis()
{
	int n = seq.size(), L = 0;
	m.resize(n+1);
	m[0] = -1;
	p.resize(n);
	for(int i =0;i<n; i++)
	{
		
		int j = bs(L,seq[i]);
		p[i] = m[j];
		if(j==L || seq[i]<seq[m[j+1]]) 
		{
			m[j+1] = i ;
			L = max(L, j+1);
		}
	}
	vector<int> res;
	int t = m[L];
	
	while(t!=-1)
	{
		res.push_back(seq[t]);
		t = p[t];
	}
	reverse(res.begin(),res.end());
	return res;
}
int main()
{
	bandera = true;
	cin >> c >> k;
	
	for(int i = 0;i<k;i++)
	{
		seq.clear();
		m.clear();
		p.clear();
		
		for(int j = 0;j<c; j++)
		{
			cin >>aux;
			seq.push_back(aux); 
		}
		mcs = lis().size();
		if(bandera) salida = mcs;
		bandera = false;
		if(salida < mcs) salida = mcs;
		
	}
	cout << salida;
	
	return 0;
}







