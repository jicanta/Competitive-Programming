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
const int MX = 1e6+5;
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

tint pot[MX];

int main(){
    NACHO();
    // la idea es basicamente contar cuantas strings balanceadas hay
    // lexicograficamente menores que la string dada.
    // para ello, supongamos que tenemos el prefijo LPPLP....
    // si queremos ver cuales son menores, pero manteniendo el prefijo LPPL,
    // debemos cambiar la P final por una L, y ver cuantas palabras hay de la forma
    // LPPLL.....
    // esto ultimo sale con cuentitas analizando bien los casos.
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int cur = 0, maxi = 0, mini = 0;
    pot[0] = 1;
    FOR(i, 1, n+1) pot[i] = (pot[i-1]*2)%m;
    tint ret = 0;
    F0R(i, n){
		int k = n-i-1;
		if(s[i] == 'L'){
			++cur;
			ckmax(maxi, cur); ckmin(mini, cur);
		}else{
			if(max(maxi, cur+1)-min(mini, cur+1) > 2){ --cur; continue; }
			// cambio esta P por L
			if(max(maxi, cur+1)-min(mini, cur+1) == 2){
				if(max(maxi, cur+1) == cur+1 || min(mini, cur+1) == cur+1){
					ret = (ret+pot[k/2]) % m;
				}else ret = (ret+pot[k/2+k%2]) % m;
			}else{
				ret = (ret+pot[k/2]+pot[k/2+k%2]-1) % m;
			}
			--cur;
			ckmax(maxi, cur); ckmin(mini, cur);
		}
	}
	cout << (ret+1) % m << "\n";
}

