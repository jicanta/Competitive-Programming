// https://codeforces.com/problemset/problem/283/A

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
	
	vector<int> d(n+1, 0);
	int curSize = 1;
	long long curSum = 0;
	
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int a, x;
			cin >> a >> x;
			curSum += x * a;
			if(a == curSize) {
				d[curSize - 1] += x;
			} else {
				d[a - 1] -= x;
			}
		} else if(t == 2) {
			int x;
			cin >> x;
			curSum += x;
			int last = d[curSize - 1];
			d[curSize - 1] = x - last;
			d[curSize] = x;
			curSize++;
		} else {
			curSum -= d[curSize - 1];
			d[curSize - 2] = d[curSize - 1] - d[curSize - 2];
			d[curSize - 1] = 0;
			curSize--;
		}
		
		cout << fixed << setprecision(9) << (double)curSum / curSize << '\n';
	}
	
	return 0;
}
