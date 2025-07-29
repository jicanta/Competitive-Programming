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
const int MAXN = 32768;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
  cin.tie(0)->sync_with_stdio(0);
    
	int n;
	cin >> n;
	vii digs(n);
	
	rep(i, 0, n) {
		cin >> digs[i].first >> digs[i].second;
	}
	
	string ret = "";
	int carry = 0;
	per(i, 0, n) {
		int cur = digs[i].first + digs[i].second + carry;
		if(cur >= 10) carry = 1;
		else carry = 0;
		ret += (cur % 10 + '0');
	}
	
	reverse(all(ret));
	cout << ret << "\n";
	
	return 0; 
}
