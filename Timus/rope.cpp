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
const int MAXN = 101;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Pt {
	ld x, y;
	
	Pt operator-(const Pt &o) const {
		Pt c;
		c.x = x - o.x; c.y = y - o.y;
		return c;
	}
	
	ld abs() {
		return sqrt(x * x + y * y);
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	int n; cin >> n;
	ld R; cin >> R;
	
	vector<Pt> poly(n);
	
	rep(i, 0, n) {
		cin >> poly[i].x >> poly[i].y;
	}
	// suma de angulos exteriores polígono, "tortuguita que va recorriéndolo"
	ld ret = 2 * PI * R;
	rep(i, 0, n) {
		ret += (poly[(i + 1) % n] - poly[i]).abs();
	}
	
	cout << fixed << setprecision(2) << ret << "\n";
	
	return 0; 
}

