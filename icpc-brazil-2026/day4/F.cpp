// el F del contest 4 de Andrew Stankevich

#include <bits/stdc++.h>

using namespace std;

const int MIN_X = 1;
const int MAX_X = 1'000'000'000;

#define ll long long

ll ask(int l1, int l2, int r1, int r2) {
	cout << "? " << l1 << ' ' << l2 << ' ' << r1 << ' ' << r2 << endl;
	ll ret;
	cin >> ret;
	return ret - 1LL * (r1 - l1 + 1) * (r2 - l2 + 1);
}

void guess(const vector<int>& left, const vector<int>& right) {
	ll ret = ask(left[0], right[0], left[0], right[0]);
	bool ch = false;
	if(!ret)
		ch = true;
	cout << "! " << left[0] << ' ' << right[0+ch] << ' ' << left[1] << ' ' << right[(1+ch)%2] << endl;
}

int solve(int quan, bool left = true) {
	int low = MIN_X-1, high = MAX_X;
	while(high - low > 1) {
		int mid = low + (high - low) / 2;
		ll ret;
		if(left)
			ret = ask(MIN_X, MIN_X, mid, MAX_X);
		else ret = ask(MIN_X, MIN_X, MAX_X, mid);
		if(ret < quan)
			low = mid;
		else high = mid; 
	}
	return high;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> left, right;
    
    for(int i = 0; i < 2; ++i)
		left.push_back(solve(i+1));
	for(int i = 0; i < 2; ++i)
		right.push_back(solve(i+1, false));
		
	guess(left, right);
    return 0;
}
