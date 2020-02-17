#include <bits/stdc++.h> 
 
using namespace std;

typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
#define dbg cout << "hu" << endl;
 
const int INF = 11000000;
const int MOD = 1000000007;
const int N = 111;  
int m = 111;  
vector<int> t (2*N, 0);

void build() {  
  for (int i = m - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  
  for (t[p += m] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) { 
  int res = 0;
  for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

struct estacion{
	int mini, maxi, id;
	bool operator<(const estacion &otro) const{
		if(mini == otro.mini) return maxi > otro.maxi;
		return mini < otro.mini;
	}
};

int main(){
	NACHO;
	ifstream cin("clima.in");
	ofstream cout("clima.out");
	int n; cin >> n;
	vector<estacion> a (n);
	build();
	forn(i, n){
		int x; cin >> x;
		int estMax = -52, estMin = 62;
		forn(askask, x){
			int mi, ma; cin >> mi >> ma;
			estMin = min(estMin, mi);
			estMax = max(estMax, ma);
		}
		a[i] = {estMin, estMax, i};
	}
	sort(rall(a));
	vector<int> res (n);
	sort(rall(a));
	t.clear(); t.resize(2*N, 0);
	build();
	forn(i, n){
		int ret = 0;
		if(i != 0 && a[i].mini == a[i-1].mini && a[i].maxi == a[i-1].maxi) res[a[i].id] += res[a[i-1].id];
		else{
			ret+=query(0, a[i].maxi+51);
			res[a[i].id] = ret;
		}
		modify(a[i].maxi+50,  t[a[i].maxi+m+50]+1);
	}
	int maxVal = -1;
	forn(i, n){
		maxVal = max(res[a[i].id], maxVal);
	}
	t.clear(); t.resize(2*N, 0);
	build();
	vector<int> cont (n, 0);
	forn(i, n){
		if(res[a[i].id] == maxVal){
			cont[a[i].id]+=query(a[i].maxi+51, 111);
		}
		modify(a[i].maxi+50,  t[a[i].maxi+m+50]+1);
	}
	sort(all(a));
	t.clear(); t.resize(2*N, 0);
	build();
	forn(i, n){
		if(res[a[i].id] == maxVal){
			cont[a[i].id]+=query(0, a[i].maxi+50);
		}
		modify(a[i].maxi+50, t[a[i].maxi+m+50]+1);
	}
	forn(i, n){
		if(res[i] == maxVal){
			cout << i+1 << " " << cont[i] << "\n";
		}
	}
}


