#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
  
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
#define dbg cout << "hu" << endl;
 
const tint INF = 1111122222;
const int MOD = 1e9+7;

int dp[21][200001];
int vengo[21][200001];
int pos[200001];
int ret[200001];
 
int main(){
	NACHO;
	ifstream cin("casas.in");
	ofstream cout("casas.out");
	int x, y; cin >> x >> y;
	int n; cin >> n;
	forn(i, n){
		cin >> pos[i];
	}
	forn(i, 21){
		forn(j, n){
			dp[i][j] = -1;
			vengo[i][j] = -1;
		}
	}
	forsn(j, 1, min(x/2, pos[0])+1){
		dp[j][0] = 4*j*j;
	}	
	forsn(i, 1, n){
		forsn(j, 1, min(x/2, pos[i-1])+1){
			int r;
			if(i == n-1) r = min(x/2, y-pos[n-1])+1;
			else r = min(x/2, pos[i])+1;
			r = min(r, pos[i]-pos[i-1]-j+1);
			forsn(k, 1, r){
				if(dp[j][i-1]+4*k*k > dp[k][i]){
					dp[k][i] = dp[j][i-1]+4*k*k;
					vengo[k][i] = j;
				}
			}
		}
	}
	int maxi = -1;
	int id;
	forsn(i, 1, min(x/2,  y-pos[n-1])+1){
		if(dp[i][n-1] > maxi){
			maxi = dp[i][n-1];
			id = i;
		}
	}
	cout << maxi << "\n";
	int st = id;
	int fi = n-1;
	while(fi != -1){
		ret[n-1-fi] = st;
		st = vengo[st][fi];
		fi--;
	}
	for(int i=n-1;i>=0;i--){
		cout << 2*ret[i] << "\n";
	}
}
