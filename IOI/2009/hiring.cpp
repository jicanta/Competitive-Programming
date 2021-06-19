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
const int MX = 4005;
const tint INF = 1e18; 
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

struct Frac{
	tint a, b;
	bool operator<(const Frac& o)const{
		if(a*o.b == o.a*b) return b < o.b;
		return a*o.b < o.a*b;
	}
};

struct Cand{
	tint s, q, id;
	bool operator<(const Cand& o)const{
		return Frac{s, q} < Frac{o.s, o.q};
	}
};

int main(){
	NACHO();
	// dado un conjunto de workers
	// tiene que existir un x tal que a cada
	// uno le pago x*Qi.
	// Demo:
	// Si a Q1 = 3 y Q2 = 9, debo pagarle a 2 el triple
	// que lo que le pague a 1, es decir 3*x*Q1=x*Q2
	// a su vez, para cada trabajador queremos que x*Qi >= Si,
	// de donde x >= Si/Qi.
	// en el conjunto, el x que debemos elegir es max(Si/Qi) para todo i,
	// dado que esto nos asegura poder pagarles a todos.
	// comenzamos ordenando a los workers
	// por Si/Qi en orden ascendente.
	int n; tint w; cin >> n >> w;
	vector<Cand> a(n);
	F0R(i, n) cin >> a[i].s >> a[i].q, a[i].id = i+1;
	sort(all(a));
	priority_queue<pl> q;
	double cost = 0LL;
	int max_size = 0;
	double min_cost = INF;
	int pos_max = -1;
	F0R(i, n){
		q.push(mp(a[i].q, a[i].id));
		cost += a[i].q;
		// mientras que el costo total sea mayor a mi w,
		// tengo que sacar al de mayor q (ya que es el que mas aumenta mi respuesta).
		// cost*si
		while(1LL*cost*a[i].s > 1LL*w*a[i].q){
			cost -= q.top().f;
			q.pop();
		}
		double pay = (double)a[i].s/(double)a[i].q;
		if(ckmax(max_size, sz(q))){
			pos_max = i;
			min_cost = cost*pay;
		}else if(sz(q) == max_size && ckmin(min_cost, cost*pay)){
			pos_max = i;
		}
	}
	while(sz(q)) q.pop();
	cout << max_size << "\n";
	cost = 0LL;
	F0R(i, n){
		q.push(mp(a[i].q, a[i].id));
		cost += a[i].q;
		while(1LL*cost*a[i].s > 1LL*w*a[i].q){
			cost -= q.top().f;
			q.pop();
		}
		if(i == pos_max){
			while(sz(q)) cout << q.top().s << "\n", q.pop();
			return 0;
		}
	}
}

