#include <bits/stdc++.h>
//#include <traffic.h>
 
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
const int M = 1e9+7;
const int MX = 1e3+5;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "parque"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct Point{
	tint id, x, y;
};

tint dist(Point &a, Point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))+2;
}

vi parent (MX);
vi tam (MX);

void fill(int n){
	forn(i, n){
		parent[i] = i;
		tam[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void unite(int a, int b){
	a = find(a), b = find(b);
	if(a != b){
		if(tam[a] < tam[b]) swap(a, b);
		parent[b] = a;
		tam[a]+=tam[b];
	}
}

int main(){
	NACHO();
	int n; cin >> n;
	vector<Point> a (n+1);
	forn(i, n) cin >> a[i].id >> a[i].x >> a[i].y;
	a[n] = {0, 0, 0};
	vector<Point> edge;
	forn(i, n+1){
		forsn(j, i+1, n+1){
			edge.pb({dist(a[i], a[j]), a[i].id, a[j].id});
		}
	}
	sort(all(edge), [&](const Point &a, const Point &b){
		return a.id < b.id;
	});
	fill(n+2);
	tint tot = 0;
	vector<vi> adj (n+1);
	forn(i, sz(edge)){
		int w = edge[i].id, u = edge[i].x, v = edge[i].y;
		int uu = u, vv = v;
		u = find(u), v = find(v);
		if(u != v){
			adj[uu].pb(vv);
			adj[vv].pb(uu);
			unite(u, v);
			tot+=w;
		}
	}
	cout << tot << "\n";
	sort(all(a), [&](const Point &a, const Point &b){
		return a.id < b.id;
	});
	forsn(i, 1, n+1){
		cout << a[i].id;
		for(auto u : adj[a[i].id]) cout << " " << u;
		cout << "\n";
	}
	
}

