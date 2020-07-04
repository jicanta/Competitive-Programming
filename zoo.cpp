#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
 
const int INF = 40000000;
const int MOD = 1e9+7;
const int N = 2001;

int main(){
	NACHO;
	ifstream cin("zoo.in");
	ofstream cout("zoo.out");
	int e, m, h; cin >> e >> m >> h;
	vector<int> agr (10001);
	forn(i, e){
		int a, b; cin >> a >> b;
		agr[a] = b;
	}
	vector<int> a (m), b (h);
	forn(i, m) cin >> a[i];
	forn(i, h) cin >> b[i];
	int cont = 0;
	int lost = 0;
	forn(i, min(m,h)) if(a[i] == b[i]) cont++;
	vector<int> v (min(m,h), -INF);
	forn(i, min(m,h)){
		if(a[i] != b[i] && abs(agr[a[i]]-agr[b[i]]) >= 4) lost++;
		else v[i] = 1;
	}
	int maxi = 0, sum = 0;
	forn(i, min(m,h)){
		sum = max(v[i], v[i]+sum);
		maxi = max(maxi, sum);
	}
	cout << cont << " " << lost << " " << maxi << "\n";
}
