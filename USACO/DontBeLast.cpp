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

template<class T> inline int sz(T container){
	return (int)container.size();
}
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1e5+5;
const tint INF = 1e18;
const int inf = 2e9;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "notlast"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main(){
	NACHO();
	int n; cin >> n;
	map<string, int> prod;
	vector<string> cows = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
	for(auto &u : cows) prod[u] = 0;
	forn(i, n){
		string name; int p;
		cin >> name >> p;
		prod[name]+=p;
	}
	map<int, int> cont;
	map<int, string> cow;
	for(auto &u : prod){
		cow[u.s] = u.f;
		++cont[u.s];
	}
	auto it = ++cow.begin();
	if(it == cow.end() || cont[it->f] > 1){
		cout << "Tie" << "\n";
	}else{
		cout << cow[it->f] << "\n";
	}
}
