#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1e5+5;
const tint INF = 1e18;
const int inf = 2e9;
const int OFF = 1e4;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "triangles"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct pt{
	tint x, y, id;
};

tint retY[MX], retX[MX];

void calc(vector<pi> &cur, bool type){
	tint ret = 0;
	if(sz(cur) <= 1) return;
	sort(all(cur));
	forsn(i, 1, sz(cur)){
		ret+=cur[i].f-cur[0].f;
	}
	if(type){
		retY[cur[0].s] = ret;
	}else retX[cur[0].s] = ret;
	forsn(i, 1, sz(cur)){
		if(type){
			retY[cur[i].s] = retY[cur[i-1].s]-(sz(cur)-2*i)*(cur[i].f-cur[i-1].f) % MOD;
		}else{
			retX[cur[i].s] = retX[cur[i-1].s]-(sz(cur)-2*i)*(cur[i].f-cur[i-1].f) % MOD;
		}
	}
}

int main(){
	NACHO();
	int n; cin >> n;
	vector<pt> a (n);
	//pensa que si vas por todas las rectas horizontales de arriba p abajo,
	//podes considerar a todos los puntos en esa recta con los puntos en los extremos.
	forn(i, n){
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	vector<vector<pi>> X (2*OFF+5);
	vector<vector<pi>> Y (2*OFF+5);
	forn(i, n){
		X[a[i].x+OFF].pb(mp(a[i].y, a[i].id));
		Y[a[i].y+OFF].pb(mp(a[i].x, a[i].id));
	}
	forn(i, 2*OFF+5){
		calc(Y[i], 1);
		calc(X[i], 0);
	}
	tint ret = 0;
	forn(i, n){
		ret = (ret+retX[a[i].id]*retY[a[i].id]) % MOD;
	}
	cout << ret << "\n";
}
