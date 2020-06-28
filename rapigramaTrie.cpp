#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
  
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int N = 1000000;

int trie[N][26];
bool fin[N];
char type[N];
string tab[1001];
vector<string> bat;

int m = 1;

void ins(const string &s, char res){
	int u = 0;
	for(const auto &d : s){
		if(trie[u][d-'a'] == 0){
			trie[u][d-'a'] = m++;
		}
		u = trie[u][d-'a'];
	}
	fin[u] = 1;
	type[u] = res;
}

char search(const string &s){
	int u = 0;
	for(const auto &d : s){
		if(trie[u][d-'a'] == 0){
			return 'Q';
		}
		u = trie[u][d-'a'];
	}
	if(fin[u]){
		return type[u];
	}else return 'Q';
}

int main(){
    NACHO;
	ifstream cin("rapigrama.in");
	ofstream cout("rapigrama.out");
	int n, m; cin >> n >> m;
	forn(i, n){
		cin >> tab[i];
	}
	forn(i, n){
		forn(j, n){
			forn(k, n-j+1){
				ins(tab[i].substr(j, k), 'E');
			}
		}
	}
	bat.resize(n, string(n, '0'));
	forn(i, n){
		forn(j, n){
			bat[j][i] = tab[i][j];
		}
	}
	forn(i, n){
		forn(j, n){
			forn(k, n-j+1){
				ins(bat[i].substr(j, k), 'S');
			}
		}
	}
	vector<pair<int,char>> ret;
	forn(i, m){
		string s; cin >> s;
		char a = search(s);
		string ss = s;
		reverse(all(ss));
		char b = search(ss);
		if(a == 'Q' && b == 'Q')continue;
		if(a != 'Q'){
			ret.push_back({i+1, a});
		}else if(b != 'Q'){
			if(b == 'E') b = 'O';
			if(b == 'S') b = 'N';
			ret.push_back({i+1, b});
		}
	}
	for(auto u : ret) cout << u.first << " " << u.second << "\n";
}
