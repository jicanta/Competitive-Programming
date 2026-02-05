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
const int MOD = 1'000'000'007;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n; cin >> n;
	queue<int> q;
	q.push(0);
	vi dist(10*n+10, INF);
	dist[0] = 0;
	vi parent(10*n+10, -1);
	while(sz(q)) {
		auto cur = q.front(); q.pop();
		int rem = cur / 10, lastDigit = cur % 10;
		rep(nxtDigit, max(1, lastDigit), 10) {
			int newRem = (10*rem+nxtDigit)%n;
			int nei = 10*newRem+nxtDigit;
			if(dist[nei] == INF) {
				dist[nei] = 1 + dist[cur];
				q.push(nei);
				parent[nei] = cur;
			}
			if(newRem == 0) {
				string ret = "";
				int v = nei;
				while(v != -1) {
					ret += (char)(v % 10 + '0');
					v = parent[v];
				}
				ret.pop_back();
				reverse(all(ret));
				cout << ret << '\n';
				return 0;
			}
		}
	}
	cout << -1 << '\n';
}
