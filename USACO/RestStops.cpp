#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
using vl = vector<tint>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1e5+5;
const tint INF = 2e18;
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "reststops"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y, int n, int m){
	return (0<=x && x<n && 0<=y && y<m);
}

int main(){
	NACHO();
	int L, n, j, b;
	cin >> L >> n >> j >> b;
	vector<pi> a (n);
	forn(i, n){
		cin >> a[i].f >> a[i].s;
	}
	sort(all(a));
	tint curJ = 0, curB = 0;
	tint ret = 0;
	int maxi = -inf;
	vector<bool> take (n, 0);
	for(int i = n-1; i >= 0; --i){
		if(a[i].s > maxi){
			take[i] = 1;
			maxi = a[i].s;
		}
	}
	forn(i, n){
		if(take[i]){
			//DBG(curB); DBG(curJ); 
			tint tardaB = (a[i].f-curB)*b;
			tint tardaJ = (a[i].f-curJ)*j;
			//DBG(tardaB); DBG(tardaJ);
			ret+=(tardaJ-tardaB)*a[i].s;
			curB = a[i].f;
			curJ = a[i].f;
		}
	}
	cout << ret << "\n";
}
