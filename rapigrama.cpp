#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
 
typedef long long tint;

const int INF = 1e9;
const int MOD = 1e9+7;
const int N = 100001;

int main(){
	ifstream cin("rapigrama.in");
	ofstream cout("rapigrama.out");
	NACHO;
	int n, q; cin >> n >> q;
	vector<string> tab (n);
	vector<string> bat (n, "");
	forn(i, n){
		cin >> tab[i];	
	}
	forn(i, n){
		forn(j, n){
			bat[i]+=tab[j][i];
		}
	}
	vector<pair<int,char>> rets;
	forn(asdja, q){
		string s; cin >> s;
		string ss = s;
		reverse(all(ss));
		char ret = 'a';
		forn(i, n){
			forn(j, n-s.size()+1){
				int idx = 0;
				int x = j;
				while(x < n && idx < int(s.size()) && tab[i][x] == s[idx]){
					x++;
					idx++;
				}
				if(x-j == int(s.size())){
					ret = 'E';
				}
				if(ret != 'a') goto en;
				idx = 0;
				x = j;
				while(x < n && idx < int(s.size()) && tab[i][x] == ss[idx]){
					x++;
					idx++;
				}
				if(x-j == int(s.size())) ret = 'O';
				if(ret != 'a') goto en;
			}
		}
		forn(i, n){
			forn(j, n-s.size()+1){
				int idx = 0;
				int x = j;
				while(x < n && idx < int(s.size()) && bat[i][x] == s[idx]){
					x++;
					idx++;
				}
				if(x-j == int(s.size())) ret = 'S';
				if(ret != 'a') goto en;
				idx = 0;
				x = j;
				while(x < n && idx < int(s.size()) && bat[i][x] == ss[idx]){
					x++;
					idx++;
				}
				if(x-j == int(s.size())) ret = 'N';
				if(ret != 'a') goto en;
			}
		}
		en:;
		if(ret != 'a') rets.push_back({asdja+1, ret});
	}
	forn(i, rets.size()){
		cout << rets[i].first << " " << rets[i].second << endl;
	}
}

