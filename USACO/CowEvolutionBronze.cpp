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
const int mod = 998244353;
const int MX = 25+5; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
template<class T> bool valid(T x, T y, T n, T m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
void NACHO(string name = "evolution"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int n;
vector<string> a[MX];
set<string> S;

bool check(string u, string v){
	int soloU = 0, soloV = 0, ambos = 0;
	forn(i, n){
		bool solou = 0, solov = 0, amboss = 0;
		bool iniu = 0, iniv = 0;
		trav(act, a[i]){
			if(act == u) iniu = 1;
			if(act == v) iniv = 1;
		}
		solov = iniv; solou = iniu;
		trav(act, a[i]){
			if(act == u && iniv) solov = 0;
			if(act == v && iniu) solou = 0;
		}
		if(!solou && !solov && iniu && iniv) ambos = 1;
		soloU+=(int)(solou);
		soloV+=(int)(solov);
		ambos+=(int)(amboss);
	}
	if(soloU > 0 && ambos > 0 && soloV > 0) return 0;
	return 1;
}
 
int main(){
	NACHO();
	//Si una poblacion es A-B
	//no puede haber una que sea A y otra que sea B.
	//ya que o A esta arriba de B o B esta arriba de A.
	//https://ide.thecodingwizard.me/#-MM8Yr-utoYACVSKtB7L
	cin >> n;
	forn(i, n){
		int k; cin >> k;
		string s;
		forn(j, k) { cin >> s; a[i].pb(s); S.insert(s); }
	}
	bool ok = 1;
	trav(u, S){
		trav(v, S){
			//if(u == v) continue;
			if(!check(u, v)){ ok = 0;}
		}
	}
	if(ok) cout << "yes" << "\n";
	else cout << "no" << "\n"; 
}
/*
3
2 A B
1 A
1 B
 */
