// https://codeforces.com/problemset/problem/416/C

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

	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> p(n);
	for(int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second.first, p[i].second.second = i + 1;
	sort(begin(p), end(p), [&](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
		if(a.second.first == b.second.first)
			return a.first < b.first;
		return a.second.first > b.second.first;
	});
	
	int k;
	cin >> k;
	vector<pair<int, int>> sizes(k);
	for(int i = 0; i < k; i++)
		cin >> sizes[i].first, sizes[i].second = i + 1;
	
	sort(begin(sizes), end(sizes));
	int quan = 0, totSum = 0;
	vector<pair<int, int>> ret;
	vector<bool> used(k, false);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) if(not used[j] && sizes[j].first >= p[i].first) {
			quan++, totSum += p[i].second.first, 
			ret.push_back({p[i].second.second, sizes[j].second});
			used[j] = true;
			break;
		}
	}
	
	cout << quan << ' ' << totSum << '\n';
	for(auto [u, v] : ret)
		cout << u << ' ' << v << '\n';
	
	return 0;
}
