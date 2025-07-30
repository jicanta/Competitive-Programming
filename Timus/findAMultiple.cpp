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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	
	// considero las sumas de prefijos mod n.
	// si alguna suma de prefijo da 0, gané.
	// sino, tengo (n-1) restos posibles y n sumas de prefijos.
	// entonces, se debe repetir alguna suma de prefijo, y el intervalo entre ambos da 0 mod n.
	
	int cur = 0;
	vi l(n, -2);
	l[0] = -1;
	rep(i, 0, n) {
		cur += a[i];
		cur %= n;
		if(l[cur] >= -1) {
			cout << i - l[cur] << "\n";
			rep(j, l[cur] + 1, i + 1) {
				cout << a[j] << "\n";
			}
			return 0;
		}
		l[cur] = i;
	}
	
	cout << 0 << "\n";
	return 0; 
}

