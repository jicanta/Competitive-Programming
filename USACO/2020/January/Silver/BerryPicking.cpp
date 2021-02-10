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
const int MX = 2e5+5; 
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
 
void NACHO(string name = "berries"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	//Asumamos que Bessie recibe k/2 cestas
	//con a lo sumo M frutas.
	//Entonces, las k/2 que les damos a 
	//Elsie van a tener exactamente M frutas
	//Ej: 2 3 / 3 3
	//Obviamente no vamos a querer darle de mas a Elsie
	
	int n, k; cin >> n >> k;
	vi a (n);
	forn(i, n) cin >> a[i];
	int ret = 0;
	forsn(M, 1, 1002){
		vi quan (1002, 0);
		forn(i, n){
			quan[M] += a[i]/M;
			++quan[a[i] % M];
		}
		if(quan[M] < k/2) continue;
		quan[M] -= k/2;
		int act = k/2;
		int curRet = 0;
		for(int i = M; i >= 0 && act > 0; --i){
			curRet += min(act, quan[i])*i;
			act -= min(act, quan[i]);
		}
		if(act > 0) curRet = 0;
		ret = max(ret, curRet);
	}
	cout << ret << "\n";
}

