// https://codeforces.com/problemset/problem/431/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MOD = 1000000007;

int waysUsingUptoD(int n, int d) {
	vector<int> ways(n+1, 0);
	ways[0] = 1;
	for(int i = 0; i <= n; i++)
		for(int j = 1; j <= d; j++) if(i - j >= 0)
			ways[i] = (ways[i] + ways[i - j]) % MOD;
	return ways[n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, d;
	cin >> n >> k >> d;
	
	if(n < d) {
		cout << 0 << '\n';
		return 0;
	}
	
	cout << (((waysUsingUptoD(n, k) - waysUsingUptoD(n, d - 1)) % MOD) + MOD) % MOD << '\n';
	return 0;
}
