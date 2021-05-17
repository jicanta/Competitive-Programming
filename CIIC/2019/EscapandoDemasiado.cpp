#include <bits/stdc++.h> 	

using namespace std;	

using tint = long long;	
using ld = double;	
 	
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)	
#define forn(i, n) forsn(i, 0, n)	
 	
using vi = vector<tint>;	
 	
#define pb push_back	
#define rsz resize	
#define all(x) begin(x), end(x)	
#define sz(x) (int)(x).size()	
 	
using pi = pair<int,int>;	
#define f first	
#define s second	
#define mp make_pair	
 	
#define DBG(x) cerr << #x << " = " << (x) << endl;	
#define dbg cerr << "HUH" << endl;	
 	
const int MOD = 1e9+7; //998244353;
const int MX = 1000+5;	
const int INF = 1e9;	
const ld PI = acos((ld)-1);	
const ld EPS = 1e-9;
 
void NACHO(string name = "balompie") { 	
    ios_base::sync_with_stdio(0); cin.tie(0); 	
    //freopen((name+".in").c_str(), "r", stdin); 	
    //freopen((name+".out").c_str(), "w", stdout);	
}	

bool valid(string s){
	bool ok = 1;
	forn(i, sz(s)){
		int j = i;
		if(s[i] != 'x') continue;
		while(j < sz(s) && s[j] == 'x'){
			++j;
		}
		--j;
		if((j-i+1) % 2 == 1 && (j == sz(s)-1 || s[j+1] != 'p')) ok = 0;
		i = j;
	}
	return ok;
}

set<string> p;

void recu(string s){
	if(!valid(s)) return;
	bool ch = 0;
	string act = "";
	bool fin = 0;
	int i;
	for(i = 0; i < sz(s)-1; i++){
		if(s[i] == 'x'){
			if(s[i+1] == 'x') act+='x';
			else if(s[i+1] == 'p') act+='$', fin = 1;
			else{
				act+='x';
				continue;
			}
			ch = 1;
			++i;
		}else act+=s[i];
	}
	//DBG(act);
	if(i == sz(s)-1) act+=s.back();
	p.insert(act);
	if(fin || !ch) return;
	recu(act);
	
}

int main(){
	NACHO();	
	string s;
	cin >> s;
	if(!valid(s)){
		cout << 0 << "\n";
		cout << "NOSTRING" << "\n";
		return 0;
	}
	recu(s);
	cout << sz(p) << endl;
	cout << *p.begin() << endl;
}
