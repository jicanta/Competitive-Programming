#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5+5;

int contA1[MX], contC1[MX], contT1[MX];
int contA2[MX], contC2[MX], contT2[MX];
int AC[MX], AT[MX], CA[MX], CT[MX], TA[MX], TC[MX];

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define F0R(i, b) FOR(i, 0, b)
#define sz(v) (int)(v).size()

void init(std::string a, std::string b) {
	FOR(i, 1, sz(a)+1){
		contA1[i] = contA1[i-1] + (a[i-1] == 'A');
		contC1[i] = contC1[i-1] + (a[i-1] == 'C');
		contT1[i] = contT1[i-1] + (a[i-1] == 'T');
	}
	FOR(i, 1, sz(b)+1){
		contA2[i] = contA2[i-1] + (b[i-1] == 'A');
		contC2[i] = contC2[i-1] + (b[i-1] == 'C');
		contT2[i] = contT2[i-1] + (b[i-1] == 'T');
	}
	FOR(i, 1, sz(a)+1){
		AC[i] = AC[i-1] + (a[i-1] == 'A' && b[i-1] == 'C');
		AT[i] = AT[i-1] + (a[i-1] == 'A' && b[i-1] == 'T');
		CA[i] = CA[i-1] + (a[i-1] == 'C' && b[i-1] == 'A');
		CT[i] = CT[i-1] + (a[i-1] == 'C' && b[i-1] == 'T');
		TA[i] = TA[i-1] + (a[i-1] == 'T' && b[i-1] == 'A');
		TC[i] = TC[i-1] + (a[i-1] == 'T' && b[i-1] == 'C');
	}
}

int get_distance(int x, int y) {
	if(contA1[y+1] - contA1[x] != contA2[y+1] - contA2[x]) return -1;
	if(contC1[y+1] - contC1[x] != contC2[y+1] - contC2[x]) return -1;
	if(contT1[y+1] - contT1[x] != contT2[y+1] - contT2[x]) return -1;
	int ret = 0;
	int ac = AC[y+1] - AC[x], at = AT[y+1] - AT[x], ca = CA[y+1] - CA[x];
	int ct = CT[y+1] - CT[x], ta = TA[y+1] - TA[x], tc = TC[y+1] - TC[x];
	// cycles of size two
	if(min(ac, ca) > 0){
		ret += 2 * min(ac, ca) - min(ac, ca);
		int xx = min(ac, ca);
		ac -= xx;
		ca -= xx;
	}
	if(min(at, ta) > 0){
		ret += 2 * min(at, ta) - min(at, ta);
		int xx = min(at, ta);
		at -= xx;
		ta -= xx;
	}
	if(min(ct, tc) > 0){
		ret += 2 * min(ct, tc) - min(ct, tc);
		int xx = min(ct, tc);
		ct -= xx;
		tc -= xx;
	} 
	// cycles of size three
	if(min({ac, ct, ta}) > 0){
		ret += 3 * min({ac, ct, ta}) - min({ac, ct, ta});
	}
	if(min({at, tc, ca}) > 0){
		ret += 3 * min({at, tc, ca}) - min({at, tc, ca});
	}
	return ret;
}
