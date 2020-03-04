#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
#define dbg cout << "hu" << endl;
 
const tint INF = 11000000;
const int MOD = 1000000007;

bool comp(const pair<int,int> &a, const pair<int,int> &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main(){
	NACHO;
	ifstream cin("mesadas.in");
	ofstream cout("mesadas.out");
	int n; cin >> n;
	vector<pair<int,int>> a (n);
	forn(i, n){
		int x, y; cin >> x >> y;
		if(y < x) swap(x,y);
		a[i] = {x,y};
	}
	sort(rall(a));
	set<int> Y;
	int cont = 0;
	forn(i, n){
		if(Y.empty()){
			Y.insert(a[i].second);
			cont++;
		}else{
			auto it = Y.lower_bound(a[i].second);
			if(it == Y.end()){
				Y.insert(a[i].second);
				cont++;
			}else{
				Y.erase(Y.find(*it));
				Y.insert(a[i].second);
			}
		}
	}
	cout << cont << "\n";
}
