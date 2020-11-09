#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define trav(a, x) for(auto& a : x)
 
using vi = vector<int>;
using vl = vector<tint>;
using vb = vector<bool>;
#define pb push_back
#define pf push_front
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sz(x) (int)(x).size()
#define ins insert
#define esta(x,c) ((c).find(x) != (c).end())
 
using pi = pair<int,int>;
using pl = pair<tint,tint>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 1e5+5;
const tint INF = 1e18;
const int inf = 2e9;
const ld PI = acos(ld(-1));

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

template<class T> void remDup(vector<T> &v){ 
    sort(all(v)); v.erase(unique(all(v)),end(v));
}

template<class T> bool valid(T x, T y, T n, T m){
    return (0<=x && x<n && 0<=y && y<m);
}

void NACHO(string name = "protesta"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

struct state{
	int x, y, dir;
	//dir 0 -> (x+1, y)
	//dir 1 -> (x-1, y)
	//dir 2 -> (x, y+1)
	//dir 3 -> (x, y-1)
	//bool operator<(const state &a)const{return x < a.x; }
};

int main(){
	NACHO();
	int n; cin >> n;
	int bigOdd = (n%2==1?n:n-1)/2;
	int bigEven = (n%2==0?n:n-1)/2;
	vector<vi> tab (n/2+1, vi (n/2+1, 0));
	int iniX, iniY, finX, finY;
	cin >> iniX >> iniY >> finX >> finY;
	if(iniX % 2 == 1) swap(iniX, iniY);
	if(finX % 2 == 1) swap(finX, finY);
	iniX=(iniX-1)/2;
	finX=(finX-1)/2;
	iniY=bigOdd-iniY/2;
	finY=bigOdd-finY/2;
	int p; cin >> p;
	forn(i, p){
		int x, y; cin >> x >> y;
		if(x % 2 == 1) swap(x, y);
		x=(x-1)/2;
		y=bigOdd-y/2;
		tab[y][x] = 1;
	}
	
	
	deque<state> q;
    int distance[n/2+1][n/2+1][4];
	q.push_front(state{iniY, iniX, 1000});
	state prev[n/2+1][n/2+1][4];
	forn(i, n/2+1) forn(j, n/2+1) forn(k, 4) prev[i][j][k] = state{-1, -1, -1};
	forn(i, n/2+1) forn(j, n/2+1) forn(k, 4) distance[i][j][k] = inf;
	
	
	if(n == 2 || (iniY == finY && iniX == finX)){
		cout << 1 << endl;
		cout << 0 << endl;
		return 0;
	}
	
	
	while(!q.empty()){
		auto v = q.front();
		q.pop_front();
		forn(k, 4){
			int x = v.x+dx[k], y = v.y+dy[k];
			int dir = k;
			if(valid(x, y, bigOdd+1, bigEven) && tab[x][y] != 1){
				if(v.x == x){
					if(y > v.y && (bigOdd+1-v.x) % 2 == 1) continue;
					if(y < v.y && (bigOdd+1-v.x) % 2 == 0) continue;
				}
				if(v.y == y){
					if(x > v.x && v.y % 2 == 1) continue;
					if(x < v.x && v.y % 2 == 0) continue;
				}
				int w = (dir != v.dir);
				int a = v.dir == 1000 ? 0 : distance[v.x][v.y][v.dir];
				if(a+w < distance[x][y][dir]){
					prev[x][y][dir] = v;
					distance[x][y][dir] = a+w;
					if(w == 1)
						q.push_back(state{x, y, dir});
					else q.push_front(state{x, y, dir});
				}
				
			}
		}
	}
	
	
	int mini = inf;
	state act;
	forn(i, 4){
		if(distance[finY][finX][i] < mini){
			mini = distance[finY][finX][i];
			act = state{finY, finX, i};
		}
	}
	
	
	if(mini >= inf){
		cout << 0 << "\n";
	}else{
		cout << 1 << "\n";
		vi ret;
		vector<pi> points;
		points.pb(mp(finY, finX));
		state ACT = act;
		ACT = prev[ACT.x][ACT.y][ACT.dir];
		
		
		while(!(ACT.x == -1 && ACT.y == -1) && !(ACT.dir == 1000)){
			points.pb(mp(ACT.x, ACT.y));
			ACT = prev[ACT.x][ACT.y][ACT.dir];
		}
		
		
		points.pb(mp(iniY, iniX));
		reverse(all(points));
		assert(sz(points) != 1);
		
		if(points[0].f == points[1].f){
			ret.pb(2*(bigOdd-points[0].f)+1);
		}else{
			ret.pb(2*points[0].s+2);
		}
		
		forsn(i, 2, sz(points)){
			if((points[i-2].f == points[i-1].f && points[i].f != points[i-1].f) || (points[i-2].s == points[i-1].s && points[i].s != points[i-1].s)){
				if(points[i-1].f == points[i].f){
					ret.pb(2*(bigOdd-points[i].f)+1);
				}else if(points[i-1].s==points[i].s){
					ret.pb(2*points[i].s+2);
				}
			}
		}
		
		cout << sz(ret) << "\n";
		trav(u, ret){
			cout << u << "\n";
		}
	}
}
