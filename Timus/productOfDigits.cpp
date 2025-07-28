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
const int MAXN = 60001;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
  cin.tie(0)->sync_with_stdio(0);
    
	int n; cin >> n;
	if(n == 0) {
		cout << 10 << "\n";
		return 0;
	} else if(n == 1) {
		cout << 1 << "\n";
		return 0;
	}
	string s = "";
	while(n > 1) {
		bool in = false;
		per(i, 2, 10) {
			if(n % i == 0) {
				in = true;
				s += (i + '0');
				n /= i;
				break;
			}
		}
		if(!in) {
			cout << -1 << "\n";
			return 0;
		}
	}
	reverse(all(s));
	cout << s << "\n";
	return 0; 
}
