#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(tint i = s; i < tint(n); i++)
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
const int MX = 2e5+5;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

const int dx[] = {1,-1,0,0,1,-1,-1,1};
const int dy[] = {0,0,1,-1,-1,-1,1,1};

int main(){
	NACHO();
	int n, m;
	while(cin >> n >> m && !(n == 0 && m == 0)){
		vector<string> board (n);
		forn(i, n) cin >> board[i];
		function<bool(int,int)> valid = [&](int x, int y){
			return (0<=x && x<n && 0<=y && y<m);
		};
		vector<vector<bool>> visited (n, vector<bool> (m, 0));
		function<void(int,int)> dfs = [&](int x, int y){
			visited[x][y] = 1;
			forn(k, 8){
				int _x = x+dx[k];
				int _y = y+dy[k];
				if(valid(_x, _y) && !visited[_x][_y] && board[_x][_y] == board[x][y]){
					dfs(_x, _y);
				}
			}
		};
		int ret = 0;
		forn(i, n){
			forn(j, m){
				if(!visited[i][j] && board[i][j] == '@'){
					dfs(i, j);
					++ret;
				}
			}
		}
		cout << ret << "\n";
	}
}


