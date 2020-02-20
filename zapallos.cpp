#include <bits/stdc++.h>

using namespace std;
 
typedef long long tint;
  
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 1111122222;
const int MOD = 1e9+7;

int dp[21][1205];
int S[21][1205];
int tam[21];
pair<int,int> vengo[21][1205];
 
int main(){
	NACHO;
	ifstream cin("zapallos.in");
	ofstream cout("zapallos.out");
	int n, w; cin >> n >> w;
	forn(i, n){
		int k; cin >> k;
		tam[i] = k;
		vector<int> p (k);
		forn(j, k){
			cin >> p[j];
			p[j] = 10-p[j];
		}
		forsn(j, 1, k+1){
			S[i][j] = S[i][j-1]+p[j-1];
		}
	}
	forn(i, n){
		forn(j, w+1){
			dp[i][j] = -1;
		}
	}
	forn(i, min(w, tam[0])+1){
		dp[0][i] = S[0][i];
	}
	forn(i, n){
		forn(j, w+1){
			vengo[i][j] = {-1,0};
		}
	}
	forsn(i, 1, n){
		forn(j, min(w, tam[i])+1){
			forn(k, w+1){
				if(k-j >= 0){
					if(dp[i-1][k-j]+S[i][j] > dp[i][k]){
						dp[i][k] = S[i][j]+dp[i-1][k-j];
						vengo[i][k] = {i-1, k-j};
					}
				}
			}
		}
	}
	int best = -1, compro;
	forn(i, w+1){
		if(dp[n-1][i] > best){
			best = dp[n-1][i];
			compro = i;
		}
	}
	cout << best << " " << compro << "\n";
	int st = n-1;
	vector<int> ret;
	while(st != -1){
		auto s = vengo[st][compro];
		ret.push_back(compro-s.second);
		st = st-1;
		compro = s.second;
	}
	for(int i=n-1;i>=0;i--){
		cout << ret[i] << " ";
	}
}
 
