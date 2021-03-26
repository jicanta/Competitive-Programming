#include <bits/stdc++.h>
#include "gondola.h"
 
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
 
const int MOD = 1e9+9; //change this
const tint mod = 998244353;
const int MX = 5005;
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
 
int valid(int n, int b[])
{
	// si algun numero aparece dos veces, no se puede.
	// si hay dos numeros <= n (no se cambiaron), hay
	// que chequear que sean validos
	// si son todos >= n o todos excepto 1, no hay forma de verificar nada.
	vi id (n);
	vi a (n);
	F0R(i, n) a[i] = b[i];
	F0R(i, n) id[i] = i+1;
	set<int> c;
	F0R(i, n){
		if(c.count(a[i])) return 0;
		c.ins(a[i]);
	}
	int pos = -1;
	F0R(i, n) if(a[i] <= n) pos = i;
	if(pos == -1) return 1;
	rotate(id.begin(), id.begin()+a[pos]-1, id.end());
    rotate(a.begin(), a.begin()+pos, a.end());
	F0R(i, n) if(a[i] <= n && a[i] != id[i]) return 0;
	return 1;
}
 
//----------------------
 
int replacement(int n, int b[], int replacementSeq[])
{
	bool allG = 1;
	vi id (n);
	vi a (n);
	F0R(i, n) a[i] = b[i];
	F0R(i, n) id[i] = i+1;
	F0R(i, n) if(a[i] <= n) allG = 0;
	vi c (n);
	F0R(i, n) c[i] = a[i];
	if(allG){
		F0R(i, n) a[i] = i+1;
	}
	// uso el pivot para saber que gondola cambiada se corresponde
	// con que gondola original
	int pos;
	F0R(i, n) if(a[i] <= n) pos = i;
	rotate(id.begin(), id.begin()+a[pos]-1, id.end());
    rotate(a.begin(), a.begin()+pos, a.end());
    rotate(c.begin(), c.begin()+pos, c.end());
	vpi g;
	if(allG) F0R(i, n) a[i] = c[i];
	F0R(i, n){
		if(a[i] > n) g.pb(mp(a[i], i));
	}
	if(sz(g) == 0) return 0;
	sort(all(g));
	int ind = 0;
	set<int> av;
	FOR(i, n+1, 250005) av.ins(i);
	F0R(i, n) if(a[i] > n) av.erase(a[i]);
	F0R(i, sz(g)){
		int cur = id[g[i].s];
		while(cur < g[i].f){
			replacementSeq[ind] = cur;
			cur = *av.begin();
			av.erase(*av.begin());
			++ind;
		}
		av.ins(cur);
	}
	return ind;
}
 
//----------------------
 
struct mi {
 	int v; explicit operator int() const { return v; } 
	mi() { v = 0; }
	mi(tint _v):v(_v%MOD) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((tint)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, tint p) { assert(p >= 0); // asserts are important! 
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
 
int countReplacement(int n, int b[])
{
	if(!valid(n, b)) return 0;
	// sea maxi el maximo numero de gondola
	// claramente, tengo que insertar
	// todas las gondolas entre [n+1;maxi] para
	// llegar a maxi.
	// ahora, cuantas formas tengo de poner la gondola x?
	// puedo ponerla en la cantidad de lugares cuya gondola final
	// es mayor a x.
	// sin embargo, si vas de n+1 a maxi es a lo sumo 1e9, por lo cual esto 
	// no es viable.
	// lo que hay que notar es lo siguiente.
	// supongamos que tenemos ... ... ... 12 29 36
	// para todos los numeros entre [12;28], la respuesta es 2.
	// por lo tanto, no hace falta iterar poor todos ellos
	// ya que su respuesta es la misma (podemos hacer 2^(29-12).
	bool allG = 1;
	F0R(i, n) if(b[i] <= n) allG = 0;
	vi a;
	F0R(i, n){
		if(b[i] > n) a.pb(b[i]);
	}
	a.pb(n);
	sort(all(a));
	mi ret = 1;
	FOR(i, 1, sz(a)){
		ret *=  pow(mi(sz(a)-i), a[i]-a[i-1]-1);
		// resto 1 pq no cuento a a[i] ya que este tiene un lugar unico
		// al que ir.
	}
	if(allG) ret *= n;
	return int(ret);
}
