#include <bits/stdc++.h>
using namespace std;

using ld = long double;

const ld EPS = 1e-14;
const ld PI = 3.141592653;
#define all(v) begin(v), end(v)

struct Pt {
    ld x, y;
    Pt(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}

    Pt operator-(const Pt &o) const {
        return Pt(x - o.x, y - o.y);
    }

    ld operator^(const Pt &o) const {
        return x * o.y - y * o.x;
    }
    
    ld operator*(const Pt &o) const {
		return x * o.x + y * o.y;
	}
	
	ld norm() {
		return sqrt(x * x + y * y);
	}
	
	bool operator<(const Pt &o) const {
		if(x == o.x) return y < o.y;
		return x < o.x;
	}
	
	ld dist(Pt &o) {
		return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
	}
};

void normalizeAngle(ld &ang) {
    while(ang < 0) ang += PI;
    while(ang >= PI) ang -= PI;
}

Pt rot(Pt a, ld theta) {
	Pt rot = Pt(a.x * acos(theta) - a.y * asin(theta), 
				   a.x * asin(theta) + a.y * acos(theta));
	return rot;
}

struct Square {
	Pt center;
	ld h;
	ld angleRot;
	int id;
	
	Square(int x1, int y1, int x2, int y2, int id) : id(id) {
		int dx = x2 - x1, dy = y2 - y1;
		h = dx;
		center = Pt((x1 + x2) / 2.0, (y1 + y2) / 2.0);
		Pt vec1 = Pt(x2, y2) - Pt(x1, y1);
		angleRot = atan2(vec1.y, vec1.x) - PI;
	    normalizeAngle(angleRot);
	}
};

ld dist(const Pt &pt, const Square &sq) {
	Pt rotPt = rot(pt, sq.angleRot);
	Pt low = Pt(sq.center.x - sq.h, sq.center.y - sq.h);
	Pt high = Pt(sq.center.x + sq.h, sq.center.y + sq.h);
	
	if(low.x <= rotPt.x && rotPt.x <= high.x) {
		return max((ld)0.0, min(rotPt.y - high.y, low.y - rotPt.y));
	}
	if(low.y <= rotPt.y && rotPt.y <= high.y) {
		return max((ld)0.0, min(rotPt.x - high.x, low.x - rotPt.x));
	}
	Pt low1 = Pt(low.x, high.y);
	Pt low2 = Pt(high.x, low.y);
	return min({rotPt.dist(low), rotPt.dist(low1), rotPt.dist(low2), rotPt.dist(high)});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	
	int n; cin >> n;
	vector<Square> sq;
	
	for(int i = 0; i < n; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		sq.emplace_back(Square(x1, y1, x2, y2, i + 1));
	}
	
	Pt pt;
	cin >> pt.x >> pt.y;
	
	sort(all(sq), [&](const Square &a, const Square &b) {
		ld dist1 = dist(pt, a), dist2 = dist(pt, b);
		if(fabs(dist1 - dist2) < EPS) {
			return a.id < b.id;
		}
		return dist1 < dist2;
	});
	
	for(int i = 0; i < n; i++) {
		cout << sq[i].id;
		if(i) cout << " ";
	}	
	cout << "\n";
}
