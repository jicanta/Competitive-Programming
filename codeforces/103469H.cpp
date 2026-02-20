// https://codeforces.com/gym/103469/problem/H
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

const ll INF = 1e13;
 
int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int k; cin >> k;
	if(k == 1) {
		cout << "2 1\n";
		cout << "1 2\n";
		return 0;
	}
	if(k == 2) {
		cout << "4 4\n";
		cout << "1 2\n";
		cout << "1 3\n";
		cout << "2 3\n";
		cout << "3 4\n";
		return 0;
	}
	if(k <= 20) {
		cout << k << ' ' << k << '\n';
		rep(i, 1, k) cout << i << ' ' << i+1 << '\n';
		cout << k << ' ' << 1 << '\n';
		return 0;
	}
	
	rep(n, 3, 21) {
		for(int m = 0; m+n <= 20; m++) {
			if(n*(n-1)/2-1+m-1+2*(n-1) == k) {
				vii ret;
				rep(i, 1, n+1) {
					rep(j, i+1, n+1) {
						ret.push_back({i, j});
					}
				}
				ret.push_back({1, n+1});
				ret.push_back({2, n+m});
				rep(i, n+1, n+m) {
					ret.push_back({i, i+1});
				}
				cout << n+m << ' ' << sz(ret) << '\n';
				for(auto [u, v] : ret) cout << u << ' ' << v << '\n';
				return 0;
			}
		}
	}
		
	return 0;
}
