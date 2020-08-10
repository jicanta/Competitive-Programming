#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(tint i = s; i < tint(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<int>;
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const tint MOD = 1e9+7;
const int MX = 1e5+5;
const int INF = 1e9;
const long double PI = acos((-1)); 
 
void NACHO(string name = "puesto"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool valid(int x, int y){
	return (0 <= x && x < 5 && 0 <= y && y < 6);
}

vector<vi> a (5, vi (6));

void press(int i, int j){
	a[i][j] = 1-a[i][j];
	forn(k, 4){
		int x = i+dx[k];
		int y = j+dy[k];
		if(valid(x, y)){
			a[x][y] = 1-a[x][y];
		}
	}
}

int main(){
	NACHO();
	forn(i, 5){
		forn(j, 6)
			cin >> a[i][j];
	}
	vector<vi> ret (5, vi (6, 0));
	forn(i, 4){
		while(1){
			bool ok = 0;
			forn(j, 6) ok |= a[i][j];
			if(!ok) break;
			forn(j, 6){
				if(a[i][j] == 1){
					++ret[i+1][j];
					press(i+1, j);
				}
			}
		}
	}
	vector<vi> aa = a;
	forn(msk, 1<<6){
		vector<vi> copy = ret;
		a = aa;
		forn(i, 6){
			if(msk&(1<<i)){
				++copy[0][i];
				press(0, i);
			}
		}
		forn(i, 4){
			while(1){
				bool ok = 0;
				forn(j, 6) ok |= a[i][j];
				if(!ok) break;
				forn(j, 6){
					if(a[i][j] == 1){
						++copy[i+1][j];
						press(i+1, j);
					}
				}
			}
		}
		bool okk = 0;
		forn(i, 5){
			forn(j, 6){
				okk |= a[i][j];
			}
		}
		if(!okk){
			forn(i, 5){
				forn(j, 6){
					cout << copy[i][j] % 2 << " ";
				}
				cout << endl;
			}
		}
	}
}

//熄灯问题
//http://bailian.openjudge.cn/practice/hint/2811/
