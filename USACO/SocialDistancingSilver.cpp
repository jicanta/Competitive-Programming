#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(tint i = s; i < tint(n); i++)
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
 
const tint MOD = 1e9+7;
const tint mod = 998244353;
const int MX = 1e8+5; 
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
 
void NACHO(string name = "socdist"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}
 
int main(){
    NACHO();
    //nota: abajo dejo mi codigo original en la competencia
	int n, m; cin >> n >> m;
	vector<pl> a (m);
	forn(i, m) cin >> a[i].f >> a[i].s;
	sort(all(a));
	tint low = 0, high = 1e18+1;
	while(high-low > 1){
		tint mid = low+(high-low)/2;
		tint pos = -INF;
		int put = n;
		forn(i, m){
			while(max(a[i].f, pos+mid) <= a[i].s){
				pos = max(a[i].f, pos+mid);
				--put;
			}
		}
		if(put > 0) high = mid;
		else low = mid;
	}
	cout << low << "\n";
}
//OVERFLOW!
//COTAS?
//CHEQUEA LAS CUENTAS

/*
#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
typedef long long tint;
 
const tint INF = 1e18+1;
const int MOD = 1e9+7;

bool comp(const pair<tint,tint> &a, const pair<tint,tint> &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

bool sortByLen(const pair<tint,tint> &a, const pair<tint,tint> &b){
	if(a.second-a.first+1 == b.second+b.first+1) return a.first < b.first;
	return a.second-a.first+1 > b.second+b.first+1;
}

int main(){
	ifstream cin("socdist.in");
	ofstream cout("socdist.out");
	int n, m; cin >> n >> m;
	vector<pair<tint,tint>> a (m);
	forn(i, m){
		cin >> a[i].first >> a[i].second;
	}
	vector<pair<tint,tint>> copy = a;
	sort(all(a), comp);
	tint low = 0, high = 1e18+1;
	while(high-low > 1){
		tint mid = low+(high-low)/2;
		int cow = 0;
		int lastPos = a[0].first-mid;
		forn(i, m){
			tint pos = lastPos+mid;
			pos = max(pos, a[i].first);
			if(a[i].first<=pos && pos<=a[i].second){
				tint k = (a[i].second-pos)/mid;
				lastPos = pos+mid*k;
				cow++;
				cow+=k;
			}
		}
		if(cow >= n){
			low = mid;
		}else high = mid;
	}
	cout << low << endl;
}
*/
