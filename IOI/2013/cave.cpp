#include <bits/stdc++.h>
#include "cave.h"
 
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
 
void exploreCave(int N) {
    // para cada puerta, veo cual la abre y en qué posicion.
    // esta mal intentar para cada switch cual puerta abre, es mas facil 
    // lo primero.
    // ahora bien, supongamos que estamos intentando abrir la puerta i.
    // claramente ya sabemos como abrir hasta la puerta i-1
    // ahora, hago busqueda binaria sobre el switch que abre la puerta i.
    // prendo todos los switchs. Luego apago un prefijo. Si estaba encendida y ahora no,
    // el switch esta en el prefijo. Si estaba encendida y ahora tmb, no esta en el prefijo (esta en el sufijo).
    // los otros casos son analogos.
    // Hacemos n*log n queries = 65000 aprox
    int s[N], state[N];
    int cur[N];
    bool fix[N];
    F0R(i, N) cur[i] = 1;
    F0R(i, N) fix[i] = 0;
    F0R(i, N){
		int low = -1, high = N;
		F0R(j, N) if(!fix[j]) cur[j] = 1;
		int c = tryCombination(cur);
		bool can = (c < 0 || c > i);
		int col = (can ? 1 : 0);
		while(high-low > 1){
			int mid = low+(high-low)/2;
			F0R(i, mid+1){
				if(!fix[i]) cur[i] = col;
			}
			FOR(i, mid+1, N){
				if(!fix[i]) cur[i] = 1-col;
			}
			int cc = tryCombination(cur);
			bool cann = (cc < 0 || cc > i);
			if(cann) high = mid;
			else low = mid;
		}
		fix[high] = 1;
		s[high] = i;
		cur[high] = col;
		state[high] = col;
	}
    answer(state, s);
}
