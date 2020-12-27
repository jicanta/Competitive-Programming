#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <utility>
#include <deque>

using namespace std;

typedef long long tint;
typedef long double ld;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define forsn(i,s,n) for(int i=s;i<int(n);i++)
#define forn(i,n) forsn(i,0,n)
#define sz(s) int(s.size())

using vi = vector<int>;
using pi = pair<tint, tint>;

int main(){
	//  codeado en la pampa xD
	// la tableta me salvo la vida sto tableta orz
	// la idea es ver que con el bubble sort
	//  solo te "cagan" aquellos elementos que deben ir hacia la izquierda
	// ya que los que se van a la derecha se mueven a medida que avanzan los pasos
	// ej:
	// 1 1 3 1 1 1
	// no nos importa la distancia que tiene que hacer el 3, ya que debe ir a la derecha.
	// la respuesta es entonces la maxima distancia que debe recorrer
	// un numero que va hacia la izquierda''
	// pd: cambio el template por tercera vez en un mes qaq, pero es solo pq con la tableta
	// me queda mas comodo poner forn y no F0R.
	ifstream cin("sort.in");
	ofstream cout("sort.out");
	   int n; cin >>n;
	   vi a (n);
	   forn(i, n) cin >> a[i];
	   vi b = a;
	   sort(all(b));
	  map<int, deque<int>> p;
	  forn(i, n) p[b[i]].push_back(i);
	  int maxi = 0;
	  forn(i, n){
	  	maxi = max(maxi, i-p[a[i]].front()+1);
	  	p[a[i]].pop_front();
	  }
	  cout << maxi << endl;
}
