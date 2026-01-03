// https://codeforces.com/problemset/problem/363/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = s.size();
	
	string sClean = "";
	
	for(int i = 0; i < n; i++) {
		if(i > 1 && s[i - 1] == s[i] && s[i - 2] == s[i])
			continue;
		sClean += s[i];
	}
	
	int cur = 0;
	string ret = "";
	bool addedLast = false;
	for(int i = 0; i < int(sClean.size()) - 1; i++) {
		ret += sClean[i];
		if(sClean[i] == sClean[i + 1]) {
			cur++;
			if(cur & 1) ret += sClean[i];
			addedLast |= i + 2 == (int)sClean.size();
			i++;
		} else {
			cur = 0;
		}
	}
	if(not addedLast) ret += sClean.back();
	
	cout << ret << '\n';
	
	return 0;
}
