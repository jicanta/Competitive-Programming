// https://codeforces.com/problemset/problem/479/E

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	--a, --b;
	
	vector<long long> dp(n+1, 0);
	// dp[a] -> numero de viajes que terminan en a
	// hago el truco del "estado implicito" k que serian
	// cuantos viajes hice
	dp[a] = 1;
	
	for(int i = 0; i < k; ++i) {
		vector<long long> newDp(n+1, 0);
		for(int j = 0; j < n; ++j) if(j != b) {
			int d = abs(j-b);
			newDp[max(0, j-d+1)] = (newDp[max(0, j-d+1)] % MOD + dp[j] % MOD) % MOD;
			newDp[min(n, j+d)] = ((newDp[min(n, j+d)] % MOD - dp[j] % MOD) +  MOD) % MOD;
		}
		
		for(int j = 1; j < n; ++j) 
			newDp[j] = (newDp[j] % MOD + newDp[j-1] % MOD) % MOD;
		
		for(int j = 0; j < n; ++j)
			newDp[j] = ((newDp[j] % MOD - dp[j] % MOD) + MOD) % MOD;
		dp = newDp;
		dp[b] = 0;
	}
	
	long long ret = 0;
	for(int i = 0; i < n; ++i)
		ret = (ret % MOD + dp[i] % MOD) % MOD;
		
	cout << ret << '\n';
    return 0;
}
