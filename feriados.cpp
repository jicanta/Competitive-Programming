//Think twice, code once 
//tzuyu ORZ

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 1000000;
const long double PI = 3.141592653;

int main(){
	NACHO;
	int n, f, d; cin >> n >> f >> d;
	vector<int> a (f, 1);
	forn(i, n){
		int x; cin >> x;
		a[x-1] = 0;
	}
	int S[f];
	S[0] = 0;
	forsn(i, 1, f+1) S[i] = S[i-1]+a[i-1];
	int ret = 0;
	forn(i, f){
		int low = i, high = f+1;
		while(high-low > 1){
			int mid = low+(high-low)/2;
			if(S[mid]-S[i] > d) high = mid;
			else low = mid;
		}
		ret = max(ret, low-i);
	}
	cout << ret << "\n";
}

