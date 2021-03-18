#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
    vector<int> par, ra, si;
    int c;

    UnionFind(int n) : par(n), ra(n, 0), si(n, 1), c(n) {
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int findd(int i) {
        return (par[i] == i ? i : (par[i] = findd(par[i])));
    }

    bool same(int i, int j) {
        return findd(i) == findd(j);
    }

    int get_size(int i) {
        return si[findd(i)];
    }

    int countt() {
        return c;
    }

    void merg(int i, int j) {
        if ((i = findd(i)) == (j = findd(j))) return;
        c--;
        if (ra[i] > ra[j]) swap(i, j);
        par[i] = j;
        si[j] += si[i];
        if (ra[i] == ra[j]) ra[j]++;
    }
};

struct prob {
    double p;
    int r, c;
};

bool cmp(const prob &l, const prob &r) {
    return l.p > r.p;
}

bool super_cmp(const prob &l, const prob &r) {
    return tie(l.r, l.c) < tie(r.r, r.c);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    vector <prob> ps;
    ps.reserve(m * n);
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            prob p{0, r, c};
            scanf("%lf", &p.p);
            ps.push_back(p);
        }
    }
    UnionFind target(m + n), cur(m + n);
    for (int r = 0; r < m; ++r) {
        int k, c;
        scanf("%d", &k);
        while (k--) scanf("%d", &c), target.merg(r, m + c);
    }
    sort(ps.begin(), ps.end(), cmp);
    vector <prob> ans;
    for (auto &p:ps) {
        if (target.same(p.r, m + p.c) && !cur.same(p.r, m + p.c)) {
            cur.merg(p.r, m + p.c), ans.push_back(p);
        }
    }
    sort(ans.begin(), ans.end(), super_cmp);
    for (auto &x:ans) printf("%d %d\n", x.r, x.c);
    return 0;
}