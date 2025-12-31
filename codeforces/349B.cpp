// https://codeforces.com/problemset/problem/349/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int v;
	cin >> v;
	
	vector<int> cost(9);
	for(int i = 0; i < 9; i++)
		cin >> cost[i];
		
	auto it = min_element(cost.begin(), cost.end());
	auto [minDig, minVal] = pair(it - begin(cost) + 1, *it);
	
	if(minVal > v) {
		cout << -1 << '\n';
		return 0;
	}
	
	for(int i = 0; i < 9; i++)
		if(cost[i] == minVal && i + 1 > minDig)
			minDig = i + 1;
	
	string ret = "";
	for(int i = 0; i < v / minVal; i++)
		ret += (char)(minDig + '0');
		
	v -= minVal * (v / minVal);
	for(int i = 0; i < int(ret.size()); i++) {
		bool changed = false;
		for(int j = 8; j >= 0; j--) {
			if(j + 1 > minDig && not changed && cost[j] <= v + minVal) {
				ret[i] = (char)(j + 1 + '0');
				v += minVal - cost[j];
				changed = true;
			}
		}
		if(not changed)
			break;
	}
	if(ret == "")
		ret = "-1";
	cout << ret << '\n';
	
	return 0;
}
