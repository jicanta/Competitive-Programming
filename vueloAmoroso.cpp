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
const int MX = 1e5+5;
const int INF = 1e9;
const long double PI = acos((-1)); 
 
void NACHO(string name = "vuelo"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n;
	cin >> n;
	vi altura (n);
	forn(i, n) cin >> altura[i];
	vector<vi> dp (n, vi (400, INF));
	dp[0][1] = abs(altura[0]-1);
	vector<vi> vengo (n, vi (400, -1));
	forsn(i, 1, n){
		forsn(h, 1, 389){
			if(dp[i-1][h-1] < dp[i-1][h+1]){
				dp[i][h] = dp[i-1][h-1]+abs(altura[i]-h);
				vengo[i][h] = h-1;
			}else{
				dp[i][h] = dp[i-1][h+1]+abs(altura[i]-h);
				vengo[i][h] = h+1;
			}
		}
	}
	int mini = INF;
	int st;
	forn(i, 400){
		if(dp[n-1][i] < mini){
			mini = dp[n-1][i];
			st = i;
		}
	}
	vi ret;
	int l = n-1;
	while(st != -1){
		ret.pb(st);
		st = vengo[l][st];
		--l;
	}
	cout << mini << "\n";
	reverse(all(ret));
	for(auto u : ret){
		cout << u << "\n";
	}
}


