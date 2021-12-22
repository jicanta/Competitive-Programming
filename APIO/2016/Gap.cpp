#include "gap.h"
 
#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
using vi = vector<int>;
using tint = long long;
using vl = vector<tint>;
 
long long findGap(int T, int n)
{
	if(T == 1){
		vl a(n);
		int l = 0, r = n-1;
		tint L = 0, R = 1e18;
		while(l <= r){
			MinMax(L, R, &L, &R);
			a[l] = L; a[r] = R;
			++L; --R;
			++l; --r;
		}
		tint maxi = 0;
		F0R(i, n-1) maxi = max(maxi, a[i+1] - a[i]);
		return maxi;
	}else{
		tint L = 0, R = 1e18;
		MinMax(L, R, &L, &R);
		tint RR = R;
		tint lowerBound = (R - L) / (n - 1);
		tint ret = lowerBound;
		tint last = L;
		for(tint i = L; i <= RR; i += lowerBound+1){
			MinMax(i, i+lowerBound, &L, &R);
			//cout << i << " " << i+lowerBound << " " << L << " " << R << "\n";
			if(L != -1){
				ret = max(ret, L - last);
				last = R;
			}
		}
		return ret;
	}
}
