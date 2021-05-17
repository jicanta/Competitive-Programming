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
 
void NACHO(string name = "cardgame"){
	ios_base::sync_with_stdio(0); cin.tie(0);
   // freopen((name+".in").c_str(), "r", stdin);
   // freopen((name+".out").c_str(), "w", stdout);
}
 
int main(){
	NACHO();
	int n; cin >> n;
	vector<ld> a (MX, -inf), b (MX, -inf);
	forn(i, n) cin >> a[i] >> b[i];
	sort(rall(a)); sort(rall(b));
	int pa = 0, pb = 0;
	ld sa = 0.0, sb = 0.0;
	ld ret = 0.0;
	while(pa <= n && pb <= n){
		//cout << sa << " " << sb << endl;
		if(sb < sa){
			sb += b[pb];
			++pb;
		}else{
			sa += a[pa];
			++pa;
		}
		ret = max(ret, min(sa-pa-pb, sb-pa-pb));
	}
	cout << fixed << setprecision(4) << ret << "\n";
}
//OVERFLOW!
//COTAS?
//CHEQUEA LAS CUENTAS
