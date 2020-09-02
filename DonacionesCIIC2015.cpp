#include <bits/stdc++.h> 	

using namespace std;	

using tint = long long;	
using ld = double;	
 	
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)	
#define forn(i, n) forsn(i, 0, n)	
 	
using vi = vector<tint>;	
 	
#define pb push_back	
#define rsz resize	
#define all(x) begin(x), end(x)	
#define sz(x) (int)(x).size()	
 	
using pi = pair<int,int>;	
#define f first	
#define s second	
#define mp make_pair	
 	
#define DBG(x) cerr << #x << " = " << (x) << endl;	
#define dbg cerr << "HUH" << endl;	
 	
const int MOD = 1e9+7; //998244353;
const int MX = 1000+5;	
const int INF = 1e9;	
const ld PI = acos((ld)-1);	
const ld EPS = 1e-9;
 
void NACHO(string name = "balompie") { 	
    ios_base::sync_with_stdio(0); cin.tie(0); 	
    //freopen((name+".in").c_str(), "r", stdin); 	
    //freopen((name+".out").c_str(), "w", stdout);	
}	

struct segtree{
	int size;
	vi st;
	
	void init(int n){
		size = 1;
		while(size < n){
			size*=2;
		}
		st.assign(2*size, 0);
	}
	
	void update(int pos, int val, int node, int tl, int tr){
		if(tr-tl == 1){
			st[node] += val;
			return;
		}	
		int tm = (tl+tr)/2;
		if(pos < tm){
			update(pos, val, 2*node+1, tl, tm);
		}else{
			update(pos, val, 2*node+2, tm, tr);
		}
		st[node] = st[2*node+1]+st[2*node+2];
	}
	
	void update(int pos, int val){
		update(pos, val, 0, 0, size);
	}
	
	tint sum(int node, int tl, int tr, int l, int r){
		if(tl >= r || tr <= l) return 0;
		if(l <= tl && tr <= r) return st[node];
		int tm = (tl+tr)/2;
		return sum(2*node+1, tl, tm, l, r)+sum(2*node+2, tm, tr, l, r);
	}
	
	tint sum(int l, int r){ 
		return sum(0, 0, size, l, r);
	}
};

struct rang{
	int l, r; tint w;
};

int main(){
	NACHO();	
	int n, q;
	cin >> n;
	segtree L;
	segtree R;
	L.init(1000001); R.init(1000001);
	vector<rang> a (n);
	tint sum = 0;
	forn(i, n){
		cin >> a[i].l >> a[i].r >> a[i].w;
		--a[i].l; --a[i].r;
		L.update(a[i].l, a[i].w);
		R.update(a[i].r, a[i].w);
		sum+=a[i].w;
	}
	cin >> q;
	forn(assfda, q){
		int type;
		cin >> type;
		if(type == 1){
			int l, r;
			cin >> l >> r;
			cout << sum-L.sum(r, L.size)-R.sum(0, l-1) << "\n";
		}else{
			int ind, l, r; tint c;
			cin >> ind >> l >> r >> c;
			--ind;
			L.update(a[ind].l, -a[ind].w);
			R.update(a[ind].r, -a[ind].w);
			sum-=a[ind].w;
			a[ind] = {l-1, r-1, c};
			L.update(a[ind].l, a[ind].w);
			R.update(a[ind].r, a[ind].w);
			sum+=a[ind].w;
		}
	}
}



