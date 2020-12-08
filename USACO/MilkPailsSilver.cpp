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
const int MX = 105; 
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
 
void NACHO(string name = "pails"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

bool visited[MX][MX][MX];
int ret = inf;
int x, y, k, m;

void dfs(int X, int Y, int K){
	visited[X][Y][K] = 1;
	if(K == 0){
		ret = min(ret, abs(X+Y-m));
		return;
	}
	//lleno la de x
	if(!visited[x][Y][K-1]) dfs(x, Y, K-1);
	//lleno la de y
	if(!visited[X][y][K-1]) dfs(X, y, K-1);
	//vacio la de x
	if(!visited[0][Y][K-1]) dfs(0, Y, K-1);
	//vacio la de y
	if(!visited[X][0][K-1]) dfs(X, 0, K-1);
	//paso de x a y
	if(!visited[X-min(X, y-Y)][Y+min(X, y-Y)][K-1]) dfs(X-min(X, y-Y), Y+min(X, y-Y), K-1);
	//paso de y a x
	if(!visited[X+min(Y, x-X)][Y-min(Y, x-X)][K-1]) dfs(X+min(Y, x-X), Y-min(Y, x-X), K-1);
}

int main(){
	NACHO();
	//simplemente hacé un dfs para pasar por todos los estados
	//similar a snowboots de silver
	cin >> x >> y >> k >> m;
	dfs(0, 0, k);
	cout << ret << "\n";
}
