//Name: Damaris Poppe
#include <iostream>
#include <vector>

using namespace std;

bool Sum(vector<int> nums, int size, int target){
    bool subset[size + 1][target + 1];

    for (int i = 0; i <= size; i++)
        subset[i][0] = true;
    for (int i = 1; i <= target; i++)
        subset[0][i] = false;

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= target; j++) {
            if (j < nums[i - 1])
                subset[i][j] = subset[i - 1][j];
            else {
                subset[i][j] = subset[i - 1][j] ||
                               subset[i - 1][j - nums[i - 1]];
            }
        }
    }

    if ((subset[size][target]) == 0)
        return false;
    else
        return true;
}


void divisors(int num){
    vector<int> divisors;
    cout << num << ":";
    for (int i = 1; i < num; i++){
        if (num % i == 0){
            divisors.push_back(i);
        }
    }

    int n = divisors.size();
    bool x = Sum(divisors, n, num);
    if (!x) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int num;
    while (cin >> num && num > 0) {
        divisors(num);
    }
    return 0;
}

