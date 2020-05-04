#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
 
typedef long long tint;
typedef long double ld;
 
const int INF = 190000000;
const int MOD = 1e9+7;
 
int main(){
	//La idea es esencialmente crear grupos de tamaño lo más cercano posible a la capacidad, pero hay que tener en cuenta cuántos grupos
	//ya se formaron.
	ifstream cin("toneles.in");
	ofstream cout("toneles.out");
	int cap; cin >> cap;
	int n; cin >> n;
	int a[n];
	forn(i, n){
		cin >> a[i];
	}
	tint cur = 0;
	vector<int> ids;
	int prev = 0;
	while(a[prev] == 0){
		prev++;
	}
	forsn(i, prev, n){
		cur+=a[i];
		if(cur > cap*int(ids.size()+1)){
			ids.push_back(prev+1);
			prev = i;
		}
	} 
	ids.push_back(prev+1);
	int ret=0;
	for(auto id : ids){
		ret+=(n+1-id);
	}
	cout << ret << "\n";
	cout << ids.back() << "\n";
}
/*
5
5
5 2 1 4 2
*/

