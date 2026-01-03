// https://codeforces.com/problemset/problem/287/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

bool can(long long mid, long long n, long long k) {
	if(k * (k + 1) / 2 - (k - mid) * (k - mid + 1) / 2 - mid + 1  >= n)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, k;
	cin >> n >> k;
	
	if(n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	
	long long low = 0, high = k + 1;
	
	while(high - low > 1) {
		int mid = low + (high - low) / 2;
		if(can(mid, n, k))
			high = mid;
		else low = mid;
	}
	
	if(high == k + 1) high = -1;
	
	cout << high << '\n';
	
	return 0;
}
