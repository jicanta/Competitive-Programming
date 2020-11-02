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
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 3e5+5;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "puesto"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

tint st[4*MX];

void build(int node, int tl, int tr){
	if(tl == tr) st[node] = 0;
	else{
		int tm = (tl+tr)/2;
		build(2*node, tl, tm);
		build(2*node+1, tm+1, tr);
		st[node] = st[2*node]+st[2*node+1];
	}
}

tint query(int node, int tl, int tr, int l, int r){
	if(l > r) return 0;
	if(l == tl && r == tr) return st[node];
	int tm = (tl+tr)/2;
	return query(2*node, tl, tm, l, min(r, tm))+query(2*node+1, tm+1, tr, max(l, tm+1), r);
}

void update(int node, int tl, int tr, int pos, int val){
	if(tl == tr) st[node]+=val;
	else{
		int tm = (tl+tr)/2;
		if(pos <= tm) update(2*node, tl, tm, pos, val);
		else update(2*node+1, tm+1, tr, pos, val);
		st[node] = st[2*node]+st[2*node+1];
	}
}

void make_distinct(vi &a){
	vector<pi> pos;
	vi contra (sz(a));
	set<pi> neg;
	forn(i, sz(a)){
		if(a[i] < 0) neg.insert(mp(a[i],i));
	}
	forn(i, sz(a)){
		if(a[i] > 0){
			pos.pb(mp(a[i],i));
			auto it = neg.lower_bound(mp(-a[i], -INF));
			contra[it->s] = i;
			neg.erase(it);
		}
	}
	sort(all(pos));
	vi posta (sz(a), -1);
	forn(i, sz(pos)){
		if(pos[i].f != i+1){
			posta[pos[i].s] = i+1;
		}
	}
	forn(i, sz(a)){
		if(a[i] > 0 && posta[i] != -1){
			a[i] = posta[i];
		}
	}
	forn(i, sz(a)){
		if(a[i] < 0){
			a[i] = -a[contra[i]];
		}
	}
}

long long count_swaps(std::vector<int> S){
	int n = sz(S);
	build(1, 0, 2*n-1);
	vi code (MX);
	int st = 0;
	make_distinct(S);
	vector<bool> seen (MX, 0);
	forn(i, n){
		if(!seen[abs(S[i])]){
			code[abs(S[i])] = 2*st;
			seen[abs(S[i])] = 1;
			++st;
		}
	}
	forn(i, n){
		if(S[i] > 0) S[i] = code[S[i]]+1;
		else S[i] = code[-S[i]];
	}
	tint ret = 0;
	forn(i, n){
		ret+=query(1, 0, 2*n-1, S[i], 2*n-1);
		update(1, 0, 2*n-1, S[i], 1);
	}
	return ret;
}
