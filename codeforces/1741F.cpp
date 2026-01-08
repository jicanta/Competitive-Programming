// https://codeforces.com/problemset/problem/1741/F

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

struct Seg {
    int l, r, c, id;
};

struct Ev {
    int l, r, c, id, o;
};

void pass(vector<Ev> pts, vector<int> &ans) {
    sort(pts.begin(), pts.end(), [&](const Ev &a, const Ev &b){
        if (a.l == b.l)
			return a.o < b.o;
        return a.l < b.l;
    });

    pair<int, int> best1 = {-INF, -1}, best2 = {-INF, -1};

    auto add = [&](int r, int c) {
        if (best1.second == c) best1.first = max(best1.first, r);
        else if (best2.second == c) best2.first = max(best2.first, r);
        else {
            if (r > best1.first) { best2 = best1; best1 = {r, c}; }
            else if (r > best2.first) best2 = {r, c};
        }
        if (best2.first > best1.first) swap(best1, best2);
        if (best1.second == best2.second) best2 = {-INF, -1};
    };

    auto getBestR = [&](int c) {
        if (best1.second != -1 && best1.second != c) return best1.first;
        if (best2.second != -1 && best2.second != c) return best2.first;
        return -INF;
    };

    for (auto &e : pts) {
        if (e.o == 0) {
            add(e.r, e.c);
        } else {
            int bestR = getBestR(e.c);
            if (bestR != -INF) ans[e.id] = min(ans[e.id], max(0, e.r- bestR));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<Seg> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].l >> a[i].r >> a[i].c;
            a[i].id = i;
        }

        vector<Ev> pts(2 * n); 
        for (int i = 0; i < n; i++) {
            pts[2 * i] = {a[i].l, a[i].r, a[i].c, a[i].id, 0};
            pts[2 * i + 1] = {a[i].r, a[i].l, a[i].c, a[i].id, 1};
        }

        vector<int> ans(n, INF);

        pass(pts, ans);

        reverse(pts.begin(), pts.end());
        for (auto &e : pts) {
            e.l = INF - e.l;
            e.r = INF - e.r;
            e.o ^= 1;
        }

        pass(pts, ans);

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
