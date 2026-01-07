// https://codeforces.com/problemset/problem/467/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdint>
#include <iomanip>

using namespace std;

const int inf = 1e9;
const int mod = 1e8;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<long long> s(n+1, 0);
	for(int i = 1; i <= n; i++)
		s[i] = s[i-1] + a[i-1];
		
	vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
  // dp[i][j] = maxima suma si vi hasta el i y puse j intervalos ya
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			dp[i][j] = dp[i-1][j];
			if(i - m >= 0)
				dp[i][j] = max(dp[i][j], dp[i-m][j-1] + s[i] - s[i-m]);
		}
	}
	
	cout << dp[n][k] << '\n';
	return 0;
}
