#include <bits/stdc++.h>
#include <math.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9
#define M 200010
#define S 200015
#define PI M_PI
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int tiros[S],hoyos[S];
vector<int> a,b,c;

typedef complex<double> base;
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}
void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n,m,tmp;
	a.resize(M); b.resize(M); c.resize(M);
	while(cin >> n) {
		
		fore(i,0,S)
			tiros[i] = hoyos[i] = 0;
		int res = 0;
		fore(i,0,n)
			cin >> tiros[i];
		
		cin >> m;
		
		fore(i,0,m) {
			cin >> tmp;
			hoyos[tmp] = 1;
		}
			
		fore(i,0,M)
			a[i] = b[i] = c[i] = 0;
		
		fore(i,0,n)
			a[tiros[i]] = b[tiros[i]] = 1;
			
		multiply(a,b,c);
	
		fore(i,0,n)
			c[tiros[i]] = 1;
		fore(i,0,S) {
			if(hoyos[i] && c[i])
				res++;
		}
		
		
		cout << res << endl;
	}

}
