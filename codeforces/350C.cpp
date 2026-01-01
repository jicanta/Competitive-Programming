// https://codeforces.com/problemset/problem/350/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MOD = 1000000007;

void printPath(const pair<int, int>& pos) {
	pair<char, char> moves = pair('$', '$');
	if(pos.first) {
		char move = (pos.first > 0 ? 'R' : 'L');
		cout << 1 << ' ' << abs(pos.first) << ' ' << move << '\n';
		moves.first = move;
	}
	if(pos.second) {
		char move = (pos.second > 0 ? 'U' : 'D');
		cout << 1 << ' ' << abs(pos.second) << ' ' << move << '\n';
		moves.second = move;
	}
	cout << 2 << '\n';
	if(moves.first != '$') {
		cout << 1 << ' ' << abs(pos.first) << ' ' << (moves.first == 'L' ? 'R' : 'L') << '\n';
	}
	if(moves.second != '$') {
		cout << 1 << ' ' << abs(pos.second) << ' ' << (moves.second == 'U' ? 'D' : 'U') << '\n';
	}
	cout << 3 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> pos(n);
	
	int ret = 2 * n;
	
	for(int i = 0; i < n; i++)
		cin >> pos[i].first >> pos[i].second, ret += 2 * ((pos[i].first != 0) + (pos[i].second != 0));
		
	sort(begin(pos), end(pos), [&](pair<int, int>& a, pair<int, int>& b) {
		return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
	});
	cout << ret << '\n';
	
	for(int i = 0; i < n; i++)
		printPath(pos[i]);
	
	return 0;
}
