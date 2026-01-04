// https://codeforces.com/problemset/problem/276/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long l, r;
	cin >> l >> r;

	for(int i = 63; i >= 0; i--) {
		bool onL = l & (1LL << i), onR = r & (1LL << i);
		if(onL != onR) {
			cout << (1LL << (i + 1)) - 1 << '\n';
			return 0;
		}
	}
	
	return 0;
}
