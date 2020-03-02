#include <bits/stdc++.h>

#define forsn(i,s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

const int INF = 1e6+1;

struct Fecha{
    int dia, mes,anno;
    bool operator<(const Fecha &ot) const{
		if(anno == ot.anno){
			if(mes == ot.mes) return dia < ot.dia;
			return mes < ot.mes;
		}
		return anno < ot.anno;
	}
};

int fila(vector<Fecha> orden, vector<int> &enojados){
	int n = orden.size();
	vector<pair<Fecha, int>> busco (n);
	forn(i, n){
		busco[i] = {orden[i],i};
	}
	sort(all(busco));
	int MINI[n];
	MINI[n-1] = busco[n-1].second;
	for(int i = n-2;i>=0;i--){
		MINI[i] = min(busco[i].second, MINI[i+1]);
	}
	vector<pair<int,int>> anger (n);
	forn(i, n){
		anger[i] = {busco[i].second-MINI[i], busco[i].second};
	}
	sort(rall(anger), [&](pair<int,int> a, pair<int,int> b){
		if(a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	});
	int maxi = -1;
	forn(i, n){
		if(anger[i].first > 0) enojados.push_back(anger[i].second+1);
		maxi = max(maxi, anger[i].first);
	}
	return maxi;
}
