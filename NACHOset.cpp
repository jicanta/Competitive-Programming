//set especial que permite estas operaciones:
//agregar un número
//borrar un número
//restar o sumar un número a TODOS los elementos del set
//obtener mínimo o máximo
//Ver https://codeforces.com/blog/entry/58316 para referencia
//Este código es la solución de este problema: https://codeforces.com/contest/923/problem/B
//Descubierto en el TC Argentina 2020
//24/7/2020
//OWO

#include <bits/stdc++.h> 	
 	
using namespace std;	
 	
using tint = long long;	
using ld = long double;	
 	
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)	
#define forn(i, n) forsn(i, 0, n)	
 	
using vi = vector<tint>;	
 	
#define pb push_back	
#define rsz resize	
#define all(x) begin(x), end(x)	
//#define rall(x) rbegin(x), rend(x)	
#define sz(x) (int)(x).size()	
 	
using pi = pair<int,int>;	
#define f first	
#define s second	
#define mp make_pair	
 	
#define DBG(x) cerr << #x << " = " << (x) << endl;	
#define dbg cerr << "HUH" << endl;	
 	
void NACHO(string name = "") { 	
    ios_base::sync_with_stdio(0); cin.tie(0); 	
    //freopen((name+".in").c_str(), "r", stdin); 	
    //freopen((name+".out").c_str(), "w", stdout);	
}	
 	
const int MOD = 1e9+7; // 998244353;	
const int N = 30*3e5+30;	
const int INF = 1e6;	
const ld PI = acos((ld)-1);	

struct NACHOset{
	multiset<tint> s;
	tint sum = 0;
	void add(int n){ s.insert(n+sum); }
	void erase(int n){ s.erase(s.find(n+sum)); }
	void upd(int n){ sum+=n; }
	int query(){ return *s.begin()-sum; }
	int size(){ return sz(s); }
};
 	
int main(){	
	NACHO();	
	NACHOset s;
	int n; cin >> n;
	vi v (n), t (n);
	forn(i, n) cin >> v[i];
	forn(i, n) cin >> t[i];
	forn(i, n){
		s.add(v[i]);
		s.upd(t[i]);
		tint ret = t[i]*s.size();
		while(s.size() > 0 && s.query() < 0){
			int act = s.query();
			ret-=-act;
			s.erase(act);
		}
		cout << ret << " ";
	}
}

