#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(tint i = s; i < tint(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (tint)(x).size()
 
using pi = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const tint MOD = 1e9+7;
const tint MX = 3e5+5;
const tint INF = 1e18;
const long double PI = acos((-1)); 
 
void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
   //freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	tint x;
	vi a;
	while(cin >> x){
		a.pb(x);
	}
	vi dp (MX, INF);
	vi id (MX);
	vi pa (MX);
	tint lis = 0, fin;
	forn(i, sz(a)){
		tint it = lower_bound(all(dp), a[i])-dp.begin();
		dp[it] = a[i];
		id[it] = i;
		pa[i] = it > 0 ? id[it-1] : -1;
		if(it+1 > lis){
			lis = it+1;
			fin = i;
		}
	}
	vi ret;
	while(fin != -1){
		ret.pb(a[fin]);
		fin = pa[fin];
	}
	reverse(all(ret));
	cout << lis << "\n";
	cout << '-' << "\n";
	for(auto u : ret){
		cout << u << "\n";
	}
}

