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
 
using pi = pair<ld,ld>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 2e5+5;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

vi parent (MX), size (MX);

void init(int n){
	forn(i, n){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int x){
	if(x == parent[x]){
		return x;
	}
	return parent[x] = find(parent[x]);
}

void unite(int a, int b){
	a = find(a), b = find(b);
	if(a != b){
		if(size[a] < size[b]) swap(a, b);
		parent[b] = a;
		size[a]+=size[b];
	}
}

ld dist(ld x1, ld y1, ld x2, ld y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

struct edge{
	int u, v; ld w;
};
 
int main(){
	NACHO();
	int tc;
	cin >> tc;
	while(tc--){
		cin.ignore();
		int n; cin >> n;
		vector<pi> a (n);
		forn(i, n){
			ld x, y;
			cin >> x >> y;
			a[i] = mp(x, y);
		}
		vector<edge> edges;
		forn(i, n){
			forn(j, i){
				edges.pb({i, j, dist(a[i].f, a[i].s, a[j].f, a[j].s)});
			}
		}
		init(n*n+5);
		sort(all(edges), [&](const edge &a, const edge &b){
			return a.w < b.w;
		});
		ld cost = 0.0;
		for(auto e : edges){
			int u = e.u, v = e.v;
			if(find(u) != find(v)){
				cost+=e.w;
				unite(u, v);
			}
		}
		cout << fixed << setprecision(2) << cost << "\n";
		if(tc > 0)cout << "\n";
	}
}

