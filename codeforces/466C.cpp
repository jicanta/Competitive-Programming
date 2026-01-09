// https://codeforces.com/problemset/problem/466/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> a(n), s(n+1, 0);
	
	for(int i = 0; i < n; i++)
		cin >> a[i],
		s[i+1] = s[i] + a[i];
    
	if(s[n] % 3 != 0){
		cout << 0 << '\n';
		return 0;
	}
	
	long long goal = s[n] / 3;
	
	map<long long, int> f;
	long long ret = 0;
	
	for(int i = 1; i < n; i++) {
		if(2 * goal == s[i])
			ret += f[goal];
		f[s[i]]++;
	}
	
	cout << ret << '\n';
    return 0;
}
