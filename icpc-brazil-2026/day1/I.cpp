// el I del contest de Andrew Stankevich

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
	// angle to xâˆ’axis in interval [âˆ’pi, pi]
	double angle() const { return atan2(y,x); }
	P unit() const { return *this/dist();}//makes dist()=1
	P perp() const { return P(-y,x);}// rotates+90degrees
	P normal() const { return perp().unit(); }
	// returns point rotated â€™aâ€™ radians ccwaround the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream &os, P p) {
		return os << "(" << p.x << "," << p.y << ")" ; }
};

template <class T>
T polygonArea2(const vector<Point<T>>& v) {
	if(not (int)v.size()) return 0;
	T a = v.back().cross(v[0]);
	for(int i = 0; i < (int)v.size() - 1; ++i) a += v[i].cross(v[i + 1]);
	return a;
}

typedef Point<long double> P;
vector<P> polygonCut(const vector<P>& poly, P s, P e) {
	vector<P> res;
	for(int i = 0; i < (int)poly.size(); ++i) {
		P cur = poly[i], prev = i ? poly[i-1] : poly.back();
		auto a = s.cross(e, cur), b = s.cross(e, prev);
		if ((a < 0) != (b < 0))
			res.push_back(cur + (prev - cur) * (a / (a - b)));
		if (a < 0)
			res.push_back(cur);
	}
	return res;
}

const double MAX_X = 2e5;
const int ITERS = 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<P> poly(n);
    for(int i = 0; i < n; ++i)
		cin >> poly[i].x >> poly[i].y;
    
    long double totalArea = polygonArea2(poly);
    if(totalArea < 0) {
		totalArea *= -1;
		reverse(begin(poly), end(poly));
	}
	
	long double low = -MAX_X, high = MAX_X;
	for(int _ = 0; _ < ITERS; ++_) {
		long double mid = low + (high - low) / 2;
		long double leftArea = 
			polygonArea2(polygonCut(poly, P(mid, -MAX_X), P(mid, MAX_X)));
		long double rightArea = totalArea - leftArea;
		if(leftArea > k * rightArea)
			low = mid;
		else high = mid;
	}
	cout << fixed << setprecision(10) << low << '\n';
    return 0;
}
