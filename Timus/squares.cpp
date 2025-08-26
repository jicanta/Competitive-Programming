#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld EPS = 1e-14;
const ld PI  = 3.14159265358979323846264L;
#define all(v) begin(v), end(v)

struct Pt {
    ld x, y;
    Pt(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}
    Pt operator-(const Pt &o) const { return Pt(x - o.x, y - o.y); }
    ld operator^(const Pt &o) const { return x * o.y - y * o.x; }
    ld operator*(const Pt &o) const { return x * o.x + y * o.y; }
    ld norm() const { return sqrt(x * x + y * y); }
    bool operator<(const Pt &o) const { return (x == o.x) ? (y < o.y) : (x < o.x); }
    ld dist2(const Pt &o) const { ld dx=x-o.x, dy=y-o.y; return dx*dx + dy*dy; }
};

static inline Pt rot(const Pt& a, ld theta) {
    ld cs = cos(theta), sn = sin(theta);
    return Pt(a.x * cs - a.y * sn, a.x * sn + a.y * cs);
}

struct Square {
    Pt center;
    ld halfSide;     
    ld angleSide;    
    int id;

    Square(int x1, int y1, int x2, int y2, int id) : id(id) {
        Pt p1(x1, y1), p2(x2, y2);
        center = Pt((x1 + x2) / 2.0L, (y1 + y2) / 2.0L);

        Pt diag = p2 - p1;
        ld d = hypot(diag.x, diag.y);      
        ld side = d / sqrtl(2.0L);         
        halfSide = side / 2.0L;            

        ld alpha = atan2l(diag.y, diag.x);
        angleSide = alpha - PI/4.0L;
    }
};

static inline ld dist(const Pt& pt, const Square& sq) {
    Pt local = rot(pt - sq.center, -sq.angleSide);

    ld ax = fabsl(local.x), ay = fabsl(local.y);
    ld dx = max(ax - sq.halfSide, 0.0L);
    ld dy = max(ay - sq.halfSide, 0.0L);
    return sqrtl(dx*dx + dy*dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Square> sq;

    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sq.emplace_back(x1, y1, x2, y2, i + 1);
    }

    Pt pt; 
    cin >> pt.x >> pt.y;

    sort(all(sq), [&](const Square &a, const Square &b) {
        ld d1 = dist(pt, a);
        ld d2 = dist(pt, b);
        if (fabsl(d1 - d2) < EPS) return a.id < b.id;
        return d1 < d2;
    });

    for(int i = 0; i < n; i++) {
        if(i) cout << ' ';
        cout << sq[i].id;
    }
    cout << '\n';
}
