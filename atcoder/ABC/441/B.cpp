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
	
	int n, m; cin >> n >> m;
	vi seenA(26, 0), seenB(26, 0);
	string s, t; cin >> s >> t;
	for(auto c : s) seenA[c-'a'] = true;
	for(auto c : t) seenB[c-'a'] = true;
	
	int q; cin >> q;
	rep(_, 0, q) {
		cin >> s;
		bool A = true, B = true;
		for(auto u : s) A &= seenA[u-'a'], B &= seenB[u-'a'];
		if(A && B) cout << "Unknown\n";
		else if(A) cout << "Takahashi\n";
		else cout << "Aoki\n";
	}
	
	return 0;
}
