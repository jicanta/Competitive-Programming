#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
#define dbg cout << "hu" << endl;
 
const int INF = 50000001; //chequea el INF!!!!!
const int MOD = 1000000007;
const int N = 2000001;

int dp1[N], dp2[N];

int main(){
	NACHO;
	ifstream cin("maxinum.in");
	ofstream cout("maxinum.out");
	int n; cin >> n;
	vector<int> a (n);
	int tot = 0;
	forn(i, n) cin >> a[i], tot+=a[i];
	if(n < 4){
		if(n == 3){ cout << a[0]*a[2] << "\n"; cout << a[1] << "\n";}
		if(n == 2){ cout << 0 << "\n"; cout << a[0]+a[1] << "\n";}
		if(n == 1){ cout << 0 << "\n"; cout << a[0] << "\n";}
		return 0;
	}
	vector<int> b1, b2;
	vector<int> p1 (n/2+1), p2 (n/2+1);
	for(int i=0;i<n;i+=2){
		b1.push_back(a[i]);
	}
	for(int i=1;i<n;i+=2){
		b2.push_back(a[i]);
	}
	dp1[1] = b1[1]*b1[0];
	vector<bool> use1 (n/2+1, 0), use2 (n/2+1, 0);
	vector<int> vengo1 (n/2+1, -1), vengo2 (n/2+1, -1);
	use1[1] = 1;
	forsn(i, 2, b1.size()){	
		if(dp1[i-2]+b1[i]*b1[i-1] > dp1[i-1]){
			use1[i] = 1;
			vengo1[i] = i-2;
		}else{
			use1[i] = 0;
			vengo1[i] = i-1;
		}
		dp1[i] = max(dp1[i-1], dp1[i-2]+b1[i]*b1[i-1]);
	}
	int st = int(b1.size()-1);
	while(st != -1){
		if(use1[st]) tot-=b1[st]+b1[st-1];
		st = vengo1[st];
	}
	dp2[1] = b2[1]*b2[0];
	use2[1] = 1;
	forsn(i, 2, b2.size()){
		if(dp2[i-2]+b2[i]*b2[i-1] > dp2[i-1]){
			use2[i] = 1;
			vengo2[i] = i-2;
		}else{
			use2[i] = 0;
			vengo2[i] = i-1;
		}
		dp2[i] = max(dp2[i-1], dp2[i-2]+b2[i]*b2[i-1]);
	}
	st = int(b2.size()-1);
	while(st != -1){
		if(use2[st]) tot-=b2[st]+b2[st-1];
		st = vengo2[st];
	}
	cout << dp1[int(b1.size())-1]+dp2[int(b2.size())-1] << "\n";
	cout << tot << "\n";
}
//4 2 1 2 8
//0 1 2 3 4
