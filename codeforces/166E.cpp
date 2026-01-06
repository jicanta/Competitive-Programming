// https://codeforces.com/problemset/problem/166/E

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>
#include <iomanip>

using namespace std;

const int MOD = 1000000007;

vector<vector<long long>> mul(vector<vector<long long>> &a, vector<vector<long long>> &b) {
	vector<vector<long long>> ret(a.size(), vector<long long>(b[0].size(), 0));
	for(int i = 0; i < (int)a.size(); i++)
		for(int j = 0; j < (int)b[0].size(); j++)
			for(int k = 0; k < (int)a[0].size(); k++)
				ret[i][j] = (ret[i][j] + a[i][k] % MOD * b[k][j] % MOD) % MOD;
	
	return ret;
}

vector<vector<long long>> binpow(vector<vector<long long>> &m, int b) {
	vector<vector<long long>> ret(m.size(), vector<long long>(m.size(), 0));
	for(int i = 0; i < (int)m.size(); i++)
		ret[i][i] = 1;
	while(b) {
		if(b & 1) ret = mul(ret, m);
		m = mul(m, m);
		b /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<long long>> m(4, vector<long long>(4, 1));
	for(int i = 0; i < 4; i++)
		m[i][i] = 0;
	
	m = binpow(m, n);
	
	cout << m[0][0] << '\n';
		
	return 0;
}
