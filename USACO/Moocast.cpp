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
const int MX = 1000005;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "moocast"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct cow{
	int x, y, p;
};

int main(){
	NACHO();
	function<int(cow, cow)> dist = [&](cow a, cow b){
		return abs(a.x-b.x)*abs(a.x-b.x)+abs(a.y-b.y)*abs(a.y-b.y);
	};
	int n; cin >> n;
	vector<cow> a (n);
	forn(i, n) cin >> a[i].x >> a[i].y >> a[i].p;
	vector<vi> adj (n);
	forn(i, n){
		forn(j, n){
			if(dist(a[i], a[j]) <= a[i].p*a[i].p){
				adj[i].pb(j);
			}
		}
	}
	int maxi = -INF;
	int c = 0;
	vector<bool> visited (n, 0);
	function<void(int)> dfs = [&](int node){
		visited[node] = 1;
		++c;
		for(auto u : adj[node]){
			if(!visited[u]) dfs(u);
		}
	};
	forn(i, n){
		visited.clear();
		visited.rsz(n, 0);
		c = 0;
		dfs(i);
		maxi = max(maxi, c);
	}
	cout << maxi << "\n";
}
