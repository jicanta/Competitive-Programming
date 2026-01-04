// https://codeforces.com/problemset/problem/165/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

#define C2(n) (long long) n * (n + 1) / 2

long long solveZero(const string &s, int sz) {
	long long ret = 0;
	for(int i = 0; i < sz; i++) if(s[i] == '0') {
		int j = i;
		while(j < sz && s[j] == '0') 
			j++; 
		ret += C2(j - i);
		i = j - 1;
	}
	return ret;
		
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	string s;
	cin >> s;
	int n = s.size();
	long long ret = 0;
	
	if(k == 0) {
		cout << solveZero(s, n) << '\n';
		return 0;
	}
	
	vector<int> zerosLeft(n, 0), zerosRight(n, 0);
	for(int i = 1; i < n; i++) {
		if(s[i - 1] == '0') zerosLeft[i] = zerosLeft[i - 1] + 1;
	}
	
	for(int i = n - 2; i >= 0; i--)
		if(s[i + 1] == '0') zerosRight[i] = zerosRight[i + 1] + 1;
		
	for(int i = 0; i < n; i++) if(s[i] == '1') {
		int cur = 0;
		int j = i;
		while(j < n && cur < k) {
			cur += s[j] == '1';
			j++;
		}
		if(cur == k) {
			ret += (long long)(zerosLeft[i] + 1) * (long long)(zerosRight[j - 1] + 1);
			i = j - 1;
		}
	}
	
	cout << ret << '\n';
	return 0;
}
