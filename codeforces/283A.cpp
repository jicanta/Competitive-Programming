// https://codeforces.com/problemset/problem/283/A

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>
#include <iomanip>

using namespace std;

const int inf=1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0;
    long long val = 0; // SUM on [lo,hi)

    Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of 0

    Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = l->val + r->val;
        } else val = v[lo];
    }

    long long query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }

    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            madd = 0;
            val = 1LL * x * (hi - lo);
        } else {
            push();
            l->set(L, R, x);
            r->set(L, R, x);
            val = l->val + r->val;
        }
    }

    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += 1LL * x * (hi - lo);
        } else {
            push();
            l->add(L, R, x);
            r->add(L, R, x);
            val = l->val + r->val;
        }
    }

    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != inf) {
            l->set(lo, hi, mset);
            r->set(lo, hi, mset);
            mset = inf;
        } else if (madd) {
            l->add(lo, hi, madd);
            r->add(lo, hi, madd);
            madd = 0;
        }
    }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int curSize = 1;
	Node* st = new Node(0, 200005);
	st->set(0, 1, 0);
	
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int x, a;
			cin >> a >> x;
			st->add(0, a, x);
		} else if(t == 2) {
			int k;
			cin >> k;
			st->set(curSize, curSize + 1, k);
			curSize++;
		} else {
			st->set(curSize - 1, curSize, 0);
			curSize--;
		}
		cout << fixed << setprecision(9) << (double)st->query(0, curSize) / curSize << '\n';
	}
	
	return 0;
}
