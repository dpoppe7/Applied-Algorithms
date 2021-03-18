//Damaris Poppe
#include <iostream>

using namespace std;

struct Point {
    double x, y;
};

const int N = 1000;
Point p[N];

double distance(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    int n;
    while (cin >> n) {
        Point gopher, dog; //coord1, coord2
        cin >> gopher.x >> gopher.y >> dog.x >> dog.y;

        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (4.0 * distance(p[i], gopher) <= distance(p[i], dog)) {
                ans = i;
                break;
            }
        }

        if (ans == -1)
            printf("The gopher cannot escape.\n");
        else //print ans with double decimals
            printf("The gopher can escape through the hole at (%.3f,%.3f).\n", p[ans].x, p[ans].y);
    }
    cout << endl;

    return 0;
}