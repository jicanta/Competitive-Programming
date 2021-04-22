#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vpi = vector<pi>;
using vpl = vector<pl>;
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
const int MX = 20000005;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-5;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
	sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; 
} 
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; 
}
 
bool valid(int x, int y, int n, int m){
	return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = ""){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}
 
// la solucion trivial es para cada objeto meter k individuales, y 
// luego correr knpascak normal. Sin embargo, hay 10^5 objetos y j <= 10^9.
// esto no es feasible.
// lo que queremos es basicamente descomponer el k en grupos de ese mismo
// objeto tal que con estos grupos puedo formar todas las sumas
// entre 1 y k y tal que la cantidad de grupos es chica.
// hacemos lo siguiente: vamos haciendo grupos de tamaño 2^0, 2^1, 2^2, hasta que
// no podamos seguir restando. A lo último metemos en un grupo lo que sobro.
// es obvio que podemos crear todas las sumas entre 1 y k con esto, y a su vez,
// hay logk grupos por cada objeto.
// sin embargo, esto no alcanza para llegar a 100.
// lo que tenemos que hacer es ver que para cada peso x,
// solo nos interesa ver los W/x items con mayor valor (ya que no puedo meter mas de W/x en la bolsa de capacidad W).
// Como los pesos van hasta 2000, la cantidad de items es a lo sumo 2000/1+2000/2+2000/3+2000/4...=17000 aprox.
// Esto ya da 100.
 
struct Item{
	tint v, w, k;
};
 
tint dp[2005];
vector<Item> items;
vpi ge[2005];
 
int main(){
	NACHO();
	tint n, w; cin >> w >> n;
	F0R(i, n){
		tint v, w, k; cin >> v >> w >> k;
		ge[w].pb(mp(v, k));
	}
	FOR(i, 1, 2005){
		sort(rall(ge[i]));
		int quan = w/i;
		F0R(j, sz(ge[i])){
			while(ge[i][j].s > 0 && quan > 0){
				--ge[i][j].s;
				--quan;
				items.pb({ge[i][j].f, i, 1});
			}
		}
	}
	F0R(i, sz(items)){
		R0F(j, w){
			if(j+items[i].k*items[i].w <= w) ckmax(dp[j+items[i].k*items[i].w], dp[j]+items[i].k*items[i].v);
		}
	}
	cout << dp[w] << "\n";
}

