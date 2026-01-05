// https://codeforces.com/problemset/problem/279/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>
#include <iomanip>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	vector<int> up(n, 1);
	for(int i = n - 1; i >= 1; i--)
		if(a[i] >= a[i - 1]) up[i-1] = 1 + up[i];
	
	vector<int> down(n, 1);
	for(int i = n - 2; i >= 0; i--)
		if(a[i] >= a[i + 1]) down[i] = 1 + down[i+1]; 
		
		
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		
		if(l + up[l] - 1 + down[l + up[l] - 1] - 1 >= r) cout << "Yes\n";
		else cout << "No\n";
	}
		
	return 0;
}
