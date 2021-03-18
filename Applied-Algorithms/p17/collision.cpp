#include <iostream>
#include <string>

using namespace std;

const int N = 30000 * 2 + 10;

//Row, column, diagonal 1, subdiagonal
int row[N/2], col[N/2], dia1[N], dia2[N];

int main()
{
    int n, g;
    while (cin >> n && n != EOF && n)
    {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(dia1, 0, sizeof(dia1));
        memset(dia2, 0, sizeof(dia2));

        cin >> g;
        int k, x, y, s, t, tmpx, tmpy;
        while (g--){
            cin >> k >> x >> y >> s >> t;

            for (int i = 0; i < k; i++){
                tmpx = x + i * s;
                tmpy = y + i * t;
                row[tmpx]++;
                col[tmpy]++;
                int tmp = tmpx - tmpy;
                if(tmp < 0) tmp += 2 * (n-1) + 1;
                dia1[tmp]++;
                dia2[tmpx+tmpy]++;
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (row[i]) sum += row[i] - 1;
            if (col[i]) sum += col[i] - 1;
        }
        for (int i = 0; i <= n + n; i++){
            if (dia1[i]) sum += dia1[i] - 1;
            if (dia2[i]) sum += dia2[i] - 1;
        }
        cout << sum << endl;
    }
}