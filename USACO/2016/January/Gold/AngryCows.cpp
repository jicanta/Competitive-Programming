#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,int>;
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
const tint mod = 998244353;
const int MX = 505;
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
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
 
void NACHO(string name = "angry"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vi a;

bool canFirst(int pos, int rad){
	if(pos-rad > a[0]){
		int kill = lower_bound(all(a), pos-rad)-a.begin();
		rad -= 2;
		while(kill != 0){
			int nxt = lower_bound(all(a), a[kill]-rad)-a.begin();
			if(nxt >= kill) return 0;
			kill = nxt;
			rad -= 2;
		}
	}
	return 1;
}

bool canLast(int pos, int rad){
	if(pos+rad < a.back()){
		int kill = upper_bound(all(a), pos+rad)-a.begin()-1;
		rad -= 2;
		while(kill != sz(a)-1){
			int nxt = upper_bound(all(a), a[kill]+rad)-a.begin()-1;
			if(nxt <= kill) return 0;
			kill = nxt;
			rad -= 2;
		}
	}
	return 1;
}

int main(){
	NACHO();
	int n; cin >> n;
	a.rsz(n);
	F0R(i, n) cin >> a[i];
	F0R(i, n) a[i] *= 2;
	sort(all(a)); 
	int low = 0, high = 1000000000;
	while(high-low > 1){
		int mid = low+(high-low)/2;
		int L = a[0], H = a.back()+1;
		while(H-L > 1){
			int M = L+(H-L)/2;
			if(canFirst(M, mid)){
				L = M;
			}else H = M;
		}
		if(canLast(L, mid)){
			high = mid;
		}else low = mid;
	}
	cout << high/2 << (high % 2 == 0 ? ".0" : ".5") << "\n";
}


