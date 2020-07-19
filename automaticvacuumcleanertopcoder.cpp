#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long tint;
typedef long double ld;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO {ios::sync_with_stdio(false); cin.tie(nullptr);}
#define DBG(x) cerr << #x << " = " << (x) << endl;
#define dbg cerr << "HUH" << endl;
 
const int INF = 99009000;
const tint MOD = 1000000007;
const int N = 100001;

struct AutomaticVacuumCleaner{
    long long getDistance(long long R, long long C, long long A, long long B){
		R++; //SOLO P QUE NO ME TIRE WARNING
        tint RF = A/C-(A % C == 0);
        tint RS = (A+B)/C-((A+B)%C == 0);
        tint CF, CS;
        if(RF % 2 == 0){
            CF = A % (2*C)-1;
        }else{
            CF = A%(C);
            if(CF == 0) CF = C;
            CF = C-CF;
        }
        if(RS % 2 == 0){
            CS = (A+B) % (2*C)-1;
        }else{
            CS = (A+B)%(C);
            if(CS == 0) CS = C;
            CS = C-CS;
        }
        return tint(abs(CF-CS))+tint(abs(RS-RF));
    }
};

int main(){
	AutomaticVacuumCleaner a;
	tint aa, b, c, d; cin >> aa >> b >> c >> d; 
	cout << a.getDistance(aa,b,c,d);
}

