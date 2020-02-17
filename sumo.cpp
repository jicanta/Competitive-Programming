#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(tint i=s;i<tint(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
#define dbg cout << "hu" << endl;
 
const tint INF = 110000000;
const tint MOD = 1000000007;

const int N = 11e6+1;  
int n = 11e6+1; 
int t[2 * N];

void build() {  
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) { 
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) { 
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

bool comp(const pair<int,int> &a, const pair<int,int> &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

struct sumo{
	int a, b, id;
	bool operator<(const sumo&otro) const{
		if(a == otro.a){
			return b < otro.b;
		}
		return a < otro.a;
	}
};
 
int main(){
	NACHO;
	ifstream cin("sumo.in");
	ofstream cout("sumo.out");
	int m; cin >> m;
	vector<sumo> a (m);
	forn(i, m){
		cin >> a[i].a >> a[i].b;
		a[i].id = i;
	}
	build();
	sort(all(a));
	int ret[m];
	forn(i, m){
		ret[a[i].id] = query(0, a[i].b+1);
		modify(a[i].b, t[n+a[i].b]+1);
	}
	forn(i, m){
		cout << ret[i] << "\n";
	}
}
