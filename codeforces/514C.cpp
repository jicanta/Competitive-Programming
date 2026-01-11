// https://codeforces.com/problemset/problem/514/C

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6e5 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> t(MAX_N, vector<int>(3, 0));
    vector<bool> finish(MAX_N, false);
    
    int curNode = 0;
    auto insert = [&](const string &s) {
		int node = 0;
		for(auto ch : s) {
			if(t[node][ch - 'a'] == 0) {
				t[node][ch - 'a'] = ++curNode;
			}
			node = t[node][ch - 'a'];
		}
		finish[node] = true;
	};
	
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}
	
	string q;
	function<bool(int, int, int)> dfs = [&](int node, int pos, int mismatch) -> bool {
		if(mismatch > 1)
			return false;
		if(pos == (int)q.size())
			return mismatch == 1 && finish[node];
			
		for(int i = 0; i < 3; i++) {
			if(t[node][i] != 0) {
				if(dfs(t[node][i], pos + 1, mismatch + (q[pos] != (char)(i + 'a'))))
					return true;
			}
		}
		return false;
	};
	
	for(int i = 0; i < m; i++) {
		cin >> q;
		if(dfs(0, 0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}
    
    return 0;
}
