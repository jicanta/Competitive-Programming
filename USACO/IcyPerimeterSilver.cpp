#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(tint i = s; i < tint(n); i++)
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
 
const tint MOD = 1e9+7;
const tint mod = 998244353;
const int MX = 1005; 
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
 
void NACHO(string name = "perimeter"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

string tab[MX];
bool visited[MX][MX];
int area = 0;
int peri = 0;
int n;

void dfs(int x, int y){
	++area;
	int periAct = 4;
	visited[x][y] = 1;
	forn(k, 4){
		int xx = x+dx[k], yy = y+dy[k];
		if(valid(xx, yy, n, n) && tab[xx][yy] == '#') --periAct;
		if(valid(xx, yy, n, n) && !visited[xx][yy] && tab[xx][yy] == '#'){
			dfs(xx, yy);
		}
	}
	peri += periAct;
}

int main(){
	NACHO();
	cin >> n;
	forn(i, n) cin >> tab[i];
	int maxiArea = 0, maxiPer = 0;
	forn(i, n){
		forn(j, n){
			if(tab[i][j] == '#' && !visited[i][j]){
				area = 0;
				peri = 0;
				dfs(i, j);
				if(area > maxiArea || (area == maxiArea && peri < maxiPer)){
					maxiArea = area;
					maxiPer = peri;
				}
			}
		}
	}
	cout << maxiArea << " " << maxiPer << "\n";
}
