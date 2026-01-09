// https://codeforces.com/problemset/problem/359/D

#include <bits/stdc++.h>

using namespace std;

template<class T>
struct RMQ{
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for(int pw = 1, k = 1; pw*2 <= (int)V.size(); pw *= 2, ++k){
			jmp.emplace_back((int)V.size() - pw*2+1);
			for(int j = 0; j < (int)jmp[k].size(); j++)
				jmp[k][j] = min(jmp[k-1][j], jmp[k-1][j+pw]);
		}
	}
	T query(int a, int b){
		assert(a<b);// or return inf if a==b
		int dep = 31 - __builtin_clz(b-a);
		return min(jmp[dep][a], jmp[dep][b-(1<<dep)]);
	}
};

template<class T>
struct RGCDQ {
	vector<vector<T>> jmp;
	RGCDQ(const vector<T>& V) : jmp(1, V) {
		for(int pw = 1, k = 1; pw*2 <= (int)V.size(); pw *= 2, ++k){
			jmp.emplace_back((int)V.size() - pw*2+1);
			for(int j = 0; j < (int)jmp[k].size(); j++)
				jmp[k][j] = __gcd(jmp[k-1][j], jmp[k-1][j+pw]);
		}
	}
	T query(int a, int b){
		assert(a<b);// or return inf if a==b
		int dep = 31 - __builtin_clz(b-a);
		return __gcd(jmp[dep][a], jmp[dep][b-(1<<dep)]);
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	RMQ m = RMQ(a);
	RGCDQ g = RGCDQ(a);
	int low = 1, high = n + 1;
	
	auto good = [&](int i, int k) {
		return m.query(i, i + k) == g.query(i, i + k);
	};
	
	auto can = [&](int k) {
		bool r = false;
		
		for(int i = 0; i <= n - k; i++)
			r |= good(i, k);
		
		return r;
	};
	
	while(high - low > 1) {
		int mid = low + (high - low) / 2;
		if(can(mid)) low = mid;
		else high = mid;
	}
	
	vector<int> pos;
	for(int i = 0; i <= n - low; i++)
		if(good(i, low))
			pos.push_back(i + 1);
			
	cout << (int)pos.size() << ' ' << low - 1 << '\n';
	for(auto u : pos)
		cout << u << ' ';
	cout << '\n';
    return 0;
}
