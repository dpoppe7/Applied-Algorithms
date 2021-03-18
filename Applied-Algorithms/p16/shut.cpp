#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 1 << 22;
const int MAX_N = 50;
int N, T;
int t[MAX_N], ans;
bool vis[1 << 23];

vector<int> G[MAX_N];
vector<int> M[MAX_N];

struct Node {
    int statu, p, n;
};

int build(int n) {
    int ans = 1 << n;
    while (!(ans & MAX))
        ans = ans | ans << 1;
    return ans;
}

void init() {
    for (int i = 1; i <= MAX; i++) {
        int sum = 0, t = i, k = 0, num = 0;
        while (t && sum < 23) {
            k++;
            if (t & 1) {
                sum += k;
                num++;
            }
            t >>= 1;
        }
        if (!t) {
            G[sum].push_back(i);
            M[sum].push_back(num);
        }
    }
}

int main() {
    init();
    int kase = 0;
    while (~scanf("%d %d", &N, &T) && N && T) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= T; i++)
            scanf("%d", t + i);
        queue<Node> Q;
        Node cur;
        Q.push(Node{build(N), 0, 0});
        ans = 0;
        while (!Q.empty()) {
            cur = Q.front();
            Q.pop();
            ans = max(ans, cur.n);
            if (cur.p >= T) continue;
            int p = cur.p + 1, to = t[p], total = (int) G[to].size();
            for (int i = 0; i < total; i++)
                if ((cur.statu & G[to][i]) == 0) {
                    int s = cur.statu | G[to][i];
                    if (!vis[s]) {
                        Q.push(Node{s, p, cur.n + M[to][i]});
                        vis[s] = true;
                    }
                }
        }
        printf("Game %d: %d\n", ++kase, ans);
    }
    return 0;
}