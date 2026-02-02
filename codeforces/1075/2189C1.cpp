/// https://codeforces.com/contest/2189/problem/C1
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

const int INF = 1'000'000'000;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;  
	if(n % 2 == 1) {
	  cout << n-1 << ' ';
	  rep(i, 1, n-1) {
	    if(i % 2 == 0) 
			cout << 2*(i/2) << ' ';
		else cout << 2*(i/2+1)+1 << ' ';
	  }
	  cout << 1 << '\n';
	} else {
	  cout << n << ' ';
	  rep(i, 1, n-1) {
	    if(i % 2 == 1)
			cout << 2*(i/2+1)+1 << ' ';
		else cout << 2*(i/2) << ' ';
	  }
	  cout << 1 << '\n';
	}
  }
}
