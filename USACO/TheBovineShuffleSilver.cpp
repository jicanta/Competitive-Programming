#include <bits/stdc++.h>
 
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
const int mod = 998244353;
const int MX = 1e5+5; 
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
 
void NACHO(string name = "shuffle"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

vi p, s;

int find(int a){
	if(a == p[a]) return a;
	return p[a] = find(p[a]);
}

void unite(int a, int b){
	a = find(a), b = find(b);
	if(a != b){
		if(s[a] < s[b]) swap(a, b);
		p[b] = a;
		s[a]+=s[b];
	}
}

vi P;
vb visited;
int ret = 0;

void dfs(int node){
	int A = P[node], B = P[P[node]];
	while(A != B){
		A = P[A];
		B = P[P[B]];
	}
	A = node;
	while(A != B){
		A = P[A];
		B = P[B];
	}
	do{
		++ret;
		A = P[A];
	}while(A != B);
}
 
int main(){
	//la respuesta es la cantidad de nodos en un ciclo
	NACHO();
	int n; cin >> n;
	p.rsz(n); s.rsz(n, 1);
	forn(i, n) p[i] = i;
	P.rsz(n); visited.rsz(n, 0);
	forn(i, n){ cin >> P[i]; unite(i, P[i]-1); unite(P[i]-1, i);}
	trav(a, P) --a;
	set<int> bad;
	forn(i, n) if(bad.count(find(i)) == 0){ dfs(i); bad.insert(find(i));}
	cout << ret << "\n";
}
