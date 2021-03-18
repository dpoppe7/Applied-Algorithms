#include <iostream>

using namespace std;

int num[205];
int dp[205][205];
bool vis[205][205];
int N, S, T;

void DP() {
    int i, j, k, t;
    for (i = 1; i <= 204; i++) {
        for (j = 1; j <= 204; j++) {
            dp[i][j] = -999999;
        }
    }
    for (i = 1; i <= S; i++) {
        dp[1][i] = num[i];
        vis[1][i] = 1;
    }
    for (i = 1; i < T; i++) {
        for (j = 1; j <= N; j++) {
            if (vis[i][j]) {
                for (t = 1; t <= S; t++) {
                    k = j + t;
                    if (vis[i + 1][k])
                        dp[i + 1][k] = dp[i + 1][k] > dp[i][j] + num[k] ? dp[i + 1][k] : dp[i][j] + num[k];
                    else {
                        dp[i + 1][k] = dp[i][j] + num[k];
                        vis[i + 1][k] = 1;
                    }
                    if (k >= N + 1)
                        break;
                }
            }
        }
    }
}

int main() {
    int i;
    while (cin >> N && N) {
        cin >> S >> T;
        memset(num, 0, sizeof(num));
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= N; i++)
            scanf(" %d ", num + i);
        DP();
        int max = dp[1][N + 1];
        for (i = 2; i <= T; i++)
            if (max < dp[i][N + 1]) {
                max = dp[i][N + 1];
            }
        cout << max << endl;
    }
    return 0;
}