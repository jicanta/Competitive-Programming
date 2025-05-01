#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using i128 = __int128_t;
const int INF = 1000000000;
const int MX = 500001;
const int MOD = 998244353;
const double EPS = 1e-6;

#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define dforn(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)
#define SZ(x) (int)((x).size())
#define DBG(x) cerr << #x << " = " << x << endl;
#define NACHO ios_base::sync_with_stdio(0);cin.tie(NULL)
#define pb push_back

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int trie[MX][26];
bool endString[MX];
int depth[MX];
int curNode = 0;
int n;

void insert(string &s) {
	int node = 0;
	for(auto u : s) {
		if(trie[node][u - 'a'] == 0) {
			trie[node][u - 'a'] = ++curNode;
		}
		node = trie[node][u - 'a'];
	}
	endString[node] = true;
}

void dfs(int node) {
	depth[node] = max(depth[node], 1);
	forn(i, 26) {
		if(trie[node][i] != 0) {
			dfs(trie[node][i]);
			depth[node] = max(depth[node], depth[trie[node][i]] + 1);
		}
	}
}

vector<char> ret;

void printInfo(int node, char cur) {
	if(cur != '0')
		ret.pb(cur);
		
	if(endString[node]) {
		ret.pb('P');
		n--;
	}
	vector<pair<int, pair<int, char>>> ord;
	forn(i, 26) {
		if(trie[node][i] != 0) {
			ord.push_back({depth[trie[node][i]], {trie[node][i], i + 'a'}});
		}
	}
	sort(ALL(ord));
	forn(i, SZ(ord)) {
		printInfo(ord[i].second.first, ord[i].second.second);
	}
	if(n)
		ret.pb('-');
}

int main() {
	NACHO;
	
	cin >> n;
	
	vector<string> s(n);
	forn(i, n) 
		cin >> s[i];
	
	forn(i, n)
		insert(s[i]);
		
	dfs(0);
	
	printInfo(0, '0');
	
	cout << SZ(ret) << "\n";
	for(auto u : ret)
		cout << u << "\n";
	
	return 0;
}
