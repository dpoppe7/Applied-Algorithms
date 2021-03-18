#include <cctype>
#include <string>
#include <queue>

using namespace std;
int n, m, t;
char mp[100][100];
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const char Dir[4] = {'S', 'N', 'E', 'W'};

struct point {
    int x, y;
};

struct State {
    point box, man;
    int Push, Walk;
};
int best[25][25][25][25][2];

bool operator<(State a, State b) {
    if (a.Push != b.Push)
        return a.Push > b.Push;
    else
        return a.Walk > b.Walk;
}

inline void BecomeBest(const State &state) {
    best[state.box.x][state.box.y][state.man.x][state.man.y][0] = state.Push,
            best[state.box.x][state.box.y][state.man.x][state.man.y][1] = state.Walk;
}

priority_queue <State> q;

inline bool Batter(const State &state) {
    if (best[state.box.x][state.box.y][state.man.x][state.man.y][0] != state.Push)
        return best[state.box.x][state.box.y][state.man.x][state.man.y][0] > state.Push;
    return best[state.box.x][state.box.y][state.man.x][state.man.y][1] > state.Walk;
}

inline bool isUreachable(point a) {
    return a.x <= 0 || a.x > n || a.y <= 0 || a.y > m || mp[a.x][a.y] == '#';
}

void printPath(point b, point m, int p, int w) {
    if (p == 0 && w == 0)
        return;

    for (int i = 0; i < 4; i++) {
        point pm, pb;
        pm.x = m.x + dir[i][0], pm.y = m.y + dir[i][1];

        if (isUreachable(pm))
            continue;
        if (!(pm.x == b.x && pm.y == b.y) && best[b.x][b.y][pm.x][pm.y][0] == p &&
            best[b.x][b.y][pm.x][pm.y][1] == w - 1) {

            printPath(b, pm, p, w - 1), putchar(tolower(Dir[i]));
            break;
        }
        pb.x = b.x + dir[i][0], pb.y = b.y + dir[i][1];

        if (isUreachable(pb))
            continue;
        if (pb.x == m.x && pb.y == m.y && best[pb.x][pb.y][pm.x][pm.y][0] == p - 1 &&
            best[pb.x][pb.y][pm.x][pm.y][1] == w) {

            printPath(pb, pm, p - 1, w), putchar(Dir[i]);
            break;
        }
    }
}

void solve() {
    while (!q.empty())q.pop();

    int sx, sy, bx, by;
    memset(best, 0x6F, sizeof(best));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == 'S')sx = i, sy = j;
            else if (mp[i][j] == 'B')bx = i, by = j;

    State now, nex;
    now.box.x = bx, now.box.y = by, now.man.x = sx, now.man.y = sy,
    now.Push = 0, now.Walk = 0, q.push(now), BecomeBest(now);

    while (!q.empty()) {
        now = q.top(), q.pop();
        if (mp[now.box.x][now.box.y] == 'T') {
            printPath(now.box, now.man, now.Push, now.Walk), puts("");
            return;
        }
        for (int i = 0; i < 4; ++i) {
            nex = now, nex.man.x += dir[i][0], nex.man.y += dir[i][1];
            if (isUreachable(nex.man))
                continue;

            if (nex.man.x == now.box.x && nex.man.y == now.box.y) {
                nex.box.x += dir[i][0], nex.box.y += dir[i][1];
                if (isUreachable(nex.box))
                    continue;
                nex.Push++;
                if (!Batter(nex))
                    continue;
                q.push(nex), BecomeBest(nex);
            } else {
                nex.Walk++;
                if (!Batter(nex))
                    continue;
                q.push(nex), BecomeBest(nex);
            }
        }
    }
    puts("Impossible.");
}

int main() {
    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0)return 0;
        while (getchar() != '\n');
        for (int i = 1; i <= n; i++)gets(mp[i] + 1);
        printf("Maze #%d\n", ++t);
        solve();
        puts("");
    }
    return 0;
}