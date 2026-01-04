// https://codeforces.com/problemset/problem/371/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

long long _div(long long n, long long quan) {
	if(quan == 0)
		return 1000000000;
	return n / quan;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	long long quanB = 0, quanS = 0, quanC = 0;
	for(auto ch : s) {
		if(ch == 'S') quanS++;
		else if(ch == 'B') quanB++;
		else quanC++;
	}
	
	long long nB, nS, nC;
	cin >> nB >> nS >> nC;
	long long pB, pS, pC;
	cin >> pB >> pS >> pC;
	long long r;
	cin >> r;
	
	long long quan = min(_div(nB, quanB), min(_div(nS, quanS), _div(nC, quanC)));
	
	nB -= quan * quanB;
	nS -= quan * quanS;
	nC -= quan * quanC;
		
	long long low = 0, high = 10000000000000;
	
	while(high - low > 1) {
		long long mid = low + (high - low) / 2;
		long long totCost = 0;
		totCost += pB * (max(0LL, quanB * mid - nB));
		totCost += pS * (max(0LL, quanS * mid - nS));
		totCost += pC * (max(0LL, quanC * mid - nC));
		if(totCost <= r) low = mid;
		else high = mid;
	}
	
	cout << quan + low << '\n';
	
	return 0;
}
