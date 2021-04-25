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
const int MX = 515;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
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
 
int main(){
	NACHO();
	// si podemos curbrirla con un radio r, tambien podemos
	// hacerlo con un radio r' > r. Esto sugiere busqueda binaria.
	// Un circulo puede cubriri un segmento de la linea (puede que no cubra nada).
	// Usando Pitagoras podemos encontrar para cada circunferencia
	// el segmento (l, r) que cubre de la linea.
	// Ahora, queremos ver si la union de estos segmentos cubre la linea entera.
	// para hacer esto, los ordenamos por l y vamos mergeando.
	// sin embargo ordenar es muy lento.
	// pero por propiedades de estos segmentos, no hace falta ordenarlos.
	int n; tint l; cin >> n >> l;
	vpl a (n);
	F0R(i, n) cin >> a[i].f >> a[i].s;
	double low = 0, high = double(5e9);
	F0R(assa, 50){
		double mid = low+(high-low)/2;
		vector<pair<double, double>> ran (n);
		F0R(i, n){
			// mid*mid = p.y*p.y+x*x
			double dist = sqrt(mid*mid-a[i].s*a[i].s);
			ran[i] = mp(a[i].f-dist, a[i].f+dist);
		}
		double ri = 0;
		F0R(i, n){
			if(ran[i].f <= ri) ri = max(ri, ran[i].s);
		}
		if(ri >= l) high = mid;
		else low = mid;
	}
	cout << fixed << setprecision(4) << high << "\n";
}
