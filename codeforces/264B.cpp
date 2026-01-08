// https://codeforces.com/problemset/problem/264/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdint>
#include <iomanip>

using namespace std;

const int MAX_N = 1e5 + 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	vector<int> dp(MAX_N, 0), bestDiv(MAX_N, 0);
	int maxi = 0;
	
	dp[a[0]] = 1;
		
	for(int i = 0; i < n; i++) {
		dp[a[i]] = max(dp[a[i]], bestDiv[a[i]] + 1);
		for(int div = 2; div * div <= a[i]; div++) {
			if(a[i] % div == 0)
				dp[a[i]] = max(dp[a[i]], max(bestDiv[div], bestDiv[a[i] / div]) + 1);
		}
		
		for(int div = 1; div * div <= a[i]; div++) {
			if(a[i] % div == 0)
				bestDiv[div] = max(bestDiv[div], dp[a[i]]),
				bestDiv[a[i] / div] = max(bestDiv[a[i] / div], dp[a[i]]);
			
		}
		maxi = max(maxi, dp[a[i]]);
	}
	
	cout << maxi << '\n';
	return 0;
}
