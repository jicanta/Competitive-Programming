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
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
 
using pi = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1000005;
const tint INF = 1e18;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "rental"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n, m, r; cin >> n >> m >> r;
	vi milk (n);
	forn(i, n) cin >> milk[i];
	vector<pi> buy (m);
	forn(i, m) cin >> buy[i].f >> buy[i].s;
	vi rent (r);
	forn(i, r) cin >> rent[i];
	sort(rall(rent));
	sort(rall(milk));
	sort(rall(buy), [&](const pi &a, const pi &b){
		return a.s < b.s;
	});
	//Creo que siempre voy a querer vender un prefijo de las vacas ordenadas por leche...
	//Tu error fue el siguiente: vos sorteabas a los shops por compro*precio.
	//Tenías que sortear por precio, y por cada vaca vender hasta que te quedas sin leche.
	vi sumRent (r+1, 0);
	forsn(i, 1, r+1) sumRent[i] = sumRent[i-1]+rent[i-1];
	vi sumMilkeando (n);
	vi used (m, 0);
	int llegue = 0;
	forn(i, n){
		tint leche = milk[i];
		tint act = (i == 0 ? 0 : sumMilkeando[i-1]);
		forsn(j, llegue, m){
			tint Act = min(buy[j].f-used[j], leche);
			used[j]+=Act;
			leche-=Act;
			act+=buy[j].s*Act;
			if(leche == 0){ llegue = j; break;}
		}
		sumMilkeando[i] = act;
	}
	tint maxi = 0;
	forn(i, n){
		maxi = max(maxi, sumMilkeando[i]+(n-i-1 > r ? 0 : sumRent[n-i-1]));
	}
	cout << maxi << "\n";
}


