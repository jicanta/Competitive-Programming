#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
 
using pi = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1000005;
const tint INF = 1e18+5;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "mountains"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	//Transformo c punto en el intervalo [x-y;x+y]
	//Entonces, no veo una montaña si está totalmente incluida en un intervalo
	int n; cin >> n;
	vector<pi> a (n);
	forn(i, n) cin >> a[i].f >> a[i].s;
	vector<pi> intervals (n);
	forn(i, n) intervals[i] = mp(a[i].f-a[i].s, a[i].f+a[i].s);
	sort(all(intervals), [&](const pi &a, const pi &b){
		if(a.f == b.f) return a.s > b.s;
		return a.f < b.f;
	});
	tint rightest = -INF;
	int tot = 0;
	forn(i, n){
		if(rightest >= intervals[i].s){
			++tot;
		}
		rightest = max(rightest, intervals[i].s);
	}
	cout << n-tot << "\n";
}
