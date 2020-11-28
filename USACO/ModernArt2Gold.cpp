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
 
void NACHO(string name = "art2"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	//la respuesta es la maxima cantidad de intervalos
	//totalmente contenidos dentro de otro
	//No sé cuando no se puede qaq
	//Edit: no se puede cuando se intersecan y no estan totalmente contenidos
	int n; cin >> n;
	vi a (n);
	forn(i, n) cin >> a[i];
	vector<pi> seq (n, mp(-1, -1));
	vi L (n+1, inf), R (n+1, -inf);
	vector<pi> ran;
	forn(i, n){
		L[a[i]] = min(i, L[a[i]]);
		R[a[i]] = max(i, R[a[i]]);
	}
	forsn(i, 1, n+1){
		ran.pb(mp(L[i], R[i]));
	}
	sort(all(ran));
	bool ok = 1;
	set<int> close;
	forn(i, n){
		auto it = close.lower_bound(ran[i].f);
		if(it == close.end()){
			close.ins(ran[i].s);
			continue;
		}
		if(*it <= ran[i].s){
			ok = 0;
		}
		close.ins(ran[i].s);
	}
	if(!ok){
		cout << -1 << "\n";
		return 0;
	}
	forsn(i, 1, n+1){
		if(L[i] == inf) continue;
		seq[R[i]].s = 1, seq[L[i]].f = 1;
	}
	int ret = 0;
	int cur = 0;
	forn(i, n){
		//cout << seq[i] << " ";
		if(seq[i].f == 1) ++cur;
		ret = max(ret, cur);
		if(seq[i].s == 1) --cur;
	}
	cout << ret << "\n";
}
