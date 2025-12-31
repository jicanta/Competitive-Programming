// https://codeforces.com/problemset/problem/214/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> removeDigs(const vector<int>& digs, int sum) {
	int sz = digs.size();
	vector<int> ret;
	int checkSum = 0;
	if(sum == 0 && digs.back() == 0)
		return digs;
	else {
		int goalOne = sum;
		int goalTwo = 3 - sum;
		vector<bool> removed(sz, false);
		bool removedOne = false;
		for(int i = sz - 1; i >= 0; i--) {
			if(digs[i] % 3 == goalOne) {
				removed[i] = true;
				removedOne = true;
				break;
			}
		}
		if(not removedOne) {
			int quanRemoved = 0;
			for(int i = sz - 1; i >= 0; i--) {
				if(digs[i] % 3 == goalTwo && quanRemoved++ < 2) {
					removed[i] = true;
				}
			}
		}
		for(int i = 0; i < sz; i++) if(not removed[i])
			ret.push_back(digs[i]), checkSum = (checkSum + digs[i]) % 3;
	}
	return (checkSum == 0 && int(ret.size()) && ret.back() == 0) ? ret : vector<int>{-1};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> digs(n);
	int sum = 0;
	
	for(int i = 0; i < n; i++)
		cin >> digs[i], sum = (sum + digs[i]) % 3;
	
	sort(rbegin(digs), rend(digs));
	
	vector<int> ret = removeDigs(digs, sum);
	
	reverse(begin(ret), end(ret));
	while(ret.back() == 0 && int(ret.size()) > 1) 
		ret.pop_back();
	reverse(begin(ret), end(ret));
	
	for(auto u : ret)
		cout << u;
		
	cout << '\n';
	return 0;
}
