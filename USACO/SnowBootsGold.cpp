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
const tint mod = 998244353;
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
 
 bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "snowboots"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct tile{
	int d, id;
	bool operator<(const tile &a)const{
		return d < a.d;
	}
};

struct boot{
	int d, k, id;
	bool operator<(const boot &a)const{
		return d < a.d;
	}
};

int main(){
	NACHO();
	int n, m; cin >> n >> m;
	vector<tile> tiles (n); vector<boot> boots (m);
	forn(i, n){ cin >> tiles[i].d; tiles[i].id = i; }
	forn(i, m){ cin >> boots[i].d >> boots[i].k; boots[i].id = i;  }
	sort(all(tiles));
	sort(rall(boots));
	
	vi pre (n), nxt (n);
	forsn(i, 1, n-1){
		pre[i] = i-1;
		nxt[i] = i+1;
	}
	int curMax = 1;
	vi ret (m);
	forn(i, m){
		int d = boots[i].d, k = boots[i].k, id = boots[i].id;
		while(!tiles.empty() && tiles.back().d > d){
			nxt[pre[tiles.back().id]]=nxt[tiles.back().id];
			pre[nxt[tiles.back().id]]=pre[tiles.back().id];
			curMax = max(curMax, nxt[tiles.back().id]-pre[tiles.back().id]);
			tiles.pop_back();
		}
		if(k >= curMax) ret[id] = 1;
		else ret[id] = 0;
 	}
 	forn(i, m){
		cout << ret[i] << "\n";
	}
}
