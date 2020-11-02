#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (tint)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;

const int MOD = 1e9+7; //998244353;
const int MX = 3e5+5;	
const int INF = 1e9;	
const ld PI = acos((ld)-1);	
const ld EPS = 1e-9;
 
void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

int st[4*MX];
tint fact[MX];

void fill(int n){ fact[0] = 1; forsn(i, 1, n+1) fact[i] = fact[i-1] * i % MOD; }

void update(int node, int tl, int tr, int pos, int add){
	if(tl == tr) st[node] = add;
	else{
		int tm = (tl+tr)/2;
		if(pos <= tm) update(2*node, tl, tm, pos, add);
		else update(2*node+1, tm+1, tr, pos, add);
		st[node] = st[2*node]+st[2*node+1];
	}
}

int query(int node, int tl, int tr, int l, int r){
	if(l > r) return 0;
	if(l == tl && tr == r) return st[node]; 
	int tm = (tl+tr)/2;
	return query(2*node, tl, tm, l, min(r, tm))+query(2*node+1, tm+1, tr, max(l, tm+1), r);
}

int main(){
	NACHO();
	int n;
	cin >> n;
	vi a (n);
	fill(n);
	forn(i, n) cin >> a[i];
	vi c = a;
	sort(all(c));
	map<int,int> code;
	forn(i, n){
		if(code.count(c[i]) == 0) code[c[i]] = sz(code);
	}
	forn(i, n) a[i] = code[a[i]];
	reverse(all(a));
	tint ret = 0;
	forn(i, n){
		ret+=fact[i]*query(1, 0, n-1, 0, a[i]) % MOD;
		update(1, 0, n-1, a[i], 1);
	}
	cout << ((ret+1%MOD)+MOD)%MOD << "\n";
}

