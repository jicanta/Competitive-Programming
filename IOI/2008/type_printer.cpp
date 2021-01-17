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
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int t[600000][26];
bool fin[600000];
bool visited[600000];
vector<char> ret;
int tam[600000];
int d[600000];

int m = 1;

void insert(const string &s){
	int u = 0;
	trav(ch, s){
		if(t[u][ch-'a'] == 0) t[u][ch-'a'] = m++;
		u = t[u][ch-'a'];
	} 
	fin[u] = 1;
}

void calc_tams(int node){
	tam[node] = 1;
	F0R(i, 26){
		if(t[node][i] != 0){
			d[t[node][i]] = d[node]+1;
			calc_tams(t[node][i]);
			tam[node] = max(tam[node], d[t[node][i]]);
			tam[node] = max(tam[node], tam[t[node][i]]);
		}
	}
}

void dfs(int node, char a){
	if(node > 0) ret.pb(a);
	set<pi> s;
	if(fin[node]){
		ret.pb('P');
	}
	F0R(i, 26){
		if(t[node][i] != 0){
			s.ins(mp(tam[t[node][i]], i));
		}
	}
	for(auto i : s){
		dfs(t[node][i.s], (char)(i.s+'a'));
	}
	ret.pb('-');
}

int main(){
	NACHO();
	// te armas el trie
	// luego, recorres el trie como si fuera un dfs
	// siempre tocas la letra que corresponde a tu nodo actual
	// si en tu nodo actual termina una palabra, tocas 'P'
	// luego, vas a ir tocando '-' a medida que subis en el trie
	// como pueden quedar caracteres al final, recorres los nodos en orden
	// segun el largo de las strings que salen de ese nodo
	int n; cin >> n;
	F0R(i, n){
		string s; cin >> s;
		insert(s);
	}
	string rett = "";
	int no = 0;
	calc_tams(0);
	dfs(no, ' ');
	while(ret.back() == '-') ret.pop_back();
	cout << sz(ret) << "\n";
	trav(u, ret){
		cout << u << "\n";
	}
}



