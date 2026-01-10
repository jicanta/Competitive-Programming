// https://codeforces.com/problemset/problem/404/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> d(n);
    for(int i = 0; i < n; i++)
		cin >> d[i].first, d[i].second = i;
	
	int countZero = 0, id = -1;
	for(int i = 0; i < n; i++) if(d[i].first == 0) {
		++countZero;
		id = i;
	}
	
	if(countZero > 1) {
		cout << -1 << '\n';
		return 0;
	}
	bool can = true;
	vector<int> deg(n, 0);
	vector<set<int>> byDist(n+1);
	vector<pair<int, int>> edges;
	
	auto addNode = [&](int node, int dist, bool changeDeg = true) {
		if(deg[node] + 1 > k) can = false;
		byDist[dist].insert(node);
		if(changeDeg) deg[node]++;
		if(deg[node] == k) byDist[dist].erase(node);
	};

	sort(begin(d), end(d));
	addNode(id, 0, false);
	
	for(int i = 1; i < n; i++) {
		if(byDist[d[i].first - 1].empty()) {
			can = false;
			break;
		}
		auto nei = *byDist[d[i].first - 1].begin();
		deg[nei]++;
		if(deg[nei] == k) byDist[d[i].first - 1].erase(nei);
		addNode(d[i].second, d[i].first);
		edges.push_back({nei, d[i].second});
	}
	
	if(not can) {
		cout << -1 << '\n';
	} else {
		cout << (int)edges.size() << '\n';
		for(auto [u, v] : edges)
			cout << u+1 << ' ' << v+1 << '\n';
	}
    return 0;
}
