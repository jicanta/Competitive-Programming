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
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const tint MOD = 1e9+7;
const int MX = 3e5+5;
const int INF = 1e9;
const long double PI = acos((-1)); 
 
void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n, m;
	int c = 0;
	while(cin >> n >> m && !(n == 0 && m == 0)){
		vi a (n+1), b (m+1);
		forn(i, n) cin >> a[i+1];
		forn(i, m) cin >> b[i+1];
		vector<vi> dp (n+1, vi (m+1, 0));
		forsn(i, 1, n+1){
			forsn(j, 1, m+1){
				if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
				else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		++c;
		cout << "Twin Towers #" << c << "\n";
		cout << "Number of Tiles : " << dp[n][m] << "\n";
		cout << "\n";
	}
}

