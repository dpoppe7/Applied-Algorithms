//Damaris Poppe
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 26; //villages
int f[N + 1];

void Const(int n) {
    for (int i = 1; i <= n; i++)
        f[i] = i;
}

int Find(int a) {
    return a == f[a] ? a : f[a] = Find(f[a]);
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        f[a] = b;
        return true;
    } else
        return false;
}

struct Edge {
    int u, v, w;
} edges[N * (N - 1)];

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n; //# of villages
    char start, end; //A .. B
    int nodes, cost, counter;
    while (cin >> n && n) {
        Const(N);

        counter = 0;
        for (int i = 0; i < n - 1; i++) {
            cin >> start >> nodes;
            for (int j = 1; j <= nodes; j++) {
                cin >> end >> cost;
                edges[counter].u = start - 'A' + 1;
                edges[counter].v = end - 'A' + 1;
                edges[counter++].w = cost;
            }
        }

        int ans = 0;
        sort(edges, edges + counter, cmp);
        for (int i = 0; i < counter; i++)
            if (Union(edges[i].u, edges[i].v))
                ans += edges[i].w;

        cout << ans << endl;
    }

    return 0;
}
