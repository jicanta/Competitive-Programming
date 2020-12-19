#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
using pi = pair<tint,tint>;
using pl = pair<tint,tint>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vl = vector<tint>;
using vb = vector<bool>;

#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert


#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int mod = 998244353;
const int MX = 2005; 
const tint INF = 1e18; 
const int inf = 2e9;
const ld PI = acos(ld(-1)); 
const ld eps = 1e-8;
 
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}
 
bool valid(int x, int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}
 
int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); } //redondea p arriba
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); } //redonde p abajo
 
void NACHO(string name = "gates"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

bool mark[MX][MX];
bool visited[MX][MX];

void dfs(int x, int y){
	stack<pi> st;
	visited[x][y] = 1;
	st.push(mp(x, y));
	while(!st.empty()){
		auto A = st.top();
		st.pop();
		int X = A.f, Y = A.s;
		F0R(k, 4){
			int xx = X+dx[k], yy = Y+dy[k];
			if(valid(xx, yy, MX, MX) && !visited[xx][yy] && !mark[xx][yy]){
				visited[xx][yy] = 1;
				st.push(mp(xx, yy));
			}
		}
		
	}
}

int main(){
	NACHO();
	// Supongamos que el fence divide al plano en n secciones.
	// La respuesta es n-1.
	
	int n; cin >> n;
	string s; cin >> s;
	int x = 1001, y = 1001;
	mark[x][y] = 1;
	int ret = 0;
	F0R(i, n){
		if(s[i] == 'N'){ mark[x][++y] = 1; mark[x][++y] = 1; }
		else if(s[i] == 'S') { mark[x][--y] = 1; mark[x][--y] = 1; }
		else if(s[i] == 'E') { mark[++x][y] = 1; mark[++x][y] =1; }
		else { mark[--x][y] = 1; mark[--x][y] =1; }
		mark[x][y] = 1;
	}
	FOR(i, 0, MX){
		FOR(j, 0, MX){
			if(!visited[i][j] && !mark[i][j]){
				++ret;
				dfs(i, j);
			}
		}
	}
	cout << ret-1 << "\n";
}


