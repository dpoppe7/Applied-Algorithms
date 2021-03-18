//Damaris P
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
#define M 8

struct node {
    int a, b, c, f;
    char o;
} f[4], s[1000], start, ed;

//descriptions of machines
int visit[10][10][10];

int bfs() {
    int t = 0, w = 1;

    memset(visit, 0, sizeof(visit));
    //descriptions of machines
    visit[s[t].a][s[t].b][s[t].c] = 1;
    s[0].f = -1;

    while (t < w) {
        if (s[t].a > 0) {
            s[w].a = s[t].a + f[0].a - 1;
            s[w].b = s[t].b + f[0].b;
            s[w].c = s[t].c + f[0].c;
            s[w].f = t;
            s[w].o = 'A';
            if (s[w].a < M && s[w].b < M && s[w].c < M && !visit[s[w].a][s[w].b][s[w].c]) {
                if (s[w].a == ed.a && s[w].b == ed.b && s[w].c == ed.c) {
                    ed.f = w;
                    return w;
                }
                visit[s[w].a][s[w].b][s[w].c] = 1;
                w++;
            }
        }
        if (s[t].b > 0) {
            s[w].b = s[t].b + f[1].b - 1;
            s[w].a = s[t].a + f[1].a;
            s[w].c = s[t].c + f[1].c;
            s[w].f = t;
            s[w].o = 'B';
            if (s[w].a < M && s[w].b < M && s[w].c < M && !visit[s[w].a][s[w].b][s[w].c]) {
                if (s[w].a == ed.a && s[w].b == ed.b && s[w].c == ed.c) {
                    ed.f = w;
                    return w;
                }
                visit[s[w].a][s[w].b][s[w].c] = 1;
                w++;
            }
        }
        if (s[t].c > 0) {
            s[w].c = s[t].c + f[2].c - 1;
            s[w].b = s[t].b + f[2].b;
            s[w].a = s[t].a + f[2].a;
            s[w].f = t;
            s[w].o = 'C';
            if (s[w].a < M && s[w].b < M && s[w].c < M && !visit[s[w].a][s[w].b][s[w].c]) {
                if (s[w].a == ed.a && s[w].b == ed.b && s[w].c == ed.c) {
                    ed.f = w;
                    return w;
                }
                visit[s[w].a][s[w].b][s[w].c] = 1;
                w++;
            }
        }
        if (s[t].a >= f[0].a && s[t].b >= f[0].b && s[t].c >= f[0].c) {
            s[w].a = s[t].a - f[0].a + 1;
            s[w].b = s[t].b - f[0].b;
            s[w].c = s[t].c - f[0].c;
            s[w].f = t;
            s[w].o = 'a';
            if (s[w].a < M && s[w].b < M && s[w].c < M && !visit[s[w].a][s[w].b][s[w].c]) {
                if (s[w].a == ed.a && s[w].b == ed.b && s[w].c == ed.c) {
                    ed.f = w;
                    return w;
                }
                visit[s[w].a][s[w].b][s[w].c] = 1;
                w++;
            }
        }
        if (s[t].a >= f[1].a && s[t].b >= f[1].b && s[t].c >= f[1].c) {
            s[w].b = s[t].b - f[1].b + 1;
            s[w].a = s[t].a - f[1].a;
            s[w].c = s[t].c - f[1].c;
            s[w].f = t;
            s[w].o = 'b';
            if (s[w].a < M && s[w].b < M && s[w].c < M && !visit[s[w].a][s[w].b][s[w].c]) {
                if (s[w].a == ed.a && s[w].b == ed.b && s[w].c == ed.c) {
                    ed.f = w;
                    return w;
                }
                visit[s[w].a][s[w].b][s[w].c] = 1;
                w++;
            }
        }
        if (s[t].a >= f[2].a && s[t].b >= f[2].b && s[t].c >= f[2].c) {
            s[w].c = s[t].c - f[2].c + 1;
            s[w].b = s[t].b - f[2].b;
            s[w].a = s[t].a - f[2].a;
            s[w].f = t;
            s[w].o = 'c';
            if (s[w].a < M && s[w].b < M && s[w].c < M && !visit[s[w].a][s[w].b][s[w].c]) {
                if (s[w].a == ed.a && s[w].b == ed.b && s[w].c == ed.c) {
                    ed.f = w;
                    return w;
                }
                visit[s[w].a][s[w].b][s[w].c] = 1;
                w++;
            }
        }
        t++;
    }
    return 0;
}

int main() {
    int t, i, j, n, num, tt;
    char count[100];
    cin >> t;
    while (t--) {
        cin >> num >> n;
        cout << num << " " << n << endl;
        for (i = 0; i < 3; i++)
            cin >> f[i].a >> f[i].b >> f[i].c;
        while (n--) {
            cin >> tt;
            cin >> s[0].a >> s[0].b >> s[0].c >> ed.a >> ed.b >> ed.c;
            cout << tt << " ";
            int temp = bfs();
            if ((i = temp)) {
                for (j = 98; i > 0; j--) {
                    count[j] = s[i].o;
                    i = s[i].f;
                }
                count[99] = '\0';
                cout << (98 - j) << endl;
            } else cout << "NO SOLUTION" << endl;
        }
    }
    return 0;
}