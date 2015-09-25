#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a;i<n;i++)
#define mp make_pair

using namespace std;

typedef long long ll;
ll barrio[100005];
map<ll,int> esta;

set<pair<ll,ll> > par;
int main() {
  ios_base::sync_with_stdio(false);
  ll n,f,a,b,c,q,casa,equipo,reloj,creloj;
  cin >> n >> f;

  cin >> a >> b >> c;
  barrio[1] = a;
  esta[a]++;
  par.insert(mp(a,1));
  fore(i,2,n+1) {
    ll tmp = b * barrio[i-1] + c;
    barrio[i] = tmp % f;
    esta[barrio[i]]++;
    par.insert(mp(barrio[i],i));
  }

  cin >> q;

  fore(i,0,q) {
    cin >> casa >> equipo;
    //cout << esta[barrio[casa]] << " <--" << endl;
    esta[barrio[casa]]--;
    if(esta[equipo]) {
      pair<ll,ll> p = mp(barrio[casa],casa);
      par.erase(p);
      p = mp(equipo,casa);
      barrio[casa] = equipo;
      par.insert(p);
      set<pair<ll,ll> >::iterator mn,mx,it,mnit,mxit,tmp;
      /*for(it = par.begin();it != par.end();it++)
	 cout << "--> " << (*it).first << " " << (*it).second << endl;*/
      it = par.find(p);
      /*tmp = it;
      tmp--;
      cout << " ---> " << (*tmp).first << " " << (*tmp).second << endl;*/
      tmp = it;
      tmp--;
      
      if(it != par.begin() && (*tmp).first == equipo)
	mn = tmp;
      else
	mn = it;

      tmp = it;
      tmp++;

      if(it != par.end() && tmp != par.end() && (*tmp).first == equipo)
	mx = tmp;
      else
	mx = it;

      mnit = par.lower_bound(mp(equipo,0)); mnit;
      mxit = par.lower_bound(mp(equipo,n+1)); mxit--;
      //cout << (*mn).second << " -- " << (*mx).second << endl;
      if(mn != it)
	creloj = casa - (*mn).second;
      else {
	//cout <<  (*mxit).second << endl;
	creloj = n - (*mxit).second + casa;
      }

      if(mx != it)
	reloj = (*mx).second - casa;
      else
	reloj = n - casa + (*mnit).second;
      
      cout << creloj << " " << reloj << endl;
    }
    else {
      par.erase(mp(barrio[casa],casa));
      par.insert(mp(equipo,casa));
      barrio[casa] = equipo;
      cout << n << " " << n << endl;
    }
    esta[equipo]++;



  }
  
}

