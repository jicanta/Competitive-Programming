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
 
const int MOD = 1e9+7;
const int MX = 1000005;
const tint INF = 1e18;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "lifeguards"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct ran{
	tint l, r, id;
	tint re = 0;
};

int main(){
	//Un problema hermoso
	//Se divide en lo siguiente:
	//Primero calculo la union de los n intervalos
	//Luego calculo p c intervalo lo siguiente:
	//Cuanto de este esta cubierto por otros
	//Para ello realizo lo siguiente:
	//Primero me los ordeno por borde izq
	//y tengo una variable que me dice cual es
	//el borde derecho mas lejano (M) que vi hasta ahora
	//Si estoy parado en el borde izq L, y M > L, entonces
	//se que M-L+1 de mi intervalo esta cubierto por otro.
	//Hago lo mismo pero ordenando por borde derecho.
	//Luego la respuesta es la union de todos menos
	//El intervalo que minimiza su largo menos lo que le cubre el resto.	
	NACHO();
	int n; cin >> n;
	vector<ran> a (n);
	forn(i, n){
		cin >> a[i].l >> a[i].r;
		--a[i].r;
		a[i].id = i;
	}	
	sort(all(a), [&](const ran &a, const ran &b){
		if(a.l == b.l) return a.r > b.r;
		return a.l < b.l;
	});
	tint uni = 0;
	ran cur = a[0];
	forsn(i, 1, n){
		if(a[i].l <= cur.r){
			cur.r = max(cur.r, a[i].r);
		}else{
			uni+=cur.r-cur.l+1;
			cur.l = a[i].l;
			cur.r = a[i].r;
		}
	}
	uni+=cur.r-cur.l+1;
	cur = a[0];
	tint mini = INF;
	forsn(i, 1, n){
		a[i].re += max(0LL, cur.r-a[i].l+1);
		cur.r = max(cur.r, a[i].r);
	}
	sort(all(a), [&](const ran &a, const ran &b){
		if(a.r == b.r) return a.l < b.l;
		return a.r > b.r;
	});
	cur = a[0];
	forsn(i, 1, n){
		a[i].re += max(0LL, a[i].r-cur.l+1);
		cur.l = min(cur.l, a[i].l);
	}
	forn(i, n){
		mini = min(mini, max(0LL, a[i].r-a[i].l+1-a[i].re));
	}
	cout << uni-mini << "\n";
}
