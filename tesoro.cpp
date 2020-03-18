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

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n, m, f;
int ex, ey;
string tab[121];

bool valid(int x, int y){
	return (0<=x && x<n && 0<=y && y<m);
}

bool visited[121][121][121];
int dist[121][121][121];


struct stat{
	int x, y, f;
};

stat vengo[121][121][121];

int main(){
	NACHO;
	ifstream cin("tesoro.in");
	ofstream cout("tesoro.out");
	cin >> n >> m >> f;
	forn(i, n){
		cin >> tab[i];
		forn(j, m){
			if(tab[i][j] == 'T') ex=i,ey=j;
		}
	}
	if(tab[0][0] == 'P' || (tab[0][0] == 'W' && f < 1)){
		cout << "imposible" << "\n";
		return 0;
	}
	if(tab[0][0] == 'W') f--;
	forn(i, n){
		forn(j, m){
			forn(k, f+1){
				dist[i][j][k] = INF;
				visited[i][j][k] = 0;
				vengo[i][j][k] = {-1,-1,-1};
			}
		}
	}
	queue<stat> q;
	q.push({0,0,f});
	visited[0][0][f] = 1;
	dist[0][0][f] = 0;
	while(!q.empty()){
		auto s = q.front();
		q.pop();
		forn(k, 4){
			int x = s.x+dx[k];
			int y = s.y+dy[k];
			if(valid(x,y)){
				if(tab[x][y] == 'P') continue;
				else if(tab[x][y] == 'W'){
					if(s.f > 0){
						if(visited[x][y][s.f-1]) continue;
						visited[x][y][s.f-1] = 1;
						vengo[x][y][s.f-1] = {s.x,s.y,s.f};
						dist[x][y][s.f-1] = dist[s.x][s.y][s.f]+1;
						q.push({x,y,s.f-1});
					}
				}else{
					if(visited[x][y][s.f]) continue;
					visited[x][y][s.f] = 1;
					vengo[x][y][s.f] = {s.x,s.y,s.f};
					q.push({x,y,s.f});
					dist[x][y][s.f] = dist[s.x][s.y][s.f]+1;
				}
			}
		}
	}
	int mini = INF;
	int b;
	forn(i, f+1){
		if(dist[ex][ey][i] < mini){
			mini = dist[ex][ey][i];
			b = i;
		}
	}
	if(mini == INF){
		cout << "imposible" << "\n";
	}else{
		cout << mini+1 << "\n";
		vector<pair<int,int>> ret;
		stat act = {ex,ey,b};
		while(act.x != -1){
			ret.push_back({act.x,act.y});
			act = vengo[act.x][act.y][act.f];
		}
		for(int i = int(ret.size())-1;i>=0;i--){
			cout << '(' << ret[i].first << ',' << ret[i].second << ')' << "\n";
		}
	}
}
