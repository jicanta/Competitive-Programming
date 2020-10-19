#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
using vb = vector<bool>;
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
const int MX = 5e5+5;
const tint INF = 1e18;
const int inf = 1e9;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "pairup"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n; cin >> n;
	vector<pi> a (n);
	forn(i, n) cin >> a[i].f >> a[i].s;
	sort(all(a), [&](const pi &a, const pi &b){
		return a.s < b.s;
	});
	int i = 0, j = n-1;
	tint maxi = 0;
	while(i <= j){
		maxi = max(maxi, a[i].s+a[j].s);
		if(a[i].f == a[j].f) ++i, --j;
		else if(a[i].f > a[j].f){ a[i].f-=a[j].f; --j;}
		else{ a[j].f-=a[i].f; ++i;}
	}
	cout << maxi << "\n";
}
