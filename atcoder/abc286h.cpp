// https://atcoder.jp/contests/abc286/tasks/abc286_h

#include <bits/stdc++.h>

using namespace std;

template <class T> int sgn(T x){ return (x > 0)-(x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x, p.y); }
	bool operator==(P p)const { return tie(x,y) == tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x+y*p.y; }
	T cross(P p) const { return x*p.y-y*p.x; }
	T cross(P a,P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x+y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x−axis in interval [−pi, pi]
	double angle() const { return atan2(y,x); }
	P unit() const { return *this/dist();}//makes dist()=1
	P perp() const { return P(-y,x);}// rotates+90degrees
	P normal() const { return perp().unit(); }
	// returns point rotated ’a’ radians ccwaround the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream &os, P p) {
		return os << "(" << p.x << "," << p.y << ")" ; }
};

typedef Point<long long> P;
vector<P> convexHull(vector<P> pts) {
	if((int)pts.size() <= 1) return pts;
	sort(begin(pts), end(pts));
	vector<P> h((int)pts.size()+1);
	int s = 0, t = 0;
	for(int it = 2; it--; s = --t, reverse(begin(pts), end(pts)))
		for(P p : pts){
			while (t >= s+2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin()+t-(t == 2 && h[0] == h[1])};
}

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s-p).dot(e-p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d,a), ob = c.cross(d,b),
	oc = a.cross(b,c), od = a.cross(b,d);
	//Checks if intersection is single non−endpoint point.
	if(sgn(oa)*sgn(ob) <= 0 && sgn(oc)*sgn(od) <= 0 && not (oa == 0 && ob == 0))
		return {(a*ob-b*oa)/(ob-oa)};
	set<P> s;
	if(onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {begin(s), end(s)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<P> poly;
    for(int i = 0; i < n; ++i) {
		long long x, y;
		cin >> x >> y;
		poly.push_back(P(x, y));
	}
	
	P s, t;
	cin >> s.x >> s.y;
	cin >> t.x >> t.y;
	
	cout << fixed << setprecision(9);
		
	poly.push_back(s);
	poly.push_back(t);
	vector<P> chull = convexHull(poly);
	
	bool inter = false;
	
	for(int i = 0; i < n; ++i) {
		inter |= (not segInter(s, t, poly[i], poly[(i+1)%n]).empty());
	}
	
	if(not inter) {
		cout << (s-t).dist() << '\n';
		return 0;
	}
	
	long double cw = 0, ccw = 0;
	int m = (int)chull.size();
	for(int _ = 0; _ < 2; ++_) {
		for(int i = 0; i < m; ++i) {
			if(chull[i] == s) {
				int j = (i+1)%m;
				while(not (chull[((j-1)+m)%m] == t)) {
					cw += (chull[j] - chull[((j-1)+m)%m]).dist();
					++j;
					j %= m;
				}
				break;
			}
		}
		swap(s, t);
		swap(cw, ccw);
	}
	cout << min(cw, ccw) << '\n';
    return 0;
}
