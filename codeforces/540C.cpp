// https://codeforces.com/problemset/problem/540/C

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n, m;
	cin >> n >> m;
	
	vector<string> tab(n);
	for(int i = 0; i < n; i++)
		cin >> tab[i];
	
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	--r1, --c1, --r2, --c2;
	
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	vis[r1][c1] = true;
	
	function<void(int, int, int, int)> dfs = [&](int x, int y, int xx, int yy) {
		vis[x][y] = true;
		if(x == r2 && y == c2)
			return;
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if(0 <= nx && nx < n && 0 <= ny && ny < m && 
				not vis[nx][ny] && (tab[nx][ny] == '.' || (nx == r2 && ny == c2)) &&
				not (nx == xx && ny == yy)) {
					dfs(nx, ny, xx, yy);
			}
		}
	};
	for(int k = 0; k < 4; k++) {
		int nx = r2 + dx[k], ny = c2 + dx[k];
		if(0 <= nx && nx < n && 0 <= ny && ny < m && tab[nx][ny] == '.') {
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					vis[i][j] = false;
			vis[r1][c1] = true;
			dfs(r1, c1, nx, ny);
			if(vis[r2][c2]) {
				cout << "YES\n";
				return 0;
			}
		}
	}
		
    cout << "NO\n";
    return 0;
}
