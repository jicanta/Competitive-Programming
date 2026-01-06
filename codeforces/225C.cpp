// https://codeforces.com/problemset/problem/225/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdint>
#include <iomanip>

using namespace std;

const int inf = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<string> tab(n);
	for(int i = 0; i < n; i++)
		cin >> tab[i];

	vector<int> toWhite(m, 0), toBlack(m, 0);
	
	for(int j = 0; j < m; j++)
		for(int i = 0; i < n; i++)
			toWhite[j] += tab[i][j] != '.',
			toBlack[j] += tab[i][j] != '#';
	
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(y+1, vector<int>(2, inf)));
	// dp[i][k][0/1] = minimum changes needed up to column j, with current k columns of color 0/1
	dp[0][1][0] = toWhite[0];
	dp[0][1][1] = toBlack[0];
	for(int j = 1; j < m; j++) {
		for(int k = x; k <= y; k++)
			 dp[j][1][0] = min(dp[j][1][0], dp[j-1][k][1] + toWhite[j]),
			 dp[j][1][1] = min(dp[j][1][1], dp[j-1][k][0] + toBlack[j]);
		for(int k = 2; k <= y; k++)
			dp[j][k][0] = dp[j-1][k-1][0] + toWhite[j],
			dp[j][k][1] = dp[j-1][k-1][1] + toBlack[j];
	}
	
	int mini = inf;
	for(int k = x; k <= y; k++)
		mini = min(mini, min(dp[m-1][k][0], dp[m-1][k][1]));
	
	cout << mini << '\n';
	return 0;
}
