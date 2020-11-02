#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1e5+5;
const tint INF = 2e18;
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "protesta"){
    ios_base::sync_with_stdio(0); cin.tie(0);
   // freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
bool valid(int x, int y, int n, int m){
	return (0<=x && x<n && 0<=y && y<m);
}
 
int main(){
	NACHO();
	int n, m; cin >> n >> m;
	vi rates (n);
	vi w (m);
	forn(i, n) cin >> rates[i];
	forn(i, m) cin >> w[i];
	tint tot = 0;
	set<int> av;
	forn(i, n) av.insert(i);
	map<int,int> garage;
	queue<int> q;
	forn(i, 2*m){
		int x; cin >> x;
		if(x > 0){
			if(av.empty()){
				q.push(x-1);
			}else{
				auto it = av.begin();
				tot+=w[x-1]*rates[*it];
				//cout << "AA "  << w[x-1]*rates[*it] << "\n";
				garage[x-1] = *it;
				av.erase(it);
			}
		}else{
			x = abs(x);
			--x;
			if(q.empty()){ av.insert(garage[x]); continue;}
			auto s = q.front();
			garage[s] = garage[x];
			tot+=w[s]*rates[garage[s]];
			q.pop();
		}
	}
	cout << tot << "\n";
}
