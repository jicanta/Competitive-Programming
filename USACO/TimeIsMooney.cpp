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
const int MX = 5e5+5;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "time"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}
 
int main(){
	NACHO();
	int n, m, C;
	cin >> n >> m >> C;
	vi val (n);
	forn(i, n) cin >> val[i];
	vector<vi> adj (n);
	forn(i, m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[v].pb(u);
	}
	vector<vi> dp (n, vi (2005, -INF));
	dp[0][0] = 0;	
	forsn(t, 1, 2005){
		forn(i, n){
			for(auto u : adj[i]){
				dp[i][t] = max(dp[i][t], dp[u][t-1]+val[i]);
			}
		}
	}
	int maxi = -INF;
	forsn(i, 1, 2005){
		maxi = max(maxi, dp[0][i]-(C*i*i));
	}
	cout << maxi << "\n";
}

