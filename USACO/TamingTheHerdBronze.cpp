#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,tint>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vl = vector<tint>;
using vb = vector<bool>;

#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert

#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int mod = 998244353;
const int MX = 205; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "taming"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n; cin >> n;
	vi a (n);
	F0R(i, n) cin >> a[i];
	bool ok = 1;
	int last = 0;
	vb mark (n, 0);
	vb mark2 (n, 0);
	// primero, es facil ver cuando es -1
	// si no es -1, p el minimo haces lo siguiente:
	// primero, marcas todas las casillas que si o si tienen q tener.
	// Luego, el minimo es la cantidad de numero marcados, ya
	// que siempre podes dirigir a los -1 de tal forma
	// que no agreguen mas casillas.
	// para el maximo, es similar, pero ahora hay que ver cuando podemos
	// transformar un -1 en 0.
	// mark2 me dice si es posible transformar
	// un -1 en 0. Esto es posible
	// si no existe uno mas adelante que me manda mas para atras
	mark[0] = 1;
	F0R(i, n){
		if(a[i] != -1 && i-a[i] < last) ok = 0;
		if(a[i] != -1){
			last = i-a[i];
		}
	}
	if(!ok){
		cout << -1 << "\n";
		return 0;
	}
	F0R(i, n){
		if(a[i] != -1) mark[i-a[i]] = 1;
	}
	int mini = 0, maxi = 0;
	F0R(i, n) if(mark[i]) ++mini;
	maxi = mini;
	int pri = inf;
	R0F(i, n){
		if(a[i] != -1) pri = min(pri, i-a[i]);
		else{
			if(pri > i) mark2[i] = 1;
		}
	}
	F0R(i, n) if(!mark[i] && mark2[i] == 1 && a[i] == -1) ++maxi;
	cout << mini << " " << maxi << "\n";
}

