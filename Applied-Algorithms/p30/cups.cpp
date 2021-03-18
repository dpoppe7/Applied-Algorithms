#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>
#include<queue>
#include<set>
#include<algorithm>

#define LL long long
using namespace std;
int n, k, v[10], pre[10];
int mp[2 * 64 * 64 * 64 * 64 + 10];

struct node {
    int val[10];
    int tot;
    int hash_val;

    bool operator<(const node &n1) const {
        return tot > n1.tot;
    }
} beg, in, out;

int Hash(int a[]) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum = sum * 65 + a[i];
    }
    return sum;
}

void _copy(int a[], int b[]) {
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

int BFS() {
    priority_queue <node> Q;
    Q.push(beg);
    while (!Q.empty()) {
        int ok = 0;
        out = Q.top();
        Q.pop();
        _copy(v, out.val);
        if (v[0] == k)return out.tot;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (x == y)continue;
                if (!v[x] && !v[y])continue;
                int tmp = min(v[x], pre[y] - v[y]);
                if (tmp == 0)continue;
                v[x] -= tmp;
                v[y] += tmp;
                int has = Hash(v);
                _copy(in.val, v);
                v[x] += tmp;
                v[y] -= tmp;
                in.tot = out.tot + tmp;
                if (mp[has] != 0 && mp[has] <= in.tot)continue;
                mp[has] = in.tot;
                in.hash_val = has;
                Q.push(in);
            }
        }
    }
    return -1;
}

int main() {

    while (cin >> n) {
        memset(mp, 0, sizeof mp);
        memset(pre, 0, sizeof pre);
        memset(v, 0, sizeof v);
        for (int i = 0; i < n; i++)
            scanf("%d", &pre[i]);
        v[0] = pre[0];
        scanf("%d", &k);
        beg.tot = 0;
        beg.hash_val = Hash(v);
        beg.val[0] = pre[0];
        mp[beg.hash_val] = -1;
        int ans = BFS();
        if (ans == -1)
            printf("impossible\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}