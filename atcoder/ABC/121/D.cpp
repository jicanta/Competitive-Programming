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
const int MX = 2e5+5;

ll prefXor(ll x) {
	if(x <= 0) return 0;
	if(x == 1) return 1;
	ll quanOnes = ((x>1)+(x-1)/2) % 2;
	return (x % 2 == 0 ? x : 0)^quanOnes;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
		
	ll a, b; cin >> a >> b;
	cout << (prefXor(b)^prefXor(a-1)) << '\n';
	
	return 0;
}
