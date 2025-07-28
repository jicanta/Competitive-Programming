#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vb = vector<bool>;
using ld = long double;
 
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
 
const ld EPS = 1e-12;
const ld PI = acos(-1);
const int inf = 1000000000;
const int MAXN = 37;

char tab[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool viss[MAXN][MAXN][4];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n;
int ret = 0;

void dfs(int x, int y) {
	vis[x][y] = true;
	rep(k, 0, 4) {
		int nX = x + dx[k], nY = y + dy[k];
		if(0 <= nX && nX < n + 2 && 0 <= nY && nY < n + 2) {
			if(tab[nX][nY] == '#' && !viss[nX][nY][k]) {
				ret += 9;
				viss[nX][nY][k] = true;
			}
			if(!vis[nX][nY] && tab[nX][nY] == '.') dfs(nX, nY);
		}
	}
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	
	rep(i, 0, n) {
		string s; cin >> s;
		rep(j, 1, n + 1) tab[i+1][j] = s[j-1];
	}
	rep(i, 2, n+2) tab[0][i] = '#';
	rep(i, 2, n+2) tab[i][0] = '#';
	rep(i, 0, n) tab[i][n+1] = '#';
	rep(i, 0, n) tab[n+1][i] = '#';
	tab[0][0] = tab[0][1] = tab[1][0] = ' ';
	tab[n+1][n+1] = tab[n+1][n] = tab[n][n+1] = ' ';
	
	dfs(1, 1);
	dfs(n, n);
	
	cout << ret << "\n";
	
	
	return 0; 
}
