// el D del contest 4 de Andrew Stankevich

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998'244'353;

#define ll long long


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
	vector<ll> dp(n+1), pot3(n+1, 1), extra(max(n+1, 10), 0);
	extra[2] = 1; extra[3] = 4; extra[4] = 5; extra[5] = 4;
	extra[6] = 3; extra[7] = 3;
	for(int i = 1; i <= n; ++i)
		pot3[i] = (3 * pot3[i-1]) % MOD;
	
	dp[1] = 5;
	for(int i = 2; i <= n; ++i) {
		dp[i] = (dp[i] + 4 * dp[i-1] % MOD) % MOD;
		if(i-2 >= 0) dp[i] = (dp[i] + 2 % MOD + 2 * pot3[i-2] % MOD) % MOD;
		dp[i] = (dp[i] + extra[i] % MOD) % MOD;
		
	}
    cout << dp[n] << '\n';
	
    return 0;
}
