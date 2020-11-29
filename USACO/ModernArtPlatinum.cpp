#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define trav(a, x) for(auto& a : x)
 
using vi = vector<int>;
using vl = vector<tint>;
using vb = vector<bool>;
#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert
#define esta(x,c) ((c).find(x) != (c).end())
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const tint mod = 998244353;
const int MX = 1e3+6; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "art"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int S[MX][MX];

int query(int a, int b, int c, int d){
	return S[c][d]-S[a-1][d]-S[c][b-1]+S[a-1][b-1];
}

int main(){
	NACHO();
	//considera dos rectangulos formados por colores
	//si no se intersecan, entonces no sabemos nada sobre cual fue primero
	//Si tengo algo de la pinta
	//RRR
	//RSS
	//RRR
	//Se que R fue pintado antes que S
	//En particular, R fue pintado primero sii
	//En ningun rectangulo de otro color existe un pixel de color R
	int tot = 0;
	int n; cin >> n;
	bool allzero = 1;
	vb seen (n*n+1, 0);
	vector<vi> a (n, vi (n));
	forn(i, n) forn(j, n) cin >> a[i][j];
	vi U (n*n+1, inf), D (n*n+1, -inf), L (n*n+1, inf), R (n*n+1, -inf);
	forn(i, n){
		forn(j, n){
			if(a[i][j] > 0) allzero = 0;
			if(!seen[a[i][j]]){
				seen[a[i][j]] = 1;
				++tot;
			}
			U[a[i][j]] = min(i+1, U[a[i][j]]);
			D[a[i][j]] = max(i+1, D[a[i][j]]);
			L[a[i][j]] = min(j+1, L[a[i][j]]);
			R[a[i][j]] = max(j+1, R[a[i][j]]);
		}
	}
	if(allzero){
		cout << 0 << "\n";
		return 0;
	}
	forsn(i, 1, n*n+1){
		if(U[i] == inf) continue;
		++S[U[i]][L[i]];
		++S[D[i]+1][R[i]+1];
		--S[U[i]][R[i]+1];
		--S[D[i]+1][L[i]];
	}
	forsn(i, 1, n+1){
		forsn(j, 1, n+1){
			S[i][j] += S[i][j-1]+S[i-1][j]-S[i-1][j-1];
		}
	}
	vb possible (n*n+1, 1);
	forsn(i, 1, n+1){
		forsn(j, 1, n+1){
			if(S[i][j] > (tot > 2 ? 1 : 0)) possible[a[i-1][j-1]] = 0; 
		}
	}
	int ret = 0;
	forsn(i, 1, n*n+1) if(possible[i]) ++ret;
	cout << ret << "\n";
}
