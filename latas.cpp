#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define dbg cerr << "HU" << endl;
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
 
typedef long long tint;
typedef long double ld;
 
const int INF = 190000000;
const int MOD = 1e9+7;
const int block = 448;


int main(){
	NACHO;
	ifstream cin("latas.in");
	ofstream cout("latas.out");
	int n; cin >> n;
	vector<vector<int>> tab (3*n, vector<int> (3*n, 0));
	int tot = 0;
	forn(i, n){
		forn(j, i+1){
			cin >> tab[i][j];
			tot+=tab[i][j];
		}
	}
	if(n == 1){
		cout << 0 << "\n";
		return 0;
	}
	vector<vector<int>> SH (3*n, vector<int> (3*n, 0));
	forn(i, 3*n){
		int suma = 0;
		forn(j, n){
			suma+=tab[i][j];
		}
		SH[i][0] = suma;
		forsn(j, 1, 2*n){
			SH[i][j] = SH[i][j-1]-tab[i][j-1]+tab[i][j+n];
		}
	}
	vector<vector<int>> SD (3*n, vector<int> (3*n, 0));
	forn(i, 3*n){
		int suma = 0;
		forn(j, i+1){
			suma+=tab[i-j][j];
		}
		SD[i][0] = suma;
		forsn(j, 1, i){
			SD[i-j][j] = SD[i-j+1][j-1]-tab[i-j+1][j-1];
		}
	}
	int maxi = 0;
	vector<vector<int>> ans (3*n, vector<int> (3*n, 0));
	forn(j, 3*n){
		ans[n-1][j] = SH[n-1][j];
	}
	for(int i=2*n-2;i>=0;i--){
		forn(j, 3*n){
			ans[i][j] = ans[i+1][j]+SH[i][j]-SD[i+n][j];
			maxi = max(maxi, ans[i][j]);
		}
	}
	cout << tot-maxi << "\n";
}


