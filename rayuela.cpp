#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
using vl = vector<tint>;
using vb = vector<bool>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1e2+5;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "rayuela"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int dp[MX][MX][MX];
bool seen[MX][MX][MX];
char word[MX][MX];
int tab[MX][MX];
string s;
int n, q;

bool valid(int x, int y){
	return (0<=x && x<n && 0<=y && y<n);
}

int solve(int x, int y, int ind){
	if(ind >= sz(s)) return 0;
	if(word[x][y] != s[ind]) return -inf;
	if(seen[x][y][ind]) return dp[x][y][ind];
	int ret = -inf;
	forn(k, 4){
		int _x = x+dx[k], _y = y+dy[k];
		if(valid(_x, _y)){
			ret = max(ret, tab[x][y]+solve(_x, _y, ind+1));
		}
	}
	seen[x][y][ind] = 1;
	return dp[x][y][ind] = ret;
}

int main(){
	NACHO();
	cin >> n >> q;
	forn(i, n){
		forn(j, n){
			cin >> word[i][j] >> tab[i][j];
		}
	}
	forn(assda, q){
		cin >> s;
		forn(i, n) forn(j, n) forn(k, sz(s)) dp[i][j][k] = -inf, seen[i][j][k] = 0;
		int ret = -inf;
		forn(i, n) forn(j, n) if(word[i][j] == s[0]) ret = max(ret, solve(i, j, 0));
		if(ret < 0) ret = 0;
		cout << ret << "\n";
	}
}


