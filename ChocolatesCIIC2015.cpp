#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
#define esta(x,c) ((c).find(x) != (c).end())
 
const tint MOD = 1e9+7;
const int MX = 2e5+5;
const int INF = 1e9;
const ld PI = acos((ld)(-1)); 
const ld EPS = 1e-9;

void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n;
	cin >> n;
	vi a (n);
	forn(i, n) cin >> a[i];
	function<bool(tint)> can = [&](tint x){
		tint guard = 0;
		forn(i, n){
			if(a[i] > x) guard+=a[i]-x;
			else if(a[i] < x){
				if(guard < x-a[i]) return 0;
				guard-=x-a[i];
			}
		}
		return 1;
	};
	tint low = -1, high = 1e14;
	while(high-low > 1){
		tint mid = low+(high-low)/2;
		if(can(mid)) low = mid;
		else high = mid;
	}
	cout << low << "\n";
}
