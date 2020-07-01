#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 40000000;
const int MOD = 1e9+7;
const int N = 2001;
 
string tab[N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
 
bool valid(int x, int y, int n){
    return (0<=x && x<n && 0<=y && y<n);
}

int main(){
	NACHO;
    ifstream cin("uniformar.in");
    ofstream cout("uniformar.out");
    int n; cin >> n;
    forn(i, n){
        cin >> tab[i];
    }
    vector<vector<int>> d (n, vector<int> (n,INF));
    d[0][0] = 0;
    deque<pair<int,int>> q;
    q.push_front({0,0});
    int maxi = 0;
    while(!q.empty()){
		auto s = q.front();
		q.pop_front();
		forn(k, 4){
			int x = s.first+dx[k];
			int y = s.second+dy[k];
			if(valid(x,y,n)){
				int w = (tab[x][y] != tab[s.first][s.second]);
				if(d[s.first][s.second]+w < d[x][y]){
					d[x][y] = d[s.first][s.second]+w;
					maxi = max(maxi, d[x][y]);
					if(w == 1) q.push_back({x,y});
					else q.push_front({x,y});
				}
			}
		}
	}
	cout << maxi << "\n";
}

