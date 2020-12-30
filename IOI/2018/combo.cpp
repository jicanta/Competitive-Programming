#include "combo.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,tint>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vpi = vector<pi>;
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
const int MX = 1005; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "lightson"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

std::string guess_sequence(int N) {
	//sea s la respuesta que tenes hasta ahira
	//si preguntas s+un caracter
	// lo podes adivinar en a lo sumo 2 queries
	// queremos adivinar en una query (supongo que Y es el del comienzo)
	// preguntas s+AB+s+AX+s+AA+s+B
	// si nos da 2, el proximo es A
	// si nos da 1, es B
	// si nos da 0, es X
	vector<string> p;
	string s;
	int q = press("AX");
	if(q == 1){
		q = press("A");
		if(q){
			s = "A";
			p = {"X", "B", "Y"};
		}else{
			s = "X";
			p = {"A", "B", "Y"};
		}
	}else if(q == 2){
		s = "A";
		p = {"X", "B", "Y"};
	}else{
		q = press("B");
		if(q == 1){	
			s = "B";
			p = {"A", "X", "Y"};
		}else{
			s = "Y";
			p = {"A", "B", "X"};
		}
	}
	F0R(i, N-2){
		q = press(s+p[0]+p[0]+s+p[0]+p[1]+s+p[0]+p[2]+s+p[1]);
		if(q == sz(s)){
			s += p[2];
		}else if(q == sz(s)+1){
			s += p[1];
		}else s += p[0];
	}
	if(N > 1){
		q = press(s+p[0]);
		if(q == sz(s)+1) s += p[0];
		else{
			q = press(s+p[1]);
			if(q == sz(s)+1) s += p[1];
			else s += p[2];
		}
	}
	return s;
}