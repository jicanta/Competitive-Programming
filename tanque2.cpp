#include <vector>
#include <iostream>
using namespace std;
 
typedef vector<vector<int> > matriz;
 
const int MAX_FILAS = 1000;
const int MAX_COLUMNAS = 1000;
 
#define forn(i, n) for(int i = 0; i < int(n); i++)
 
matriz dp(MAX_FILAS, vector<int>(MAX_COLUMNAS, -1)); 
 
int min_camino_matriz(matriz& m, int i, int j) {
	if (i == 0 and j == 0) {
		return m[0][0];
	}
 
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
 
	if (i == 0 and j > 0) {
		dp[0][j] = min_camino_matriz(m, 0, j - 1) + m[0][j];
	}
	if (j == 0 and i > 0) {
		dp[i][0] = min_camino_matriz(m, i - 1, 0) + m[i][0]; 
	}
	if (i > 0 and j > 0) {
		dp[i][j] = min(min_camino_matriz(m, i - 1, j), min_camino_matriz(m, i, j - 1)) + m[i][j];
	}
	return dp[i][j];
} 
 
 
int main(){
	int filas, columnas;
	cin >> filas >> columnas;
	matriz m(filas, vector<int> (columnas, 0));
	forn(i, filas) {
		forn(j, columnas) {
			cin >> m[i][j];
		}
	}
	cout << min_camino_matriz(m, filas-1, columnas-1);
}
