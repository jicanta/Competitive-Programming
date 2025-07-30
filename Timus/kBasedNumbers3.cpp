#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;
using vb = vector<bool>;
using ld = long double;
 
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
 
const ld EPS = 1e-12;
const ld PI = acos(-1);
const int inf = 1000000000;
const int MAXN = 32768;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
ll m;

struct Mat {
	ll X[2][2];
	
	Mat operator*(const Mat& o) const {
		Mat r = {};
		rep(i, 0, 2) {
			rep(j, 0, 2) {
				rep(k, 0, 2) {
					r.X[i][j] = (r.X[i][j] % m + X[i][k] % m * o.X[k][j] % m) % m; 
				}
			}
		}
		return r;
	}
};

Mat binpow(Mat a, ll b) {
	Mat ret;
	ret.X[0][0] = ret.X[1][1] = 1; ret.X[0][1] = ret.X[1][0] = 0;
	while(b) {
		if(b & 1) ret = ret * a;
		a = a * a;
		b >>= 1LL;
	}
	return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	// conzero_0 = 0, sinzero_0 = k-1
	// conzero_i = sinzero_i-1, sinzero_i = (k-1) * conzero_i-1 + (k-1) * sinzero_i-1
	// puedo pasarlo todo a una recurrencia lineal de una sola variable:
	// sea sinzero_i = a_i
	// a_i = (k-1) * (a_i-1 + a_i-2)
	// El resto es historia, y a la hora de escribir esto, ya quedГі en el pasado
	// casos base: a0 = 1, a1 = k - 1
	
	ll n, k;
	cin >> n >> k >> m;
	Mat mat;
	mat.X[0][0] = 0; mat.X[0][1] = 1; mat.X[1][0] = k - 1; mat.X[1][1] = k - 1;
	Mat ret = binpow(mat, n);
	ll rett = 1 * ret.X[0][0] % m + (k - 1) * ret.X[0][1] % m;
	rett %= m;
	
	cout << rett << "\n";
	
	return 0; 
}
