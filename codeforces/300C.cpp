// https://codeforces.com/problemset/problem/300/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MOD = 1000000007;

bool isGood(int x, int a, int b) {
	bool good = true;
	while(x) {
		good &= (x % 10) == a || (x % 10) == b;
		x /= 10;
	}
	return good;
}

int binPow(long long a, long long b) {
	a %= MOD;
	long long ret = 1;
	while(b) {
		if(b % 2 == 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ret;
}

int inv(int x) {
	return binPow(x, MOD - 2);
}

void fillFacts(vector<long long>& facts, int n) {
	facts[0] = 1;
	for(int i = 1; i <= n; i++)
		facts[i] = i * facts[i - 1] % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, n;
	cin >> a >> b >> n;
	vector<long long> facts(n + 1);
	
	fillFacts(facts, n);
		
	long long ret = 0;
	
	for(int i = 0; i <= n; i++) {
		int sum = a * i + b * (n - i);
		if(isGood(sum, a, b)) {
			ret = (ret + facts[n] * inv(facts[i]) % MOD * inv(facts[n - i]) % MOD) % MOD;
		}
	}
	
	cout << ret << '\n';
	return 0;
}
