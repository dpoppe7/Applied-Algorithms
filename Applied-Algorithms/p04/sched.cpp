//Name: Damaris Poppe
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Values{
    int numOrder, deadline, profit;
};

#define T 1000 //max size of Deadlines
int schedule(vector<Values> const &myVector){
    int maxprofit = 0;
    vector<int> pos(T, -1);

    for(const Values &t : myVector){
        for(int j = t.deadline - 1; j >= 0; j--){
            if(j < T && pos[j] == -1){
                pos[j] = t.numOrder;
                maxprofit += t.profit;
                break;
            }
        }
    }
    return maxprofit;
}

int main() {
    int TC;
    int a, b, c;

    while (cin >> TC && TC > 0) {
        vector<Values> myVector;
        do{
            cin >> a >> b >> c;
            Values elem = {a, b, c};
            myVector.push_back(elem);
            TC--;
        }while(TC != 0);
        sort(myVector.begin(), myVector.end(),
             [](Values &a, Values &b) {
                 return a.profit > b.profit;
             });

        cout << schedule(myVector) << endl;
    }
}

