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

int main(){
	NACHO();
	int n;
	cin >> n;
	vi a (2*n);
	forn(i, 2*n) cin >> a[i];
	//Imagina que tenes n+1 botones, y apretar el i-esimo boton corresponde a cambiar el estado de los botones
	//en el rango [i;i+n). Ahora bien, esta claro que apretar dos botones consecutivos solamente cambia el estado
	//del boton i y el boton i+n-1. Por lo tanto, vamos por cada boton y vemos si nos conviene o no apretarlo.
	//Una observacion importante es que hay que probar hacer eso tambien con el arreglo en el que invertimos
	//el rango [2*n-n-1;2*n].
	vi b = a;
	forsn(i, n, 2*n){
		b[i] = -a[i];
	}
	function<int(vi)> calc = [&](vi a){
		tint tot = 0;
		forn(i, n){
			tot+=max(a[i]+a[i+n], -a[i]-a[i+n]);
		}
		return tot;
	};
	cout << max(calc(a), calc(b)) << "\n";
}
