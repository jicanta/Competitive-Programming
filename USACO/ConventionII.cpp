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
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1e5+5;
const tint INF = 1e18;
const int inf = 2e9;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "convention2"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct cow{
	int a, t, id;
};

bool cmp(const cow &a, const cow &b){ return a.id < b.id; }

int main(){
	NACHO();
	int n; cin >> n;
	vector<cow> a (3*n+1);
	forn(i, n){ cin >> a[i].a >> a[i].t; a[i].id = i; }
	forsn(j, n, 3*n){
		a[j] = {inf, 0, inf};
	}
	a[3*n] = {inf, 0, inf};
	sort(all(a), [&](const cow &a, const cow &b){
		return a.a < b.a;
	});
	int fin = 0;
	set<cow, bool(*)(const cow&,const cow&)> s (cmp);
	int ret = 0;
	fin = a[0].a+a[0].t;
	forsn(i, 1, 3*n){
		while(a[i].a > fin && !s.empty()){
			auto beg = *s.begin();
			ret = max(ret, max(1,fin-beg.a));
			fin=max(beg.a, fin)+beg.t;
			s.erase(beg);
		}
		s.insert(a[i]);
	}
	cout << ret << "\n";
}
