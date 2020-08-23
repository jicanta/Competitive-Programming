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
#define esta(x,c) ((c).find(x) != (c).end())
 
const int MOD = 1e9+7;
const int MX = 10000+5;
const tint INF = 1e18;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	vector<pair<pi,int>> a;
	int x, y;
	int s = 0;
	while(cin >> x >> y){
		a.pb(mp(mp(x, y), s++));
	}
	int n = sz(a);
	vi dp (n, 1);
	vi pa (n, -1);
	sort(all(a));
	forn(i, n){
		forn(j, i){
			if(a[i].f.f > a[j].f.f && a[i].f.s < a[j].f.s){
				if(dp[j]+1 > dp[i]){
					dp[i] = dp[j]+1;
					pa[i] = j;
				}
			}
		}
	}
	int maxi = 0, fin;
	forn(i, n) if(dp[i] > maxi) maxi = dp[i], fin = i;
	cout << maxi << "\n";
	vi ret;
	while(fin != -1){
		ret.pb(a[fin].s);
		fin = pa[fin];
	}
	reverse(all(ret));
	for(auto u : ret) cout << u+1 << "\n";
}

