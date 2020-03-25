#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
#define dbg cout << "hu" << endl;

const int INF = 55550000;

int dp[65537];

int main(){
	NACHO;
	ifstream cin("placas.in");
	ofstream cout("placas.out");
	int n, k; cin >> k >> n;
	vector<pair<int,int>> a (n);
	forn(i, n){
		cin >> a[i].first >> a[i].second;
	}
	dp[0] = 0;
	forsn(i, 1, 1<<n){
		int miniX = INF, miniY = INF, maxiX = -1, maxiY = -1;
		forn(j, n){
			if(i&(1<<j)){
				miniX = min(miniX, a[j].first);
				miniY = min(miniY, a[j].second);
				maxiX = max(maxiX, a[j].first);
				maxiY = max(maxiY, a[j].second);
			}
		}
		int cost = 2*(maxiX-miniX+2*k)+2*(maxiY-miniY+2*k);
		dp[i] = cost;
		for(int j=i;j;j=(j-1)&i){
			dp[i] = min(dp[i], dp[i-j]+dp[j]);
		}
	}
	cout << dp[(1<<n)-1] << "\n";
}
