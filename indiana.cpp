#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);

const int INF = 1e5;
const int MOD = 1e9+7;

int main(){
	NACHO;
	ifstream cin("indiana.in");
	ofstream cout("indiana.out");
	int n; cin >> n;
	string tab[n];
	bool type[n][n];
	int dp[n][n][4];
	forn(i, n){
		cin >> tab[i];
		forn(j, n){
			type[i][j] = (tab[i][j] == 'H' ? 1 : 0);
		}
	}
	forn(i, n){
		forn(j, n){
			forn(k, 4){
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][2] = 0;
	forn(i, n){
		forn(j, n){
			forn(k, 4){
				if(k == 0 && i-1 >= 0){
					if(type[i-1][j] == 1){
						dp[i][j][k] = min({dp[i][j][k], dp[i-1][j][0]+2, dp[i-1][j][2]+3, dp[i-1][j][3]+1});
					}else{
						dp[i][j][k] = min({dp[i][j][k], dp[i-1][j][0]+2, dp[i-1][j][2]+1, dp[i-1][j][3]+3});
					}
				}else if(k == 1 && i+1 <= n-1){
					if(type[i+1][j] == 1){
						dp[i][j][k] = min({dp[i][j][k], dp[i+1][j][1]+2, dp[i+1][j][2]+3, dp[i+1][j][3]+1});
					}else{
						dp[i][j][k] = min({dp[i][j][k], dp[i+1][j][1]+2, dp[i+1][j][2]+1, dp[i+1][j][3]+3});
					}
				}else if(k == 2 && j-1 >= 0){
					if(type[i][j-1] == 1){
						dp[i][j][k] = min({dp[i][j][k], dp[i][j-1][0]+1, dp[i][j-1][1]+3, dp[i][j-1][2]+2});
					}else{
						dp[i][j][k] = min({dp[i][j][k], dp[i][j-1][0]+3, dp[i][j-1][1]+1, dp[i][j-1][2]+2});
					}
				}else if(k == 3 && j+1 <= n-1){
					if(type[i][j+1] == 1){
						dp[i][j][k] = min({dp[i][j][k], dp[i][j+1][0]+3, dp[i][j+1][1]+1, dp[i][j+1][3]+2});
					}else{
						dp[i][j][k] = min({dp[i][j][k], dp[i][j+1][0]+1, dp[i][j+1][1]+3, dp[i][j+1][3]+2});
					}
				}
			}
		}
	}
	if(type[n-1][n-1] == 1){
		cout << min(dp[n-1][n-1][0]+1, dp[n-1][n-1][2]+2) << "\n";
	}else{
		cout << min(dp[n-1][n-1][0]+3, dp[n-1][n-1][2]+2) << "\n";
	}
}
