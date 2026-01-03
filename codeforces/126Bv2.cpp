// https://codeforces.com/problemset/problem/126/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

vector<int> pii(const string& s){
	vector<int> p((int)s.size());
	for(int i = 1; i < (int)s.size(); i++){
		int g = p[i-1];
		while(g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = s.size();
	
	vector<int> pi = pii(s);
	
	if(pi[n-1] == 0) {
		cout << "Just a legend\n";
		return 0;
	}
	
	bool can = false;
	for(int i = 0; i < n - 1; i++)
		can |= pi[i] == pi[n-1];
	if(can) {
		cout << s.substr(0, pi[n-1]) << '\n';
		return 0;
	}
	if(pi[pi[n-1] - 1] == 0) cout << "Just a legend\n";
	else cout << s.substr(0, pi[pi[n-1] - 1]) << '\n';
	
	return 0;
}
