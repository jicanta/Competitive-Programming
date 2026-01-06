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
	vector<int> prefToWhite(m+1, 0), prefToBlack(m+1, 0);
	
	for(int j = 0; j < m; j++)
		for(int i = 0; i < n; i++)
			toWhite[j] += tab[i][j] != '.',
			toBlack[j] += tab[i][j] != '#';
			
	for(int j = 1; j <= m; j++)
		prefToWhite[j] = prefToWhite[j-1] + toWhite[j-1],
		prefToBlack[j] = prefToBlack[j-1] + toBlack[j-1];
	
	vector<vector<int>> dp(m+1, vector<int>(2, inf));
	// dp[i][0/1] = minima cantidad a cambiar viendo hasta la j-esima columna y poniendo un 0/1 en esta columna
	dp[0][0] = 0;
	dp[0][1] = 0;
	for(int j = 1; j <= m; j++) {
		for(int k = x; k <= y; k++) if(j - k >= 0) {
			dp[j][0] = min(dp[j][0], dp[j - k][1] + (prefToWhite[j] - prefToWhite[j - k]));
			dp[j][1] = min(dp[j][1], dp[j - k][0] + (prefToBlack[j] - prefToBlack[j - k]));
		}
	}
	
	cout << min(dp[m][0], dp[m][1]) << '\n';
	return 0;
}
