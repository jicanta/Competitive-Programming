// https://codeforces.com/problemset/problem/466/B

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	long long n, a, b;
	cin >> n >> a >> b;
	n *= 6;
	
	if(a * b >= n) {
		cout << a * b << '\n';
		cout << a << ' ' << b << '\n';
		return 0;
	}
	
	long long bestDa = INF, bestDb = INF;
	long long minArea = INF;
	
	for(int t = 0; t < 2; t++) {
		for(long long da = a; da * da <= n; da++) {
			long long db = n / da + (n % da != 0);
			if(db >= b && da * db < minArea) {
				minArea = da * db;
				bestDa = da, bestDb = db;
			}
		}
		
		swap(a, b);
	}
	
	cout << minArea << '\n';
	if(bestDa < a || bestDb < b) swap(bestDa, bestDb);
	cout << bestDa << ' ' << bestDb << '\n';
    return 0;
}
