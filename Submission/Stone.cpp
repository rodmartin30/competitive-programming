#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,total,temp,temp2;
vector<int> input;
int f(int y,vector<int> xs)
{
	if(xs.empty())
	{
		if(total-y >= y) return (total-y) - y;
		else return y - (total - y);
	}
	temp2 = xs.back();
	xs.pop_back();
	return min(f(y,xs),f(y+temp2,xs));
	
}
int g(int y,vector<int> xs)
{
	temp2 = xs.back();
	xs.pop_back();
 	return f(y+temp2,xs);
}

int main()
{
	cin >> n;
	for(int i =0;i<n ;i++)
	{
		cin >> temp;
		input.push_back(temp);
		total +=temp;
	}
	cout << g(0,input) << endl;

}
