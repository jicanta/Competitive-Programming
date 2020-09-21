#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
typedef long long tint;
 
const tint INF = 1e18+1;
const int MOD = 1e9+7;

bool comp(const pair<tint,tint> &a, const pair<tint,tint> &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

bool sortByLen(const pair<tint,tint> &a, const pair<tint,tint> &b){
	if(a.second-a.first+1 == b.second+b.first+1) return a.first < b.first;
	return a.second-a.first+1 > b.second+b.first+1;
}

int main(){
	ifstream cin("socdist.in");
	ofstream cout("socdist.out");
	int n, m; cin >> n >> m;
	vector<pair<tint,tint>> a (m);
	forn(i, m){
		cin >> a[i].first >> a[i].second;
	}
	vector<pair<tint,tint>> copy = a;
	sort(all(a), comp);
	tint low = 0, high = 1e18+1;
	while(high-low > 1){
		tint mid = low+(high-low)/2;
		int cow = 0;
		int lastPos = a[0].first-mid;
		forn(i, m){
			tint pos = lastPos+mid;
			pos = max(pos, a[i].first);
			if(a[i].first<=pos && pos<=a[i].second){
				tint k = (a[i].second-pos)/mid;
				lastPos = pos+mid*k;
				cow++;
				cow+=k;
			}
		}
		if(cow >= n){
			low = mid;
		}else high = mid;
	}
	cout << low << endl;
}
