#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
const int MX = 200005;
const int MOD = 998244353;

#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define ALL(v) begin(v), end(v)
#define SZ(x) (int)((x).size())
#define DBG(x) cerr << #x << " = " << x << endl;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n;
ll L;

ll d[16][16];

struct Path {
	int visitedMask;
	int end;
	
	bool operator<(const Path& o) const {
		#define CMP(field, op) if(field != o.field) return field op o.field;
		CMP(visitedMask, <);
		CMP(end, <);
		return false;
	}
};

const int MAX_LENGTH = 7;

map<Path, vector<ll>> paths;

void go(Path path, int l, ll total) {
	paths[path].push_back(total);
	if(l < MAX_LENGTH) {
		forn(i, n) {
			if(((path.visitedMask>>i)&1) == 0) 
				go({path.visitedMask | (1<<i), i}, l+1, total + d[path.end][i]);
		}
	}
}

bool twoSum(const vector<ll> &a, const vector<ll> &b, ll target) {
	int i = 0;
	int j = SZ(b) - 1;
	while(i < SZ(a) && j >= 0) {
		ll s = a[i] + b[j];
		if(s == target)
			return true;
		else if(s > target)
			j--;
		else
			i++;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> L;
	forn(i, n)
		forn(j, n)
			cin >> d[i][j];
	
	const int START = n-1;
	go({(1<<START), START}, 0, 0);
	for(auto &it : paths)
		sort(ALL(it.second));
	for(const auto &itA : paths) {
		int maskA = itA.first.visitedMask;
		int x = itA.first.end;
		int maskB = ((~maskA) & ((1<<n) - 1)) | (1<<START); 
		forn(y, n) {
			if((maskB>>y) & 1) {
				// puedo mergear los caminos. El A termina en x y el B termina en y.
				// ahora hago un 2SUM en los dos vectores y veo si puedo llegar a suma L.
				auto itB = paths.find({maskB, y});
				if(itB != paths.end() && twoSum(itA.second, itB->second, L - d[x][y])) {
					cout << "possible\n";
					return 0;
				}
			}
		}
	} 
	cout << "impossible\n";
	return 0;
}


