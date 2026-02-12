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

const ll INF = 1e18;

template <class T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}
template <class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator*(T k) const { return P(k*x, k*y); }
  T cross(P p) const { return x * p.y - y * p.x; }
  T dot(P p) const { return x*p.x + y*p.y; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  ld dist() const { return sqrtl(x*x+y*y); }
  T dist2() const { return x*x+y*y; }
};

using P = Point<ll>;
vector<P> convexHull(vector<P> pts) {
  if (sz(pts) == 1) return pts;
  sort(all(pts));
  vector<P> h(sz(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(all(pts))) {
    for (P p : pts) {
      while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
      h[t++] = p;
    }
  }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

vector<P> MinkowskiSum(vector<P> a, vector<P> b) {
    if (sz(a) > sz(b)) swap(a, b);
    if (not sz(a)) return {};
    if (sz(a) == 1) {
        for (auto &t : b) t = t+a[0];
        return b;
    }
    rotate(begin(a), min_element(all(a)), end(a));
    rotate(begin(b), min_element(all(b)), end(b));
    a.push_back(a[0]), a.push_back(a[1]);
    b.push_back(b[0]), b.push_back(b[1]);
    vector<P> result;
    int i = 0, j = 0;
    while (i < sz(a)-2 || j < sz(b)-2) {
        result.push_back(a[i] + b[j]);
        ll crs = (a[i+1] - a[i]).cross(b[j+1] - b[j]); // might actually need to use T
        i += (crs >= 0);
        j += (crs <= 0);
    }
    return result;
}

ld area(vector<P> &v) {
	ll a = v.back().cross(v[0]);
	rep(i, 0, sz(v)-1) a += v[i].cross(v[i+1]);
	return (ld)a/2;
}

ld segDist(P s, P e, P p) {
    ld sx=s.x, sy=s.y, ex=e.x, ey=e.y, px=p.x, py=p.y;
    ld vx = ex - sx, vy = ey - sy;
    ld wx = px - sx, wy = py - sy;
    ld vv = vx*vx + vy*vy;
    if (vv == 0) return sqrtl(wx*wx + wy*wy);
    ld t = (wx*vx + wy*vy) / vv;
    if (t < 0) t = 0;
    if (t > 1) t = 1;
    ld cx = sx + t*vx, cy = sy + t*vy;
    ld dx = px - cx, dy = py - cy;
    return sqrtl(dx*dx + dy*dy);
}


int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<P> a(n), b(m);
  rep(i, 0, n) cin >> a[i].x >> a[i].y;
  rep(i, 0, m) cin >> b[i].x >> b[i].y;
  rep(i, 0, m) b[i] = b[i]*-1;
  a = convexHull(a), b = convexHull(b);
  vector<P> M = MinkowskiSum(a, b);
  M = convexHull(M);
  ld ret = INF;
  P c = P(0, 0);
  rep(i, 0, sz(M)) ret = min(ret, segDist(M[i], M[(i+1)%sz(M)], c));
  cout << fixed << setprecision(9) << max((ld).0, ret-60.0) << '\n';
}
