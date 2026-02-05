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

struct Angle {
	ll x, y; int id;
	int t;
	Angle(ll x, ll y, int id, int t=0) : x(x), y(y), id(id), t(t) {}
	Angle operator-(Angle b) const { return {x-b.x, y-b.y, t}; }
	int half() const {
		assert(x || y);
		return y < 0 || (y == 0 && x < 0);
	}
	Angle t90() const { return {-y, x, t + (half() && x >= 0)}; }
	Angle t180() const { return {-x, -y, t + half()}; }
	Angle t360() const { return {x, y, t + 1}; }
	ll dist2() const { return x*x+y*y; }
};
bool operator<(Angle a, Angle b) {
	// add a.dist2() and b.dist2() to also compare distances
	return make_tuple(a.t, a.half(), a.y * (ll)b.x, -a.dist2()) <
	       make_tuple(b.t, b.half(), a.x * (ll)b.y, -b.dist2());
}
Angle angleDiff(Angle a, Angle b) { // angle b - angle a
	int tu = b.t - a.t; a.t = b.t;
	return {a.x*b.x + a.y*b.y, a.x*b.y - a.y*b.x, tu - (b < a)};
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	
	int n, q; cin >> n >> q;
	vector<Angle> a;
	rep(i, 0, n) {
		ll x, y; cin >> x >> y;
		a.push_back(Angle(x, y, i));
	}
	
	sort(all(a));
	reverse(all(a));
	vi pos(n);
	vi biggestCollinear(n);
	vi smallestCollinear(n);
	Angle prev = a[n-1];
	
	rep(i, 0, n) pos[a[i].id] = i, biggestCollinear[a[i].id] = smallestCollinear[a[i].id] = a[i].id;
	per(i, 0, n) {
		Angle d = angleDiff(prev, a[i]);
		if(d.x > 0 && d.y == 0) {
			biggestCollinear[a[i].id] = prev.id;
		} else prev = a[i];
	}
	prev = a[0];
	rep(i, 0, n) {
		Angle d = angleDiff(prev, a[i]);
		if(d.x > 0 && d.y == 0) {
			smallestCollinear[a[i].id] = prev.id;
		} else prev = a[i];
	}
	rep(_, 0, q) {
		int i, j; cin >> i >> j;
		i--, j--;
		i = smallestCollinear[i], j = biggestCollinear[j];
		int posI = pos[i], posJ = pos[j];
		if(posI <= posJ) cout << posJ - posI + 1 << '\n';
		else cout << posJ+1+n-posI << '\n';
	}
}
