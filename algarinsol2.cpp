#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 40000000;
const int MOD = 1e9+7;
const int N = 1001;

string tab[N];
vector<vector<int>> dp (N, vector<int> (N, -INF));

int main(){
	NACHO;
	int n, m; cin >> n >> m;
	forn(i, n) cin >> tab[i];
	int posX, posY = 0;
	forn(i, n) if(tab[i][0] == 'A') posX = i;
	dp[posX][posY] = 0;
	forsn(j, 1, m){
		forn(i, n){
			int add = (tab[i][j] == 'J');
			int prev = -INF;
			prev = max(prev, dp[i][j-1]);
			if(i-1 >= 0) prev = max(prev, dp[i-1][j-1]);
			if(i+1 < n) prev = max(prev, dp[i+1][j-1]);
			if(tab[i][j] == 'M'){
				if(prev > 0) dp[i][j] = 0;
			}else{
				dp[i][j] = prev+add;
			}
		}
	}
	int maxi = -INF;
	forn(i, n){
		maxi = max(maxi, dp[i][m-1]);
	}
	if(maxi < 0){
		cout << "SIN SALIDA" << "\n";
	}else cout << maxi << endl;
}


