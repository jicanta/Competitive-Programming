#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for(int i = (int)b-1; i >= a; i--)
#define sz(x) (int)(x.size())
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vl = vector<ll>;
using vb = vector<bool>;

const int INF = 1'000'000'000;
const int MOD = 1'000'000'007;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n, c; cin >> n >> c;
		c--;
		vector<string> a(n);
		rep(i, 0, n)
			cin >> a[i];
		vector<vi> rowByCol(n);
		rep(col, 0, n) {
			rep(row, 0, n) {
				if(a[row][col] == '#') {
					rowByCol[col].push_back(row);
				}
			}
		}
		vector<vb> vis(n, vb(n, false));
		queue<pii> q;
		if(a[n-1][c] != '#') {
			q.push({n-1, c});
			vis[n-1][c] = true;
		}
		while(sz(q)) {
			auto [x, y] = q.front(); q.pop();
			rep(k, -1, 2) {
				if(x-1 >= 0 && 0 <= y+k && y+k < n && not vis[x-1][y+k]) {
					if(a[x-1][y+k] == '.') {
						vis[x-1][y+k] = true;
						q.push({x-1, y+k});
					} else if(rowByCol[y+k].back() == x-1) {
						vis[x-1][y+k] = true;
						q.push({x-1, y+k});
						rowByCol[y+k].pop_back();
					}
				}
			}
		}
		string ret = "";
		rep(i, 0, n) {
			if(vis[0][i]) ret += '1';
			else ret += '0';
		}
		cout << ret << '\n';
	}
}
