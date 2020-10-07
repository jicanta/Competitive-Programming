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
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1e5+5;
const tint INF = 1e18;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "milkvisits"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

vi parent (MX), size (MX);

void init(int n){
	forn(i, n) parent[i] = i, size[i] = 1;
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void unite(int a, int b){
	a = find(a), b = find(b);
	if(a != b){
		if(size[a] < size[b]) swap(a, b);
		parent[b] = a;
		size[a]+=size[b];
	}
}

int main(){
	NACHO();
	int n, q;
	cin >> n >> q;
	init(n);
	vector<char> type (n);
	forn(i, n) cin >> type[i];
	forn(i, n-1){
		int u, v;
		cin >> u >> v;
		--u, --v;
		if(type[u] == type[v]) unite(u, v);
	}
	string ret = "";
	forn(i, q){
		int u, v; char c;
		cin >> u >> v >> c;
		--u, --v;
		if(type[u] == c || type[v] == c) ret+='1';
		else if(find(u) != find(v)) ret+='1';
		else ret+='0';
	}
	cout << ret << "\n";
}
