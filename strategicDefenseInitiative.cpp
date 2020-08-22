#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const tint MOD = 1e9+7;
const int MX = 3e5+5;
const int INF = 1e9;
const long double PI = acos((-1)); 
 
void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	while(tc--){
		string act;
		vi a;
		while(getline(cin, act) && act != ""){
			a.pb(stoi(act));
		}
		int n = sz(a);
		vi dp (MX, INF);
		vi id (MX);
		vi pa (MX, -1);
		int lis = 0, fin;
		forn(i, n){
			int it = lower_bound(all(dp), a[i])-dp.begin();
			dp[it] = a[i];
			id[it] = i;
			pa[i] = it > 0 ? id[it-1] : -1;
			if(it+1 > lis){
				fin = i;
				lis = it+1;
			}
		}
		vi ret;
		while(fin != -1){
			ret.pb(a[fin]);
			fin = pa[fin];
		}
		reverse(all(ret));
		cout << "Max hits: " << lis << "\n";
		forn(i, sz(ret)) cout << ret[i] << "\n";
		if(tc > 0)cout << "\n";
	}
}

