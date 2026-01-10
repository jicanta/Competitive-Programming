// https://cses.fi/problemset/task/3403/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	vector<vector<pair<int, int>>> come(n+1, vector<pair<int, int>>(m+1, {-1, -1}));
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1],
				come[i][j] = {i-1, j-1};
			else {
				if(dp[i-1][j] >= dp[i][j])
					dp[i][j] = dp[i-1][j],
					come[i][j] = {i-1, j};
				if(dp[i][j-1] >= dp[i][j])
					dp[i][j] = dp[i][j-1],
					come[i][j] = {i, j-1};
			}
			
		}
		
	cout << dp[n][m] << '\n';
	int N = n, M = m;
	vector<int> ret;
	while(N && M) {
		if(a[N-1] == b[M-1])
			ret.push_back(a[N-1]);
		pair<int, int> c = come[N][M];
		N = c.first, M = c.second;
	}
	reverse(begin(ret), end(ret));
	for(auto u : ret)
		cout << u << ' ';
	cout << '\n';
    return 0;
}
