// https://codeforces.com/problemset/problem/455/A

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_NUM = 100001;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n);
	vector<int> f(MAX_NUM, 0);
	for(int i = 0; i < n; i++)
		cin >> a[i], f[a[i]]++;
		
	vector<int> maxPoints(MAX_NUM, 0);
	maxPoints[1] = f[1];
	for(int i = 2; i < MAX_NUM; i++) {
		maxPoints[i] = maxPoints[i-1];
		if(i >= 2) 
			maxPoints[i] = max(maxPoints[i-1], maxPoints[i-2] + f[i] * i);
	}
	cout << maxPoints[MAX_NUM - 1] << '\n';
	
	return 0;
}
