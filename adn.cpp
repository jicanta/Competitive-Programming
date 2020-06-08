#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}

tint dp[200001][2];

int main(){
    NACHO;
    ifstream cin("adn.in");
    ofstream cout("adn.out");
    int n, m, k; cin >> n >> m >> k;
    string a, b; cin >> a >> b;
    forn(i, n+1) dp[i][0] = i;
    forsn(i, 1, m+1){
         int mod = i%2;
         dp[0][mod] = i;
        forsn(j, max(1,i-2*k-1), min(n+1,i+2*k+1)){	
            if(a[j-1] == b[i-1]) dp[j][mod] = dp[j-1][1-mod];
            else{
                dp[j][mod] = min(dp[j][1-mod], min(dp[j-1][mod], dp[j-1][1-mod]))+1;
            }
        }
    }
    int ret = dp[n][m%2];
    if(ret > k) cout << "Muy distintas." << "\n";
    else cout << ret << "\n";
}
