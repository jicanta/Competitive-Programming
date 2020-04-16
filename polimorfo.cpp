#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 1e6;
const int MOD = 1e9+7;

template<class T> struct MinDeque { 
    int lo = 0, hi = -1;
    deque<pair<T,int>> d;
    void ins(T x){ 
        while(!d.empty() && d.back().first>=x) d.pop_back();
        d.push_back({x,++hi});
    }
    void del(){ 
        if(d.front().second == lo++) d.pop_front();
    }
    T get() { 
        return !d.empty() ? d.front().first : INF; 
    }
};

template<class T> struct MaxDeque{
	int lo = 0, hi = -1;
	deque<pair<T,int>> d;
	void ins(T x){ 
        while(!d.empty() && d.back().first<=x) d.pop_back();
        d.push_back({x,++hi});
    }
    void del(){ 
        if(d.front().second == lo++) d.pop_front();
    }
    T get() { 
        return !d.empty() ? d.front().first : INF; 
    }
};

int dec(int n){
	return n+100000;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	ifstream cin("polimorfo.in");
	ofstream cout("polimorfo.out");
	int n, m; cin >> n >> m;
	vector<int> a (n);
	forn(i, n){
		cin >> a[i];
	}
	if(n<m){
		cout << 0 << "\n";
		return 0;
	}
	MinDeque<int> qMi;
	MaxDeque<int> qMa;
	vector<int> ret;
	vector<int> seen (200001, 0);
	int c = 0;
	forn(i, n){
		if(i > m-1){qMi.del(); qMa.del(); seen[dec(a[i-m])]--; if(seen[dec(a[i-m])] == 0) c--;}
		qMi.ins(a[i]);
		qMa.ins(a[i]);
		if(seen[dec(a[i])] == 0) c++;
		seen[dec(a[i])]++;
		if(c == m && qMi.get() == 1 && qMa.get() == m){
			ret.push_back(i-m+2);
		}
	}
	cout << int(ret.size()) << "\n";
	if(int(ret.size()) < 11){
		for(auto x : ret){
			cout << x << " ";
		}
	}else{
		forn(i, 5){
			cout << ret[i] << " ";
		}
		forsn(i, ret.size()-5, ret.size()){
			cout << ret[i] << " ";
		}
	}
}
