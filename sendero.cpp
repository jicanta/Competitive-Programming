
//---------------------------------//


//ESTOS CASOS ROMPEN SOLUCIONES EN OIAJ
//1 2 3
//RRRBRRR

//1 2 3
//RRRRRRR



//---------------------------------//

#include <bits/stdc++.h> 	
 	
using namespace std;	
 	
using tint = long long;	
using ld = long double;	
 	
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)	
#define forn(i, n) forsn(i, 0, n)	
 	
using vi = vector<tint>;	
 	
#define pb push_back	
#define rsz resize	
#define all(x) begin(x), end(x)	
//#define rall(x) rbegin(x), rend(x)	
#define sz(x) (int)(x).size()	
 	
using pi = pair<int,int>;	
#define f first	
#define s second	
#define mp make_pair	
 	
#define DBG(x) cerr << #x << " = " << (x) << endl;	
#define dbg cerr << "HUH" << endl;	
 	
void NACHO(string name = "") { 	
    ios_base::sync_with_stdio(0); cin.tie(0); 	
    //freopen((name+".in").c_str(), "r", stdin); 	
    //freopen((name+".out").c_str(), "w", stdout);	
}	

int sendero(int B, int G, int N, string &baldosas){
    bool allR = 1;
    int cost = 0;
    int n = sz(baldosas);
    vector<pair<int,char>> val = {mp(B, 'B'), mp(G, 'G'), mp(N, 'N')};
    sort(all(val));
    forn(i, n){
		if(baldosas[i] != 'R') allR = 0;
	}
	if(allR){
		forn(i, n){
			cost+=val[i%2].f;
			baldosas[i] = val[i % 2].s;
		}
		return cost;
	}
	int st = -1;
	bool ok = 1;
	string ret1 = baldosas, ret2 = baldosas;
	forn(i, n){
		if(baldosas[i] != 'R' && st >= 0){
			int cost1 = 0, cost2 = 0;
			forsn(j, st, i){
				forn(k, 3){
					if(j-1 >= 0 && j+1 < n && ret1[j-1] != val[k].s && ret1[j+1] != val[k].s){
						cost1+=val[k].f;
						ret1[j] = val[k].s;
						break;
					}else if(j-1 < 0 && j+1 < n && ret1[j+1] != val[k].s){
						cost1+=val[k].f;
						ret1[j] = val[k].s;
						break;
					}else if(j-1 >= 0 && j+1 > n-1 && ret1[j-1] != val[k].s){
						cost1+=val[k].f;
						ret1[j] = val[k].s;
						break;
					}
				}
			}
			for(int j=i-1;j>=st;j--){
				forn(k, 3){
					if(j-1 >= 0 && j+1 < n && ret2[j-1] != val[k].s && ret2[j+1] != val[k].s){
						cost2+=val[k].f;
						ret2[j] = val[k].s;
						break;
					}else if(j-1 < 0 && j+1 < n && ret2[j+1] != val[k].s){
						cost2+=val[k].f;
						ret2[j] = val[k].s;
						break;
					}else if(j-1 >= 0 && j+1 > n-1 && ret2[j-1] != val[k].s){
						cost2+=val[k].f;
						ret2[j] = val[k].s;
						break;
					}
				}
			}
			if(cost1 < cost2){ 
				 forsn(j, st, i){
					forn(k, 3){
						if(j-1 >= 0 && j+1 < n && ret1[j-1] != val[k].s && ret1[j+1] != val[k].s){
							baldosas[j] = val[k].s;
							break;
						}else if(j-1 < 0 && j+1 < n && ret1[j+1] != val[k].s){
							baldosas[j] = val[k].s;
							break;
						}else if(j-1 >= 0 && j+1 > n-1 && ret1[j-1] != val[k].s){
							baldosas[j] = val[k].s;
							break;
						}
					}
				}
				cost+=cost1;
			}else{ 
				for(int j=i-1;j>=st;j--){
					forn(k, 3){
						if(j-1 >= 0 && j+1 < n && ret2[j-1] != val[k].s && ret2[j+1] != val[k].s){
							baldosas[j] = val[k].s;
							break;
						}else if(j-1 < 0 && j+1 < n && ret2[j+1] != val[k].s){
							baldosas[j] = val[k].s;
							break;
						}else if(j-1 >= 0 && j+1 > n-1 && ret2[j-1] != val[k].s){
							baldosas[j] = val[k].s;
							break;
						}
					}
				}
				cost+=cost2;
			}
			ok = 1;
			st = -1;
		}else if(baldosas[i] == 'R' && ok){
			st = i;
			ok = 0;
		}
	}
	if(st >= 0){
		int cost1 = 0, cost2 = 0;
		string ret1 = baldosas, ret2 = baldosas;
		forsn(j, st, n){
			forn(k, 3){
				if(j-1 >= 0 && j+1 < n && ret1[j-1] != val[k].s && ret1[j+1] != val[k].s){
					cost1+=val[k].f;
					ret1[j] = val[k].s;
					break;
				}else if(j-1 < 0 && j+1 < n && ret1[j+1] != val[k].s){
					cost1+=val[k].f;
					ret1[j] = val[k].s;
					break;
				}else if(j-1 >= 0 && j+1 > n-1 && ret1[j-1] != val[k].s){
					cost1+=val[k].f;
					ret1[j] = val[k].s;
					break;
				}
			}
		}
		for(int j=n-1;j>=st;j--){
			forn(k, 3){
				if(j-1 >= 0 && j+1 < n && ret2[j-1] != val[k].s && ret2[j+1] != val[k].s){
					cost2+=val[k].f;
					ret2[j] = val[k].s;
					break;
				}else if(j-1 < 0 && j+1 < n && ret2[j+1] != val[k].s){
					cost2+=val[k].f;
					ret2[j] = val[k].s;
					break;
				}else if(j-1 >= 0 && j+1 > n-1 && ret2[j-1] != val[k].s){
					cost2+=val[k].f;
					ret2[j] = val[k].s;
					break;
				}
			}
		}
		if(cost1 < cost2){ baldosas = ret1; cost+=cost1;}
		else{ baldosas = ret2; cost+=cost2;}
	}
	return cost;
}


