//Name: Damaris Poppe
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    string str;

    while (cin >> m >> n && cin >> str && m > 0 && n > 0) {
        if (str.size() == m) {
            vector<int> captives;
            vector<char> pills(str.size());
            copy(str.begin(), str.end(), pills.begin());

            for (int captiveNum = 1; captiveNum <= n; captiveNum++) {
                pills.push_back(pills[0]);    //copy element to the back
                pills.erase(pills.begin()); //erase front element/new pile

                if (pills[0] == 'B') {
                    captives.push_back(captiveNum);
                }
                pills.erase(pills.begin()); //captive eats pill/erase front
            }

            sort(captives.begin(), captives.end());
            if (captives.empty())
                cout << "0";
            else {
                cout << captives[0];
                for (int i = 1; i < captives.size(); ++i) {
                    cout << " " << captives[i];
                }
            }
        }
        cout << endl;
    }
    return 0;
}

