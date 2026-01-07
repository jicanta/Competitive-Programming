// https://codeforces.com/problemset/problem/118/D

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

	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	
	vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(2, 0)));
	// dp[i][j][0] = numero de formas de poner i de tipo 1, j de tipo 2 y en el actual pongo un 0/1
	// muy parecido a 225C
	
	dp[0][0][0] = dp[0][0][1] = 1;
	
	for(int i = 0; i <= n1; i++) {
		for(int j = 0; j <= n2; j++) {
			for(int k = 1; k <= k1; k++) {
				if(i - k >= 0)
					dp[i][j][0] += dp[i-k][j][1],
					dp[i][j][0] %= mod;
			}
			for(int k = 1; k <= k2; k++) {
				if(j - k >= 0)
					dp[i][j][1] += dp[i][j-k][0],
					dp[i][j][1] %= mod;
			}
		}
	}
	
	cout << (dp[n1][n2][0] + dp[n1][n2][1]) % mod << '\n';
	return 0;
}
