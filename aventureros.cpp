#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
 const int MAXN = 400001;
 int n;
 int t[2*MAXN];
 
 void build(int v, int tl, int tr){
	 if(tl == tr){
		 t[v] = 1;
	 }else{
		 int tm = (tl+tr)/2;
		 build(2*v, tl, tm);
		 build(2*v+1, tm+1, tr);
		 t[v] = t[2*v]+t[2*v+1];
	 }
 }	
 
 void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int find_kth(int v, int tl, int tr, int k) {
    if (k > t[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (t[v*2] >= k)
        return find_kth(v*2, tl, tm, k);
    else 
        return find_kth(v*2+1, tm+1, tr, k - t[v*2]);
}
 
int main(){
	ifstream cin("aventureros.in");
	ofstream cout("aventureros.out");
	NACHO;
	cin >> n;
	int sz = n;
	int ini = 0;
	build(1, 0, n-1);
	forn(i, n-1){
		int a_i; cin >> a_i;
		int act = (ini+a_i) % sz;
		int id = find_kth(1, 0, n-1, act+1);
		update(1, 0, n-1, id, 0);
		sz--;
		ini = act;
	}
	cout << "\n";
	cout << find_kth(1, 0, n-1, 1)+1 << "\n";
}
