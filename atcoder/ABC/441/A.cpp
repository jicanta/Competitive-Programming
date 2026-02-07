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
using ld = long double;

const int INF = 1'000'000'000;
const int MOD = 1'000'000'007;
const ld EPS = 1e-6;

const int DIM = 99;


int main() {
	cin.tie(0)->sync_with_stdio(false);
	int p, q, x, y; cin >> p >> q >> x >> y;
	
	if(p <= x && x <= p + DIM && q <= y && y <= q + DIM) cout << "Yes\n";
	else cout << "No\n";
	
	
	return 0;
}
