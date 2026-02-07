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

ll floorsum(ll a, ll b, ll m, ll n){
	 if (n == 0) return 0;
	 if (a >= m) return (n*(n-1)/2) * (a/m) + floorsum(a%m,b,m,n);
	 if (b >= m) return n * (b/m) + floorsum(a,b%m,m,n); 
	 if (a < 0){
	 	a = -a;
	 	ll aux = (a+m-1)/m;
		return -(n*(n-1)/2) * aux + floorsum(aux*m-a,b,m,n);
	 }
	 if (b < 0){
	 	b = -b;
		ll aux = (b+m-1)/m;
		return -n*aux + floorsum(a,aux*m-b,m,n);
	 }
	 ll a2 = m, b2 = (a*n+b)%m, m2 = a, n2 = (a*n+b)/m;
	 return floorsum(a2,b2,m2,n2);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int t; cin >> t;
	while(t--) {
		int n, m, a, b; cin >> n >> m >> a >> b;
		cout << n + floorsum(a-1, b-1, m, n) - floorsum(a, b, m, n)  << '\n';
	}
	return 0;
}
