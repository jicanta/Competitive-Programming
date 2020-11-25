#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define trav(a, x) for(auto& a : x)
 
using vi = vector<int>;
using vl = vector<tint>;
using vb = vector<bool>;
#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert
#define esta(x,c) ((c).find(x) != (c).end())
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const tint mod = 998244353;
const int MX = 1e6+5; 
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
 
void NACHO(string name = "meetings"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}
struct cow{
	tint w, x, d;
	bool operator<(const cow &o)const{ return x < o.x; }
};

int main(){
	NACHO();
	tint n, L; cin >> n >> L;
	vector<cow> a (n);
	forn(i, n) cin >> a[i].w >> a[i].x >> a[i].d;
	//Primero, calcula T
	//Lo que haces es esto:
	//Sea z la cantidad de vacas con velocidad -1
	//Las primeras z vacas (de izq a derecha) van a terminar en el establo
	//de la izquierda. Las demas en el de la derecha.
	//Sin embargo, las vacas que terminan en el establo de la izquierda
	//van a tardar en total lo mismo que tardarian
	//las vacas con velocidad -1 si fueran a la izquierda.
	//Luego, para cada vaca calculas cual es el tiempo que le lleva ir 
	//a su establo correspondiente.
	//Las ordenas por tiempo de menor a mayor y en caso de empate por mayor peso.
	//Asi calculas T facil.
	tint cowsL = 0;
	sort(all(a));
	forn(i, n) if(a[i].d == -1) ++cowsL;
	vector<pl> times;
	vector<cow> cowsMinus1;
	vector<cow> cowsPlus1;
	forn(i, n) if(a[i].d == -1) cowsMinus1.pb(a[i]);
	forn(i, n) if(a[i].d == 1) cowsPlus1.pb(a[i]);
	forn(i, cowsL){
		times.pb(mp(cowsMinus1[i].x, a[i].w));
	}
	forsn(i, cowsL, n){
		times.pb(mp(L-cowsPlus1[i-cowsL].x, a[i].w));
	}
	sort(all(times), [&](const pi &a, const pi &b){
		if(a.f == b.f) return a.s > b.s;
		return a.f < b.f;
	});
	tint T = 0;
	tint curW = 0;
	tint totW = 0;
	forn(i, n) totW+=a[i].w;
	forn(i, n){
		curW+=times[i].s;
		if(2*curW >= totW){
			T = times[i].f;
			break;
		}
	}
	//para calcular cuantos encuentros hay
	//pienso a cada vaca con el intervalo [x-T, x] o [x, x+T]
	//entonces una vaca con velocidad 1 se choca con una con velocidad -1
	//si xi+2T >= xj
	int ans = 0;
	queue<int> curPlus1;
	forn(i, n){
		if(a[i].d == -1){
			while(!curPlus1.empty() && curPlus1.front()+2*T < a[i].x){
				curPlus1.pop();
			}
			ans+=sz(curPlus1);
		}else curPlus1.push(a[i].x);
	}
	cout << ans << "\n";
}
