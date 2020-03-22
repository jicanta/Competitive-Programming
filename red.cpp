#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
#define dbg cout << "hu" << endl;
 
const int INF = 50000001;
const int MOD = 1000000007;

int parent[1000001];
int size[1000001];

void make_set(int v){
	parent[v] = v;
	size[v] = 1;
}

int find_set(int v){
	if(v == parent[v]){
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b){
	a = find_set(a); b = find_set(b);
	if(a != b){
		if(size[a] < size[b]) swap(a,b);
		parent[b] = a;
		size[a]+=size[b];
	}
}

int main(){
	NACHO;
	ifstream cin("red.in");
	ofstream cout("red.out");
	char c;
	forn(i, 1000001){
		make_set(i);
	}
	while(cin >> c && c != 'F'){
		int k, kk; cin >> k >> kk;
		if(c == 'C'){
			union_set(k,kk);
		}else{
			if(find_set(k) == find_set(kk)){
				cout << "S" << "\n";
			}else cout << "N" << "\n";
		}
	}
}
