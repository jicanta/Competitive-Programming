// https://codeforces.com/problemset/problem/339/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdint>
#include <iomanip>

using namespace std;

bool dfs(int balance, int prev, int curLevel, const string &s, int m, vector<int> &ret) {
	if(curLevel >= 0 && curLevel % 2 == 0 && balance <= 0)
		return false;
	if(curLevel >= 0 && curLevel % 2 == 1 && balance >= 0)
		return false;
	if(curLevel + 1 == m)
		return true;
	for(int i = 0; i < 10; i++) if(i + 1 != prev && s[i] == '1') {
		int sgn = (curLevel < 0 || ((curLevel % 2) == 1)) ? 1 : -1;
		if(dfs(balance + sgn * (i + 1), i + 1, curLevel + 1, s, m, ret)) {
			ret.push_back(i + 1);
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	int m;
	cin >> m;
	
	vector<int> ret;
	
	if(dfs(0, 0, -1, s, m, ret)) {
		cout << "YES\n";
		reverse(begin(ret), end(ret));
		for(auto u : ret)
			cout << u << ' ';
	} else cout << "NO\n";
	return 0;
}
