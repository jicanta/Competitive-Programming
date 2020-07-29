#include <bits/stdc++.h>

using namespace std;

using tint = long long;
using ld = long double;

#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
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

const int MX = 2e5+5;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "", bool file = 0) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(file){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

tint choose2(int x){ if(x == 0) return 0; return x*(x-1)/2; }
tint ot(int x){ if(x == 0) return 0; return x*(x+1)/2;  }
 
int main(){
    NACHO();
    int n, m, q; cin >> n >> m >> q;
    vi a (n);
    forn(i, n){
		cin >> a[i];
	}
	vi s (n+1, 0);
	forsn(i, 1, n+1){
		s[i] = (s[i-1] % m + a[i-1 % m])% m;
	}
	vector<vi> cont (m, vi (n+1, 0));
	forsn(i, 1, n+1){
		forn(j, m){
			cont[j][i] = cont[j][i-1]+(s[i] == j);
		}
	}
	forn(i, q){
		int l, r; cin >> l >> r;
		tint ret = 0;
		--l;
		forn(j, m){
			if(j == 0) ret+=ot(cont[j][r]-(l > 0 ? cont[j][l-1] : 0))-(l > 0 ? cont[j][r]-cont[j][l-1] : 0);
			else ret+=choose2(cont[j][r]-(l > 0 ? cont[j][l-1] : 0));
		}
		cout << ret << "\n";
	}
}

