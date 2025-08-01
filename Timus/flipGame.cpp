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
const int MAXN = (1<<16) + 1;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

char inv(char a) {
	if(a == 'b') return 'w';
	return 'b';
}

struct Grid {
	string tab[4];
	
	void apply(int i, int j) {
		tab[i][j] = inv(tab[i][j]);
		rep(k, 0, 4) {
			int x = i + dx[k], y = j + dy[k];
			if(0 <= x && x < 4 && 0 <= y && y < 4) {
				tab[x][y] = inv(tab[x][y]);
			}
		}
	}
	
	int val() {
		int cur = 0;
		rep(i, 0, 4) {
			rep(j, 0, 4) {
				if(tab[i][j] == 'b') cur |= (1 << (4 * j + i));
			}
		}
		return cur;
	}
};

int bfs(Grid& node) {
	vb vis(MAXN, false);
	vi dist(MAXN, -1);
	queue<Grid> q;
	q.push(node);
	dist[node.val()] = 0;
	
	while(sz(q)) {
		auto u = q.front();
		q.pop();
		vis[u.val()] = true;
		rep(i, 0, 4) {
			rep(j, 0, 4) {
				Grid copy = u;
				copy.apply(i, j);
				if(!vis[copy.val()]) {
					q.push(copy);
					vis[copy.val()] = true;
					dist[copy.val()] = dist[u.val()] + 1;
				}
			}
		}
	}
	if(dist[0] == -1 && dist[MAXN - 2] == -1) return -1;
	if(dist[0] == -1) dist[0] = 1000000;
	if(dist[MAXN - 2] == -1) dist[MAXN - 2] = 100000;
	return min(dist[0], dist[MAXN - 2]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    Grid g;
    
    rep(i, 0, 4) {
		cin >> g.tab[i];
	}
	
	int ret = bfs(g);
	cout << (ret >= 0 ? to_string(ret) : "Impossible\n") << "\n";
	
	return 0; 
}

