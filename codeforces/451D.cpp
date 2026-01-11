// https://codeforces.com/problemset/problem/451/D

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6e5 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = (int)s.size();
    
    vector<vector<int>> c(2, vector<int>(2, 0));
    
    long long even = 0, odd = 0;
    for(int i = 0; i < n; i++) {
		++c[s[i]-'a'][i%2];
		even += c[s[i]-'a'][1^(i%2)];
		odd += c[s[i]-'a'][i%2];
	}
    
    cout << even << ' ' << odd << '\n';
    return 0;
}
