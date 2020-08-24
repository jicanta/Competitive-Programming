#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (tint)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const tint MOD = 1e9+7;
const int MX = 1e5+5;
const tint INF = 1e16;
const ld PI = acos((ld)(-1)); 
const double EPS = 1e-9;

void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	string s1, s2;
	vector<string> a, b;
	while(getline(cin, s1)){
		a.clear(); b.clear();
		if(s1 != "#"){
			istringstream is(s1);
			while(is >> s2) a.pb(s2);
			while(getline(cin, s1)){
				if(s1 == "#") break;
				istringstream is(s1);
				while(is >> s2) a.pb(s2);
			}
		}
		while(getline(cin, s1)){
			if(s1 == "#") break;
			istringstream is(s1);
			while(is >> s2) b.pb(s2);
		}
		int n = sz(a), m = sz(b);
		vector<vi> dp (n+1, vi (m+1, 0));
		vector<vi> vengo (n+1, vi (m+1, -1)); //0->(i-1, j-1)//1->(i-1, j)//2->(i, j-1	)
		forsn(i, 1, n+1){
			forsn(j, 1, m+1){
				if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1, vengo[i][j] = 0;
				else{
					if(dp[i-1][j] > dp[i][j-1]){
						dp[i][j] = dp[i-1][j];
						vengo[i][j] = 1;
					}else{
						dp[i][j] = dp[i][j-1];
						vengo[i][j] = 2;
					}
				}
			}
		}
		int st1 = n, st2 = m;
		vector<string> r;
		while(!(st1 == 0 || st2 == 0)){
			if(a[st1-1] == b[st2-1]) r.pb(a[st1-1]);
			auto s = vengo[st1][st2];
			if(s == 0) --st1, --st2;
			else if(s == 1) --st1;
			else --st2;
		}
		reverse(all(r));
		forn(i, sz(r)){ if(i > 0) cout << " "; cout << r[i];}
		cout << "\n";
	}
}

