#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define sz(x) (int)(x.size())
#define all(x) begin(x), end(x)

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vb = vector<bool>;
using ll = long long;
using vl = vector<ll>;
using ld = long double;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int a, b; cin >> a >> b;
	a *= 12;
	cout << a+b << '\n';
}
