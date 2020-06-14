#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO {ios::sync_with_stdio(0); cin.tie(NULL);}
 
typedef long long tint;
 
const int INF = 50000200;
const int MOD = 1e9+7;
const int N = 100001;

const int d = 26;

int pf(const string &s){
	int n = s.size();
	vector<int> pi (n);
	forsn(i, 1, n){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
	return pi[n-1];
}

int  prueba( string s )
{
    string ss = s; reverse(all(ss));
	int n = s.size();
	int res = max(pf(s+'#'+ss), pf(ss+'#'+s));
	return n-res;
}
