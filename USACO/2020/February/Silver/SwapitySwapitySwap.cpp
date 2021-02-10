#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,int>;
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
const tint mod = 998244353;
const int MX = 1e5+5; 
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
 
void NACHO(string name = "swap"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int succ[MX];
vi cyc[MX];
int pos_cyc[MX];
int pa[MX];
bool visited[MX];

int main(){
	NACHO();
	// primero, armamos el hgrafo funcional 
	// en el que mando una arista de i
	// a la posicion que va a parar i luego de una
	// iteracion.
	// descompongo al grafo en ciclos.
	// para cada i, la respuesta
	// va a ser la posicion numero tam(ciclo_i) mod K del ciclo_i
	// por cuestiones implementativas (i.e. evitar el O(n^2))
	// me guardo para cada ciclo el representante de este ciclo
	// y la posicion de cada numero de este ciclo en este ciclo
	int n, m, k; cin >> n >> m >> k;
	vi a (n);
	iota(all(a), 1);
	F0R(i, m){
		int l, r; cin >> l >> r;
		--l, --r;
		FOR(j, l, (l+r)/2+((l+r) % 2 == 1)){
			swap(a[j], a[r-j+l]);
		}
	}
	F0R(i, n){
		succ[i+1] = a[i];
	}
	F0R(i, n){
		if(!visited[i+1]){
			visited[i+1] = 1;
			cyc[i+1].pb(i+1);
			pos_cyc[i+1] = 0;
			int j = succ[i+1];
			int pos = 1;
			pa[i+1] = i+1;
			while(j != i+1){
				visited[j] = 1;
				pos_cyc[j] = pos;
				++pos;
				cyc[i+1].pb(j);
				pa[j] = i+1;
				j = succ[j];
			}
		}
	}
	F0R(i, n){
		cout << cyc[pa[i+1]][(pos_cyc[i+1]+k) % sz(cyc[pa[i+1]])] << "\n";
	}
}
