// https://codeforces.com/problemset/problem/165/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	string s;
	cin >> s;
	int n = s.size();
	vector<int> sum(n, 0);
	sum[0] = s[0] == '1';
	for(int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + (s[i] == '1');
	
	vector<int> f(n + 1, 0);
	f[0]++;
	long long ret = 0;
	for(int i = 0; i < n; i++) {
		if(sum[i] - k >= 0) ret += f[sum[i] - k];
		f[sum[i]]++;
	}
	
	cout << ret << '\n';
	return 0;
}
