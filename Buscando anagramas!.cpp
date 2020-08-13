#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const tint MOD = 1e9+7;
const int MX = 1e5+5; 
const int INF = 1e9; //chequea el INF!!!!!
const long double PI = acos((-1)); 
 
void NACHO(string name = "factory"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int tc;
	cin >> tc;
	while(tc--){
		string a, b;
		cin >> a >> b;
		vi f (26, 0);
		string ret = "";
		string rett = "";
		forn(i, sz(a)) ++f[a[i]-'a'];
		forn(i, sz(b)) --f[b[i]-'a'];
		forn(i, 26){
			if((char)(i+'a') == b[0]) ret+=b;
			forn(j, f[i]) ret+=(char)(i+'a');
		}
		forn(i, 26){
			forn(j, f[i]) rett+=(char)(i+'a');
			if((char)(i+'a') == b[0]) rett+=b;
		}
		cout << min(ret, rett) << "\n";
	}
}

//bs? dp? greedy?
//check long long
//abohotypsu
//abohotypsu
//1
//zaaazzzzzzzzzzzzzaaaaaaaa
//zzaaz
