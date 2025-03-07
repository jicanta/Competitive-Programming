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

tint dp[200001][41];
int vengo[200001][41];
 
int main(){
	NACHO;
	ifstream cin("casas.in");
	ofstream cout("casas.out");
	int x, y; cin >> x >> y;
	int n; cin >> n;
	vector<int> pos (n);
	forn(i, n){
		cin >> pos[i];
	}
	forn(i, n){
		forn(j, 41){
			dp[i][j] = -1;
			vengo[i][j] = -1;
		}
	}
	forsn(j, 1, min(x/2, pos[0])+1){
		dp[0][j] = 4*j*j;
	}	
	forsn(i, 1, n){
		forsn(j, 1, min(x/2, pos[i-1])+1){
			int r;
			if(i == n-1) r = min(x/2, y-pos[n-1])+1;
			else r = min(x/2, pos[i])+1;
			r = min(r, pos[i]-pos[i-1]-j+1);
			forsn(k, 1, r){
				if(dp[i-1][j]+4*k*k > dp[i][k]){
					dp[i][k] = dp[i-1][j]+4*k*k;
					vengo[i][k] = j;
				}
			}
		}
	}
	tint maxi = -1;
	int id;
	forsn(i, 1, min(x/2,  y-pos[n-1])+1){
		if(dp[n-1][i] > maxi){
			maxi = dp[n-1][i];
			id = i;
		}
	}
	vector<int> ret;
	cout << maxi << "\n";
	int st = id;
	int fi = n-1;
	while(fi != -1){
		ret.push_back(2*st);
		st = vengo[fi][st];
		fi--;
	}
	reverse(all(ret));
	forn(i, ret.size()){
		cout << ret[i] << "\n";
	}
}
