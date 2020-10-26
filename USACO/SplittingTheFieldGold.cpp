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
const ld PI = acos(ld(-1)); 

void NACHO(string name = "split"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct pt{
	tint x, y;
};

tint areaNS(vector<pt> &a){
	tint maxX = -INF, maxY = -INF, minX = INF, minY = INF;
	forn(i, sz(a)){
		maxX = max(maxX, a[i].x);
		minX = min(minX, a[i].x);
		maxY = max(maxY, a[i].y);
		minY = min(minY, a[i].y);
	}
	return (maxX-minX)*(maxY-minY);
}

int main(){
	NACHO();
	int n; cin >> n;
	vector<pt> a (n);
	forn(i, n) cin >> a[i].x >> a[i].y;
	//Calculo area si cubro con uno solo
	tint area1 = areaNS(a);
	//Ahora, hago lo siguiente. Dividir los puntos en dos es equivalente
	//a tirar una recta vertical y calcular p cada lado cual es el minimo
	//area que los cubra a todos.
	//Hago lo mismo pero con lineas horizontales
	sort(all(a), [&](const pt &a, const pt &b){
		return a.x < b.x;
	});
	vi maxXP (n, -INF), maxYP (n, -INF), minXP (n, INF), minYP (n, INF);
	vi maxXS (n, -INF), maxYS (n, -INF), minXS (n, INF), minYS (n, -INF);
	tint maxX = -INF, maxY = -INF, minX = INF, minY = INF;
	forn(i, n){
		maxX = max(maxX, a[i].x);
		minX = min(minX, a[i].x);
		maxY = max(maxY, a[i].y);
		minY = min(minY, a[i].y);
		maxXP[i] = maxX;
		maxYP[i] = maxY;
		minXP[i] = minX;
		minYP[i] = minY;
	}
	maxX = -INF, maxY = -INF, minX = INF, minY = INF;
	for(int i = n-1; i >= 0; i--){
		maxX = max(maxX, a[i].x);
		minX = min(minX, a[i].x);
		maxY = max(maxY, a[i].y);
		minY = min(minY, a[i].y);
		maxXS[i] = maxX;
		maxYS[i] = maxY;
		minXS[i] = minX;
		minYS[i] = minY;
	}
	tint area2 = INF;
	forn(i, n-1){
		tint areaAct = (maxXP[i]-minXP[i])*(maxYP[i]-minYP[i])+(maxXS[i+1]-minXS[i+1])*(maxYS[i+1]-minYS[i+1]);
		area2 = min(area2, areaAct);
	}
	sort(all(a), [&](const pt &a, const pt &b){
		return a.y < b.y;
	});
	maxXP.clear(); maxYP.clear(); minXP.clear(); minYP.clear();
	maxXS.clear(); maxYS.clear(); minXS.clear(); minYS.clear();
	maxXP.rsz(n, -INF), maxYP.rsz(n, -INF), minXP.rsz(n, INF), minYP.rsz(n, INF);
	maxXS.rsz(n, -INF), maxYS.rsz(n, -INF), minXS.rsz(n, INF), minYS.rsz(n, -INF);
	maxX = -INF, maxY = -INF, minX = INF, minY = INF;
	forn(i, n){
		maxX = max(maxX, a[i].x);
		minX = min(minX, a[i].x);
		maxY = max(maxY, a[i].y);
		minY = min(minY, a[i].y);
		maxXP[i] = maxX;
		maxYP[i] = maxY;
		minXP[i] = minX;
		minYP[i] = minY;
	}
	maxX = -INF, maxY = -INF, minX = INF, minY = INF;
	for(int i = n-1; i >= 0; i--){
		maxX = max(maxX, a[i].x);
		minX = min(minX, a[i].x);
		maxY = max(maxY, a[i].y);
		minY = min(minY, a[i].y);
		maxXS[i] = maxX;
		maxYS[i] = maxY;
		minXS[i] = minX;
		minYS[i] = minY;
	}
	tint area3 = INF;
	forn(i, n-1){
		tint areaAct = (maxXP[i]-minXP[i])*(maxYP[i]-minYP[i])+(maxXS[i+1]-minXS[i+1])*(maxYS[i+1]-minYS[i+1]);
		area3 = min(area3, areaAct);
	}
	cout << area1-min({area2, area3, area1}) << "\n";
}
