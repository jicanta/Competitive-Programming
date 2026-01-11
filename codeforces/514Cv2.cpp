// https://codeforces.com/problemset/problem/514/C

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6e5 + 1;

// or work mod 10^9+7 if the Birthday paradox is not a problem.
typedef uint64_t ull;

struct H {
    ull x;
    H(ull x = 0) : x(x) {}

    H operator+(H o) { 
        return x + o.x + (x + o.x < x); 
    }

    H operator-(H o) { 
        return *this + ~o.x; 
    }

    H operator*(H o) { 
        __uint128_t m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64); 
    }

    ull get() const { 
        return x + !~x; 
    }

    bool operator==(H o) const { 
        return get() == o.get(); 
    }

    bool operator<(H o) const { 
        return get() < o.get(); 
    }
};

static const H C = (ull)1e11 + 3; // (order ~3e9; random also ok

struct HashInterval {
    vector<H> ha, pw;

    HashInterval(string& str) : ha(str.size() + 1), pw(ha.size()) {
        pw[0] = 1;
        for (int i = 0; i < (int)str.size(); i++)
            ha[i + 1] = ha[i] * C + str[i],
            pw[i + 1] = pw[i] * C;
    }

    H hashInterval(int a, int b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
    
    H hashChange(int i, char newCh) {
		int n = (int)ha.size() - 1;
		H pref = hashInterval(0, i);
		H suff = hashInterval(i+1, n);
		return pref * pw[n-i] + H(newCh) * pw[n-i-1] + suff;
	}
};

H hashString(string& s) {
    H h{};
    for (char c : s) h = h * C + c;
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
	
	vector<string> s(n);
	set<H> hashes;
	
	for(int i = 0; i < n; i++)
		cin >> s[i], hashes.insert(hashString(s[i]));
    
    for(int i = 0; i < m; i++) {
		string t;
		cin >> t;
		HashInterval curHash = HashInterval(t);
		bool can = false;
		for(int j = 0; j < (int)t.size(); j++)
			for(char ch = 'a'; ch <= 'c'; ch++) if(ch != t[j])
				can |= hashes.find(curHash.hashChange(j, ch)) != end(hashes);
		cout << (can ? "YES\n" : "NO\n");
	}
    return 0;
}
