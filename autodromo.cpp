#include <bits/stdc++.h> 
 
using namespace std;
 
#define forsn(i, s, n) for(tint i=s;i<tint(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define dbg cerr << "HU" << endl;
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
typedef long long tint;
 
const int INF = 11000;
const tint MOD = 1000000007;
const int MAXN = 60001;

int t[4*MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int qry(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return qry(v*2, tl, tm, l, min(r, tm))
           + qry(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void upd(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            upd(v*2, tl, tm, pos, new_val);
        else
            upd(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int ql[100001], qr[100001];
int qll[100001], qrr[100001];

struct event{
	int x1, y1,y2, t;
	bool operator<(const event &o)const{
		if(x1 == o.x1) return y1 < o.y1;
		return x1 < o.x1;
	}
};

int main(){
	NACHO;
	ifstream cin("autodromo.in");
	ofstream cout("autodromo.out");
	int n; cin >> n;
	forn(i, n){
		cin >> ql[i] >> qr[i];
	}
	build(1, 0, MAXN);
	vector<event> ev;
	forn(i, n-1){
		if(qr[i] == qr[i+1]){
			ev.push_back({min(ql[i], ql[i+1]), qr[i], qr[i] ,1});
			ev.push_back({max(ql[i], ql[i+1]), qr[i], qr[i]  ,2});
		}
	}
	if(qr[n-1] == qr[0]){
		ev.push_back({min(ql[0], ql[n-1]), qr[0], qr[0] ,1});
		ev.push_back({max(ql[0], ql[n-1]), qr[0], qr[0]  ,2});
	}
	int m; cin >> m;
	forn(i, m){
		cin >> qll[i] >> qrr[i];
	}
	forn(i, m-1){
		if(qll[i] == qll[i+1]){
			ev.push_back({qll[i],  min(qrr[i], qrr[i+1]), max(qrr[i], qrr[i+1]), 3});
		}
	}
	if(qll[0] == qll[m-1]){
		ev.push_back({qll[0], min(qrr[0], qrr[m-1]), max(qrr[0], qrr[0]), 3});
	}
	sort(all(ev));
	int ret = 0;
	forn(i, ev.size()){
		if(ev[i].t == 3){
			ret+=qry(1, 0, MAXN, ev[i].y1+1, ev[i].y2-1);
		}else if(ev[i].t == 1){
			upd(1, 0, MAXN, ev[i].y1, 1);
		}else{
			upd(1,0,MAXN, ev[i].y1, -1);
		}
	}
	build(1, 0, MAXN);
	ev.clear();
	forn(i, n-1){
		if(ql[i] == ql[i+1]){
			ev.push_back({ql[i],  min(qr[i], qr[i+1]), max(qr[i], qr[i+1]), 3});
		}
	}
	if(ql[n-1] == ql[0]){
		ev.push_back({ql[0],  min(qr[0], qr[n-1]), max(qr[0], qr[n-1]), 3});
	}
	forn(i, m-1){
		if(qrr[i] == qrr[i+1]){
			ev.push_back({min(qll[i], qll[i+1]), qrr[i], qrr[i] ,1});
			ev.push_back({max(qll[i], qll[i+1]), qrr[i], qrr[i]  ,2});
		}
	}
	if(qrr[m-1] == qrr[0]){
		ev.push_back({min(qll[0], qll[m-1]), qrr[0], qrr[0] ,1});
		ev.push_back({max(qll[0], qll[m-1]), qrr[0], qrr[0]  ,2});
	}
	sort(all(ev));
	forn(i, ev.size()){
		if(ev[i].t == 3){
			ret+=qry(1, 0, MAXN, ev[i].y1+1, ev[i].y2-1);
		}else if(ev[i].t == 1){
			upd(1, 0, MAXN, ev[i].y1, 1);
		}else{
			upd(1,0,MAXN, ev[i].y1, -1);
		}
	}
	cout << ret << "\n";
}

