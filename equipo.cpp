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
const int maxn = 2.5e6+1;

int t[maxn][26];
int fin[maxn];
int depth[maxn];

tint maxi = -1;
string best;
string a;

void dfs(int node=0, int d=0){
	depth[node]+=fin[node];
	forn(i, 26){
		if(t[node][i] != 0){
			a+=(char)('a'+i);
			dfs(t[node][i], d+1);
			if(!a.empty())a.pop_back();
			depth[node]+=depth[t[node][i]];
			
		}
	}
	if(depth[node] > 1 && 1LL*d*d*depth[node] > maxi){
		maxi =  1LL*d*d*depth[node];
		best = a;
	}
}
 
int main(){
	NACHO;
	ifstream cin("equipo.in");
	ofstream cout("equipo.out");
    int sz; cin >> sz;
    int n; cin >> n;
    int m = 1;
	forn(i, n){
		string s;
		cin >> s;
		int u=0;
		for(const auto &d : s) {
			if(t[u][d-'a'] == 0){
				t[u][d-'a']=m++;
			}
			u=t[u][d-'a'];
		}
		++fin[u];
	}
	dfs();
	cout << maxi << "\n";
	cout << best << "\n";
}
