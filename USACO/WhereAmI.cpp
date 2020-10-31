#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1e5+5;
const tint INF = 1e18;
const int inf = 2e9;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "whereami"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n; cin >> n;
	string s; cin >> s;
	forsn(tam, 1, sz(s)){
		map<string, int> c;
		forn(i, sz(s)-tam+1){
			++c[s.substr(i, tam)];
		}
		bool ok = 1;
		for(auto u : c){
			if(u.s > 1) ok = 0;
		}
		if(ok){
			cout << tam << "\n";
			return 0;
		}
	}
}
