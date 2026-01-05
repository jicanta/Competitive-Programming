// https://codeforces.com/problemset/problem/358/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	
	vector<vector<int>> dp(n, vector<int>(2, 0));
	// dp[n][2] -> maxima respuesta si comio hasta el i-esimo
	// y el i come antes o no del i + 1
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	for(int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i-1][0] + b[i], dp[i-1][1] + a[i]);
		dp[i][1] = max(dp[i-1][0] + c[i], dp[i-1][1] + b[i]);
	}
	
	cout << dp[n-1][0] << '\n';	
	return 0;
}
