#include <bits/stdc++.h>

using namespace std;
 
typedef long long tint;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend() 
#define NACHO ios::sync_with_stdio(0); cin.tie(NULL);
 
const int INF = 1e6;
const int MOD = 1e9+7;
 
vector<int> electromovil(int E, vector<int> ubicacion, vector<int> autonomia){
	vector<int> ret;
	vector<int> ba;
	int posAct = autonomia[0];
	int maxSF = -1;
	int id = 0;
	forsn(i, id+1, E){
		if(ubicacion[i] > posAct){
			posAct = maxSF;
			ret.push_back(ubicacion[id]);
			ba.push_back(autonomia[id]);
			maxSF = -1;
		}
		if(ubicacion[i]+autonomia[i] > maxSF){
			maxSF = ubicacion[i]+autonomia[i];
			id = i;
		}
	}
	ret.push_back(ubicacion[E-1]);
	ba.push_back(autonomia[E-1]);
	int check = autonomia[0];
	bool ok = 1;
	forn(i, ret.size()){
		if(check < ret[i]){
			ok = 0;
		}else{
			check = ret[i]+ba[i];
		}
	}
	if(!ok){
		ret.clear();
	}
	return ret;
}


