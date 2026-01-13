// https://codeforces.com/problemset/problem/439/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n);
    vector<vector<int>> c(2); 
    for(int i = 0; i < n; i++)
		cin >> a[i], 
		c[a[i]%2].push_back(a[i]);
	
	if((int)c[1].size() < k - p) {
		cout << "NO\n";
		return 0;
	}
	vector<vector<int>> group;
	for(int i = 0; i < k - p; i++)
		group.push_back({c[1].back()}),
		c[1].pop_back();
	for(int i = 0; i < p; i++) {
		if(not c[0].empty())
			group.push_back({c[0].back()}),
			c[0].pop_back();
		else {
			if((int)c[1].size() < 2) {
				cout << "NO\n";
				return 0;
			}
			int b = c[1].back();
			c[1].pop_back();
			group.push_back({b, c[1].back()});
			c[1].pop_back();
		}
	}
	
	for(int i = 0; i < (int)c[0].size(); i++)
		group.back().push_back(c[0][i]);
    
    if((int)c[1].size() % 2 == 1) {
		cout << "NO\n";
		return 0;
	}
    for(int i = 0; i < (int)c[1].size(); i++) {
		group.back().push_back(c[1][i]);
	}
	
	cout << "YES\n";
	
	for(int i = 0; i < (int)group.size(); i++) {
		cout << (int)group[i].size() << ' ';
		for(auto u : group[i]) cout << u << ' ';
		cout << '\n';
	}
    return 0;
}
