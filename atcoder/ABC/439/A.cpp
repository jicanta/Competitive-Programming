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

const ld INF = 1e18;
const int MOD = 1000000007;
const ld EPS = 1e-12;
const int MX = 2e5+5;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n; cin >> n;
	cout << (1<<n)-2*n << '\n';
	
	return 0;
}

