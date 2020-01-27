//Think twice, code once 
//tzuyu ORZ

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 1000000;
const long double PI = 3.141592653;

int main(){
	NACHO;
	ifstream cin("pajaros.in");
	ofstream cout("pajaros.out");
	int n; cin >> n;
	vector<int> a (n);
	forn(i, n) cin >> a[i];
	vector<vector<int>> dp (n, vector<int> (302, INF));
	dp[0][1] = abs(a[0]-1);
	forsn(i, 1, n){
		forn(j, 301){
			if(j == 0) dp[i][0] = dp[i-1][1]+a[i];
			else{
				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j+1])+abs(a[i]-j);
			}
		}
	}
	int ret = INF;
	forn(i, 302){
		ret = min(ret, dp[n-1][i]);
	}
	cout << ret << "\n";
}
