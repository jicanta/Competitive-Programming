#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)	
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vvi = vector<vi>;
using vl = vector<tint>;
using vb = vector<bool>;
 
#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert
 
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7; 
const int mod = 998244353;
const int MX = 1e6+5;
const tint INF = 1e9; 
const int inf = 2e8;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-5;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} 
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redondea p abajo
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

string s;
const tint P = 9973, M1 = 1e9+7, M2 = 1e9+9;
tint hsh1[MX], hsh2[MX], pw1[MX], pw2[MX];

void calc_hash(){
	hsh1[0] = hsh2[0] = pw1[0] = pw2[0] =  1;
	FOR(i, 1, sz(s)+1) pw1[i] = pw1[i-1] * P % M1, pw2[i] = pw2[i-1] * P % M2;
	FOR(i, 1, sz(s)+1){
		hsh1[i] = ((hsh1[i-1] * P) % M1 + s[i-1]) % M1;
		hsh2[i] = ((hsh2[i-1] * P) % M2 + s[i-1]) % M2;
	}
}

tint get_hsh(int l, int r, tint M){
	if(M == M1) return (((hsh1[r+1] - pw1[r-l+1] * hsh1[l] % M) % M) + M) % M;
	else return (((hsh2[r+1] - pw2[r-l+1] * hsh2[l] % M) % M) + M) % M;
}

int main(){
	NACHO();
	int tc; cin >> tc;
	while(tc--){
		cin >> s;
		calc_hash();
		int lst = -1;
		int ret = 0;
		F0R(i, sz(s)){
			if(get_hsh(lst+1, i, M1) == get_hsh(sz(s)-i-1, sz(s)-lst-2, M1) && get_hsh(lst+1, i, M2) == get_hsh(sz(s)-i-1, sz(s)-lst-2, M2)){
				//cout << i << " " << lst << endl;
				++ret;
				lst = i;
			}
		}
		cout << ret << "\n";
	}
}

