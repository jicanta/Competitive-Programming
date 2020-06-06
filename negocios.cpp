#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
 
typedef long long tint;

const int INF = 1e8;
const int MOD = 1e9+7;
const int N = 2001;

struct Ne{
	int x, y, h, m, id; 
	bool operator<(const Ne &a) const{
		return h<a.h;
	}
};

int dist(int x1, int y1, int x2, int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int dp[N+1];
int pa[N+1];

int main(){
	NACHO;
	ifstream cin("negocios.in");
	ofstream cout("negocios.out");
	int n; cin >> n;
	vector<Ne> a (n+1);
	forn(i, n){
	    dp[i+1] = -INF;
		cin >> a[i+1].x >> a[i+1].y >> a[i+1].h >> a[i+1].m;
		a[i+1].id = i;
	}
	a[0].x = 0; a[0].y = 0; a[0].h = -3; a[0].m = 0; a[0].id = -1;
	sort(all(a));
	int maxi = -1;
	forsn(i, 1, n+1){
		forn(j, i+1){
			if(a[j].h+dist(a[i].x, a[i].y, a[j].x, a[j].y)+3 <= a[i].h){
				if(dp[j]+a[i].m > dp[i]){
					pa[a[i].id] = a[j].id;
					dp[i] = dp[j]+a[i].m;
				}
			}
		}
	}
	int st;
	forn(i, n+1){
		if(dp[i] > maxi){
			maxi = dp[i];
			st = a[i].id;
		}
	}
	cout << maxi << "\n";
	vector<int> ret;
	while(st != -1){
		ret.push_back(st);
		st = pa[st];
	}
	reverse(all(ret));
	forn(i, ret.size()){
		cout << ret[i]+1 << " ";
	}
}

