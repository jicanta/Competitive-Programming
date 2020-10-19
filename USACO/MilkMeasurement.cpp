#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
using vb = vector<bool>;
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
 
const int MOD = 1e9+7;
const int MX = 5e5+5;
const tint INF = 1e18;
const int inf = 2e9;
const ld PI = acos(ld(-1)); 

void NACHO(string name = "measurement"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct cow{
	tint day, id; string prod;
	tint get(){
		return (prod[0] == '-' ? -1 : 1)*stoi(prod.substr(1, sz(prod)-1));
	}
	bool operator<(const cow &a)const{
		return day < a.day;
	}
};

int main(){
	NACHO();
	int n, g; cin >> n >> g;
	map<tint,tint> prod;
	vector<cow> a (n);
	forn(i, n) cin >> a[i].day >> a[i].id >> a[i].prod;
	sort(all(a));
	tint tot = 0;
	multiset<tint> s;
	map<tint, tint> cont;
	forn(i, n){
		tint id = a[i].id;
		tint sum = a[i].get();
		bool fi = 0;
		if(prod.count(id) == 0){ prod[id] = g; s.insert(g); cont[g] = 1; fi = 1;}
		tint oldMax = *--s.end();
		tint contEra = cont[oldMax];
		bool era = (oldMax == prod[id]);
		if(fi) era = 0;
		--cont[prod[id]];
		s.erase(s.find(prod[id]));
		prod[id]+=sum;
		++cont[prod[id]];
		s.insert(prod[id]);
		tint newMax = *--s.end();
		tint contEs = cont[newMax];
		bool es = (newMax == prod[id]);
		if(es && !era){
			++tot;
		}
		if(era && !es){
			++tot; 
		}
		if(era && es){
			if(sum != 0 && (contEs > 1 || contEra > 1)) ++tot;
		}
	}
	cout << tot << "\n";
}
