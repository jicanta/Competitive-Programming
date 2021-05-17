#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(tint i = s; i < tint(n); i++)
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
 
 
void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

struct frac{
	tint num, den;
	bool operator< (const frac &a) const{
		return (num*a.den < a.num*den);
	}
};

struct prob{
	tint p, f, t;
	bool operator< (const prob &a) const{
		return frac{a.f, a.t} < frac{f, t};
	}
};

int main(){
	int n, T;
	cin >> n >> T;
	vector<prob> a (n);
	forn(i, n) cin >> a[i].p >> a[i].f >> a[i].t;
	sort(all(a));
	vi dp (T+1, 0);
	for(int i = 0; i< n; ++i){
		for(int j = T; j>=0;--j){
			if(j+a[i].t <= T){
				dp[j+a[i].t] = max(dp[j+a[i].t], dp[j]+(max(0LL, a[i].p-((j+a[i].t)*a[i].f))));
			}
		}
	}
	tint maxi = 0;
	forn(i, T+1){
		maxi = max(maxi, dp[i]);
	}
	cout << maxi << "\n";		
}
