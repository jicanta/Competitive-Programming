#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
  
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 200000;
const int MOD = 1e9+7;
const int N = 100001;

pair<tint,tint> vals(tint a1, tint b1, tint c1, tint a2, tint b2, tint c2){
	return {((c1*b2) - (b1*c2))/((a1*b2)-(b1*a2)), ((a1*c2) - (c1*a2))/((a1*b2) - (b1*a2))};
}

int main(){
	NACHO;
	ifstream cin("ladrillos.in");
	ofstream cout("ladrillos.out");
	int n; cin >> n;
	vector<tint> a (n), b (n);
	vector<string> val (n);
	forn(i, n) cin >> val[i];
	if(n <= 2){
		if(n == 1 && val[0] == "*"){
			val[0] = "1";
		}
		if(n == 2){
			if(val[0] == "*") val[0] = "1";
			if(val[1] == "*") val[1] = "2";
		}
		forn(i, n){
			cout << val[i] << " ";
		}
		return 0;
	}
	a[0] = 1; b[0] = 0;
	a[1] = 0; b[1] = 1;
	forsn(i, 2, n){
		a[i] = a[i-1]+a[i-2];
		b[i] = b[i-1]+b[i-2];
	}
	tint a1 = -1, b1 = -1, c1 = -1;
	tint a2 = -1, b2 = -1, c2 = -1;
	forn(i, n){
		if(val[i] != "*"){
			if(a1 == -1){
				a1 = a[i];
				b1 = b[i];
				c1 = stol(val[i]);
			}else if(a2 == -1){
				a2 = a[i];
				b2 = b[i];
				c2 = stol(val[i]);
			}
		}
	}
	if(a1 == -1){
		tint o = 1, b = 1;
		cout << o << " " << b << " ";
		forsn(i, 2, n){
			cout << o+b << " ";
			int c = o;
			o = b;
			b = b+c;
		}
		return 0;
	}
	pair<tint,tint> get = vals(a1, b1, c1, a2, b2, c2);
	tint A = get.first;
	tint B = get.second;
	forn(i, n){
		cout << a[i]*A+b[i]*B << " ";
	}
}
