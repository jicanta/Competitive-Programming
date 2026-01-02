// https://codeforces.com/problemset/problem/126/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

typedef uint64_t ull;
struct H{
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x);}
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const{ return get() == o.get(); }
	bool operator<(H o) const{ return get() < o.get(); }
};
	
static const H C = (long long)1e11+3; // (order∼3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha((int)str.size() + 1), pw(ha) {
		pw[0] = 1;
		for(int i = 0; i < (int)str.size(); i++)
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

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
	
	HashInterval hash(s);
	vector<int> pi = pii(s);
	
	int maxi = 0, pos = -1;
	int sz = s.size();
	for(int i = 0; i < sz - 1; i++) {
		if(hash.hashInterval(0, pi[i]) == hash.hashInterval(sz - pi[i], sz)) {
			if(pi[i] > maxi) {
				maxi = pi[i];
				pos = i - pi[i] + 1;
			}
		}
	}
	
	if(pos == -1)
		cout << "Just a legend\n";
	else cout << s.substr(pos, maxi) << '\n';
	
	return 0;
}
