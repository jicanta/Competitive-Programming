#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 1e6;
const int MOD = 1e9+7;

vector<int> adj[10001];
int ind[10001];
bool visited[10001];

void dfs(int node){
	visited[node] = 1;
	for(auto u : adj[node]){
		if(!visited[u]){
			dfs(u);
		}
	}
}

int main(){
	NACHO;
	ifstream cin("arbol.in");
	ofstream cout("arbol.out");
	int n, m; cin >> n >> m;
	forn(i, m){
		int u, v; cin >> u >> v;
		u--;v--;
		adj[u].push_back(v);
		ind[v]++;
	}
	vector<int> roots;
	vector<bool> isRoot(n, 0);
	forn(i, n){
		if(ind[i] == 0){
			isRoot[i] = 1;
			roots.push_back(i+1);
		}
	}
	vector<int> cond2;
	forn(i, n){
		if(!isRoot[i] && ind[i] != 1){
			cond2.push_back(i+1);
		}
	}
	if(int(roots.size()) == 1){
		dfs(roots[0]-1);
		bool ok = 1;
		vector<int> unvi;
		forn(i, n) if(!visited[i]){ ok = 0; unvi.push_back(i+1);}
		if(ok && int(cond2.size() == 0)){
			cout << "Si" << " " << roots[0] << "\n";
			return 0;
		}else cout << "No" << "\n";
		cout << roots[0] << "\n";
		if(int(cond2.size()) == 0){
			cout << 0 << "\n";
		}else{
			for(auto u : cond2) cout << u << " ";
			cout << "\n";
		}
		if(int(unvi.size()) == 0){
			cout << 0 << "\n";
		}else{
			for(auto u : unvi) cout << u << " ";
		}
	}else{
		cout << "No" << "\n";
		if(int(roots.size()) == 0){
			cout << 0 << "\n";
		}else{
			for(auto u : roots) cout << u << " ";
			cout << "\n";
		}
		if(int(cond2.size()) == 0){
			cout << 0 << "\n";
		}else{
			for(auto u : cond2) cout << u << " ";
			cout << "\n";
		}
		cout << 0 << "\n";
	}
}
