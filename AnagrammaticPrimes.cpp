#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
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
const int MX = 1000005;
const tint INF = 1e18+5;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "stacking"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}
 
int main(){
	NACHO();
	vi pr = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
	int c;
	while(cin >> c && c != 0){
		auto it = upper_bound(all(pr), c);
		if(97 <= c && c <= 99) cout << 0 << "\n";
		else if(7 <= c && c <= 9) cout << 0 << "\n";
		else if(it-pr.begin() >= sz(pr)) cout << 0 << "\n";
		else cout << *it << "\n";
	}
}

