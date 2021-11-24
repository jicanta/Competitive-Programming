#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
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
using vvl = vector<vl>;
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
const int MX = 1e5+5;
const tint INF = 1e18; 
const int inf = 1e9;
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
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } 
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } 
 
void NACHO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int B[MX];
int n;

void upd(int pos, int val){
	for(int x = pos; x <= n; x += x&(-x)){
		B[x] += val;
	}
}

int sum(int pos){
	int ret = 0;
	for(int x = pos; x > 0; x -= x&(-x)){
		ret += B[x];
	}
	return ret;
}

int main(){
    NACHO();
	int q; cin >> n >> q;
	vi a(n+1);
	F0R(i, n){
		cin >> a[i+1];
	}
	sort(all(a));
	FOR(i, 1, n+1) upd(i, a[i] - a[i-1]);
	F0R(assa, q){
		char t; cin >> t;
		if(t == 'F'){
			int c, h; cin >> c >> h;
			int low = 0, high = n+1;
			while(high - low > 1){
				int mid = low + (high - low) / 2;
				if(sum(mid) >= h) high = mid;
				else low = mid;
			}
			int L = high;
			int R = L + c - 1;
			if(R < L) continue;
			if(R >= n){
				upd(L, 1);
				continue;
			}
			int a_r = sum(R);
			low = 0, high = n+1;
			while(high - low > 1){
				int mid = low + (high - low) / 2;
				if(sum(mid) >= a_r) high = mid;
				else low = mid;
			}
			int L2 = high;
			low = 0, high = n+1;
			while(high - low > 1){
				int mid = low + (high - low) / 2;
				if(sum(mid) > a_r) high = mid;
				else low = mid;
			}
			int R2 = high - 1;
			upd(L, 1); upd(L2, -1);
			upd(R2 - (c - (L2 - L)) + 1, 1); upd(R2 + 1, -1);
		}else{
			int l, r; cin >> l >> r;
			int low = 0, high = n+1;
			while(high - low > 1){
				int mid = low + (high - low) / 2;
				if(sum(mid) >= l) high = mid;
				else low = mid;
			}
			int L = high;
			low = 0, high = n+1;
			while(high - low > 1){
				int mid = low + (high - low) / 2;
				if(sum(mid) > r) high = mid;
				else low = mid;
			}
			int R = high - 1;
			cout << max(0, R - L + 1) << "\n";
		}
	}
}

