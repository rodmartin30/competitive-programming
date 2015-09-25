#include <iostream>
#include <utility>
#include <algorithm>
#define T 105
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
for(int i=m;i<=n;i++)

using namespace std;

char table[T][T];

int main()
{
	int n,m,s;
	string seq;
	pair<int,int> coor; char c;
	while(cin >> n >> m >> s && n+m+s!=0)
	{
		int cant = 0;
		fore(i,0,n)
			fore(j,0,m)
			{
				cin >> table[i][j];
				if(table[i][j] == 'N')
				{
					coor.first = i; coor.second = j; c= 'N';
				}
				else if(table[i][j] == 'S')
				{
					coor.first = i; coor.second = j; c= 'S';
				}
				else if(table[i][j] == 'L')
				{
					coor.first = i; coor.second = j; c= 'L';
				}
				else if(table[i][j] == 'O')
				{
					coor.first = i; coor.second = j; c= 'O';
				}
			}
			
		
		
		cin >> seq;
		/*cout << endl;
			fore(i,0,n)
			{
				fore(j,0,m)
					cout << table[i][j] << " ";
				cout << endl;
			}*/
		fore(i,0,seq.size())
		{
			if (seq[i] == 'F')
			{
				if(c=='N' && coor.first !=0 && table[coor.first-1][coor.second]!='#')
				{
					table[coor.first][coor.second]= '.';
					coor.first-=1;
					if(table[coor.first][coor.second]=='*')
						cant++;
					table[coor.first][coor.second]= 'N';
					
				}
				else if(c=='S' && coor.first !=n-1 && table[coor.first+1][coor.second]!='#')
				{
					table[coor.first][coor.second]= '.';
					coor.first+=1;
					if(table[coor.first][coor.second]=='*')
						cant++;
					table[coor.first][coor.second]= 'S';
				}
				else if(c=='L' && coor.second !=m-1 && table[coor.first][coor.second+1]!='#')
				{
					table[coor.first][coor.second]= '.';
					coor.second+=1;
					if(table[coor.first][coor.second]=='*')
						cant++;
					table[coor.first][coor.second]= 'L';
				}
				else if(c=='O' && coor.second !=0 && table[coor.first][coor.second-1]!='#')
				{
					table[coor.first][coor.second]= '.';
					coor.second-=1;
					if(table[coor.first][coor.second]=='*')
						cant++;
					table[coor.first][coor.second]= 'O';
					
				}
			}
			else if(seq[i]=='D')
			{
				if(c=='N')
					c='L';
				else if(c == 'L')
					c = 'S';
				else if(c== 'S')
					c = 'O';
				else if(c == 'O')
					c = 'N';
					
				table[coor.first][coor.second]= c;
			}
			else if(seq[i]=='E')
			{
				if(c=='N')
					c='O';
				else if(c == 'O')
					c = 'S';
				else if(c== 'S')
					c = 'L';
				else if(c == 'L')
					c = 'N';
				table[coor.first][coor.second]= c;
			}
			/*cout << endl;
			fore(i,0,n)
			{
				fore(j,0,m)
					cout << table[i][j] << " ";
				cout << endl;
			}*/
		}
		
		cout << cant << endl;
		
	}
}

