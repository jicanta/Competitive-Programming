#include <bits/stdc++.h>
 
using namespace std;
 
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
using vpi = vector<pi>;
using vvi = vector<vi>;
using vl = vector<tint>;
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
const int MX = 505; 
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
 
void NACHO(string name = "family"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

string a, b;
map<string, vector<string>> adj;
map<string, vector<string>> ADJ;
map<string, string> mom;
bool ok = false;
bool fin = false;

void dfs(string node, string ma, int d = -2){
	if(node == b){
		ok = true;
		cout << a << " is the ";
		F0R(i, d){
			cout << "great-";
		}
		cout << (d >= 0 ? "grand-mother" : "mother") << " of " << b << "\n";
		fin = true;
		return;
	}
	trav(u, adj[node]){
		if(u != ma){
			dfs(u, node, d+1);
		}
	}
}

void dfs2(string node, string ma){
	if(node == b){
		ok = true;
	}
	trav(u, ADJ[node]){
		if(u != ma){
			dfs2(u, node);
		}
	}
}

int main(){
	NACHO();
	int n; cin >> n >> a >> b;
	F0R(i, n){
		string u, v; cin >> u >> v;
		adj[u].push_back(v);
		ADJ[u].push_back(v);
		ADJ[v].push_back(u);
		mom[v] = u;
	}
	if(mom[a] == mom[b]){
		cout << "SIBLINGS\n";
		return 0;
	}
	dfs(a, a);
	if(fin) return 0;
	dfs2(a, a);
	if(!ok){
		cout << "NOT RELATED\n";
		return 0;
	}
	cout << "BB is the great-aunt of AA";
}



