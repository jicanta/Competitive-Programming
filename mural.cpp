#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
  
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 1111122222;
const int MOD = 1e9+7;

vector<string> tab (1001, string(1001, '.'));

char paint(int x, int y, char col){
	char act = tab[x][y];
	char copy = col;
	char copyy = act;
	act = min(act, col);
	col = max(copyy, col);
	if(act == 'R' && col == 'Z') return 'P';
	if(act == 'A' && col == 'R') return 'N';
	if(act == 'A' && col == 'Z') return 'V';
	return copy;
}
 
int main(){
	NACHO;
	ifstream cin("mural.in");
	ofstream cout("mural.out");
	int n, a, b; cin >> n >> a >> b;
	forn(i, a){
		int idx, l, r;
		char a;
		cin >> idx >> a >> l >> r;
		idx--;l--;
		forsn(j, l, r){
			tab[idx][j] = paint(idx, j, a);
		}
	}
	forn(i, b){
		int idx, l, r;
		char a;
		cin >> idx >> a >> l >> r;
		idx--;l--;
		forsn(j, l, r){
			tab[j][idx] = paint(j, idx, a);
		}
	}
	forn(i, n){
		forn(j, n) cout << tab[i][j];
		cout << "\n";
	}
}

