// http://codeforces.com/problemset/problem/382/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdint>
#include <iomanip>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if(n == 1) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int> a(n);
	bool allSame = true;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(begin(a), end(a));
	for(int i = 0; i < n - 1; i++)
		allSame &= a[i] == a[i+1];
	if(allSame) {
		cout << 1 << '\n';
		cout << a[0] << '\n';
		return 0;
	}
	int diff = a[1] - a[0];
	
	if(n == 2) {
		if(diff % 2 == 0) {
			cout << 3 << '\n';
			cout << a[0] - diff << ' ' << a[0] + diff / 2 << ' ' << a[1] + diff << '\n';
		} else {
			cout << 2 << '\n';
			cout << a[0] - diff << ' ' << a[1] + diff << '\n';
		}
		return 0;
	}
	
	map<int, int> f;
	for(int i = 0; i < n - 1; i++)
		f[a[i+1] - a[i]]++;
		
	if((int)f.size() > 2) {
		cout << 0 << '\n';
		return 0;
	}
	
	if((int)f.size() == 1) {
		cout << 2 << '\n';
		cout << a[0] - diff << ' ' << a[n-1] + diff << '\n';
		return 0;
	}
	
	bool can = false;
	int idx;
	for(int i = 0; i < n - 1; i++) {
		if(a[i+1] != a[i] && f[a[i+1] - a[i]] == 1 && (a[i+1] - a[i]) % 2 == 0) {
			can = true;
			idx = i;
			diff = a[i+1] - a[i];
		}
	}
	
	if(not can) {
		cout << 0 << '\n';
		return 0;
	}
	
	cout << 1 << '\n';
	cout << a[idx] + diff / 2 << '\n';
	return 0;
}
