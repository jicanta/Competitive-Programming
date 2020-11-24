#include <bits/stdc++.h>
#include <traffic.h>
 
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
const int MX = 1e6+5; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
template<class T> bool valid(T x, T y, T n, T m){
    return (0<=x && x<n && 0<=y && y<m);
}

int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "cbarn"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

vi adj[MX];
int dp[MX];
int val[MX];
int sum = 0;
int best = inf;
int ret;

void dfs(int node, int pa){
	int sumSon = 0;
	int maxi = 0;
	trav(u, adj[node]){
		if(u != pa){
			sumSon+=val[u];
			dfs(u, node);
			maxi = max(maxi, val[u]+dp[u]);
			sumSon+=dp[u];
			dp[node]+=val[u]+dp[u];
		}
	}
	int dad = sum-sumSon-val[node];
	maxi = max(maxi, dad);
	if(maxi < best){
		best = maxi;
		ret = node;
	}
}

int LocateCentre(int n, int p[], int d[], int s[]){
	forn(i, n) val[i] = p[i], sum+=val[i];
	forn(i, n-1){
		adj[d[i]].pb(s[i]);
		adj[s[i]].pb(d[i]);
	}
	dfs(0, -1);
	return ret;
}
/*
int main(){
	NACHO();
	int n; cin >> n;
	int p[n], d[n], s[n];
	forn(i, n){
		cin >> p[i];
	}
	forn(i, n-1) cin >> d[i] >> s[i];
	cout << LocateCentre(n, p, d, s) << endl;
}


5
10 10 10 20 20
1 2
2 3
3 4
0 2
*/

