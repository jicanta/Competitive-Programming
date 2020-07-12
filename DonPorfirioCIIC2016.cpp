#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
#define dbg cout << "hu" << endl;
 
const int INF = 1100000000;
const tint MOD = 1000000007;
const int N = 300001;

int parent[N]; tint size[N];

struct edge{
	int u, v, w; 
	bool operator<(const edge &o) const{
		return w < o.w;
	}
};

void fill(){
	forn(i, N){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int x){
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void unite(int a, int b){
	a = find(a); b = find(b);
	if(a != b){
		if(size[a] < size[b]) swap(a,b);
		parent[b] = a;
		size[a]+=size[b];
	}
}

int main(){
	NACHO;
	fill();
	int n; cin >> n;
	vector<edge> a (n-1);
	forn(i, n-1){
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		a[i] = {u,v,w};
	}
	sort(all(a));
	tint ret = 0;
	forn(i, n-1){
		int u = a[i].u, v = a[i].v, w = a[i].w;
		tint iniA = (size[find(u)]*(size[find(u)]-1)/2), iniB = (size[find(v)]*(size[find(v)]-1)/2);
		unite(u, v);
		int pa = find(u);
		ret+=w*((size[pa]*(size[pa]-1)/2)-iniA-iniB);
		ret%=MOD;
	}
	cout << ((ret%MOD)+MOD)%MOD << "\n";
}


