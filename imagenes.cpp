#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
  
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int N = 1000000;

int main(){
	NACHO;
	ifstream cin("imagenes.in");
	ofstream cout("imagenes.out");
	string s, t; cin >> s >> t;
	int n = s.size();
	string ret = "";
	forn(i, n){
		int j = i;
		while(j < n && s[j] == s[i]){
			j++;
		}
		j--;
		if(j-i+1 > 4){
			ret+='('; ret+=s[i];
			ret+=to_string(j-i+1);
			ret+=')';
		}else{
			forn(k, j-i+1){
				ret+=s[i];
			}
		}
		i = j;
	}
	n = t.size();
	cout << ret << "\n";
	forn(i, n){
		if(t[i] == '('){
			char a = t[i+1];
			i+=2;
			string quan = "";
			while(i <n && t[i] != ')'){
				quan+=t[i];
				i++;
			}
			int x = stoi(quan);
			forn(j, x){
				cout << a;
			}
		}else{
			cout << t[i];
		}
	}
	
}
