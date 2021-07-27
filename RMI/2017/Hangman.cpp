#include <bits/stdc++.h>
 
using namespace std;
 
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
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
using vl = vector<tint>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vvi = vector<vi>;
using vvl = vector<vl>;
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
const int MX = 3e4+5;
const tint INF = 1e18; 
const int inf = 1e9;
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

string a[MX];
bool good[MX];
tint pw1[MX], pw2[MX];
vl hsh1[MX], hsh2[MX];

const int P = 9973, M = 1e9+9;

void calc_hash(int id, string& a){
	hsh1[id][0] = hsh2[id][0] = 1;
	FOR(i, 1, sz(a)+1){
		hsh1[id][i] = ((hsh1[id][i-1] * P) % MOD + a[i-1]) % MOD;
		hsh2[id][i] = ((hsh2[id][i-1] * P) % M + a[i-1]) % M;
	}
}

int main(){
	NACHO();
	// el hecho de que nos den cota sobre el producto de N y K y no sobre N y K en si, 
	// sugiere que vamos a tener dos algoritmos distintos.
	// O(N^2*K) u O(N*K^2), segun cual entre.
	// el N^2*K es facil, para cada par de strings, vemos en cuantas posiciones difieren.
	// para el N*K^2, probamos sacar todo par (i, j) de letras y con hashing vemos que strings quedan iguales.
	pw1[0] = pw2[0] = 1;
	FOR(i, 1, MX) pw1[i] = pw1[i-1] * P % MOD, pw2[i] = pw2[i-1] * P % M;
	int tc; cin >> tc;
	while(tc--){
		int n, k; cin >> n >> k;
		F0R(i, n) good[i] = 1;
		F0R(i, n) cin >> a[i];
		if(n*n*k <= n*k*k){
			F0R(i, n){
				FOR(j, i+1, n){
					int cnt = 0;
					F0R(l, k) cnt += (a[i][l] != a[j][l]);
					if(cnt <= 2) good[i] = good[j] = 0;
				}
			}
			F0R(i, n) cout << 1-good[i];
			cout << "\n";
		}else{
			F0R(i, n) hsh1[i].clear(), hsh1[i].rsz(k+1);
			F0R(i, n) hsh2[i].clear(), hsh2[i].rsz(k+1);
			F0R(i, n) good[i] = 1;
			F0R(i, n) calc_hash(i, a[i]);
			vector<pair<pl, int>> hashes;
			F0R(i, k){
				FOR(j, i+1, k){
					hashes.clear();
					F0R(l, n){
						tint curHsh1 = (hsh1[l][k]-pw1[k-i-1]*a[l][i]-pw1[k-j-1]*a[l][j]) % MOD;
						tint curHsh2 = (hsh2[l][k]-pw2[k-i-1]*a[l][i]-pw2[k-j-1]*a[l][j]) % M;  
						hashes.pb(mp(mp(curHsh1, curHsh2), l));
					}					
					sort(all(hashes));
					F0R(l, n-1){
						if(hashes[l].f.f == hashes[l+1].f.f && hashes[l].f.s == hashes[l+1].f.s){
							good[hashes[l].s] = 0;
							good[hashes[l+1].s] = 0;
						}
					}
				}
			}
			F0R(i, k){
				hashes.clear();
				F0R(l, n){
					tint curHsh1 = (hsh1[l][k]-pw1[k-i-1]*a[l][i]) % MOD;
					tint curHsh2 = (hsh2[l][k]-pw2[k-i-1]*a[l][i]) % M;  
					hashes.pb(mp(mp(curHsh1, curHsh2), l));
				}					
				sort(all(hashes));
				F0R(l, n-1){
					if(hashes[l].f.f == hashes[l+1].f.f && hashes[l].f.s == hashes[l+1].f.s){
						good[hashes[l].s] = 0;
						good[hashes[l+1].s] = 0;
					}
				}
			}
			F0R(i, n) cout << 1-good[i];
			cout << "\n";
		}
	}
}

