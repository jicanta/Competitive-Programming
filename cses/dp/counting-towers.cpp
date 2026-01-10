// https://cses.fi/problemset/task/2413/

#include <bits/stdc++.h>

using namespace std;

const long long MAX_N = 1e6 + 2;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	vector<vector<long long>> dp(MAX_N, vector<long long>(2, 0));
  // dp[i][0/1] = number of towers of height i such that last blocks are / are not connected
	
	dp[1][0] = dp[1][1] = 1;
	
	for(int i = 2; i < MAX_N; i++) {
		dp[i][0] = (2 * dp[i-1][0] % MOD + dp[i-1][1] % MOD) % MOD;
		dp[i][1] = (dp[i-1][0] %  MOD + 4 * dp[i-1][1] % MOD) % MOD;
	}
	
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		cout << (dp[n][1] % MOD + dp[n][0] % MOD) % MOD << '\n';
	}
    return 0;
}
