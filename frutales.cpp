#include <iostream>
#include <vector> 
#include <fstream>
#include <cassert>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
#define dbg cout << "hu" << endl;
 
const tint INF = 11000000;
const int MOD = 1000000007;

int pinos[2002][2002];
int frutas[2002][2002];
int SP[2002][2002];
int SF[2002][2002];
int dp[2002][2002];

int main(){
	NACHO;
	ifstream cin("frutales.in");
	ofstream cout("frutales.out");
	int n, m, p, f; cin >> n >> m >> p >> f;
	forn(i, p){
		int x, y; cin >> x >> y;
		pinos[x-1][y-1] = 1;
	}
	forn(i, f){
		int x, y; cin >> x >> y;
		frutas[x-1][y-1] = 1;
	}
	forsn(i, 1, n+1){
		forsn(j, 1, m+1){
			SP[i][j] = SP[i-1][j]+SP[i][j-1]-SP[i-1][j-1]+pinos[i-1][j-1];
		}
	}
	forsn(i, 1, n+1){
		forsn(j, 1, m+1){
			SF[i][j] = SF[i-1][j]+SF[i][j-1]-SF[i-1][j-1]+frutas[i-1][j-1];
		}
	}
	forn(i, n){
		dp[i][0] = 1-pinos[i][0];
	}
	forn(i, m){
		dp[0][i] = 1-pinos[0][i];
	}
	forsn(i, 1, n){
		forsn(j, 1, m){
			if(pinos[i][j] == 0){
				dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]))+1;
			}
			else dp[i][j] = 0;
		}
	}
	int maxi = -1, base = -1, posX = 1, posY = 1;
	forsn(j, 1, m+1){
		forsn(i, 1, n+1){
			if(pinos[i-1][j-1] == 1) continue;
			int quan = dp[i-1][j-1];
			int act = SF[i][j]-SF[i][j-quan]-SF[i-quan][j]+SF[i-quan][j-quan];
			if(act < maxi) continue;
			int low = 0, high = quan+1;
			while(high-low>1){
				int mid = low+(high-low)/2;
				if(SF[i][j]-SF[i][j-mid]-SF[i-mid][j]+SF[i-mid][j-mid] == act) high = mid;
				else low = mid;
			}
			if(maxi == act && high < base){
				base = high;
				posX = i; posY = j;
			}
			if(maxi < act){
				maxi = act;
				base = high;
				posX = i; posY = j;
			}
		}
	}
	if(f == 0) base = 0;
	cout << posX-base << " " << posY-base << "\n";
	cout << base << "\n";
	cout << maxi << "\n";
}

