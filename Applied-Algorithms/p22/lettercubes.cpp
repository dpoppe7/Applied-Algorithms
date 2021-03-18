#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int MAX_N = 30;
const int MAX_K = 4;
const int MAX_TRIALS = 20; //1-20
int N, K;

string alpha;
vector<string> myVec;
map<char,set<char> > myMap;

void print(vector<string> &sol) {
    for (int d=0; d < sol.size(); d++) {
        if (d != 0) cout << " ";
        cout << sol[d];
    }
    cout << endl;
}

void solve(int j, vector<string> &partial) {
    if (j == 6*K) {
        if (myVec.empty())
            myVec = partial;
        else {
            print(partial);
        }
    } else {
        for (int d=0; d < partial.size(); d++) {
            if (partial[d].size() < 6) {
                bool legal=true;
                for (int c=0; c < partial[d].size(); c++)
                    if (myMap[alpha[j]].find(partial[d][c]) != myMap[alpha[j]].end()) {
                        legal = false; break;
                    }
                if (legal) {
                    partial[d].push_back(alpha[j]);
                    solve(j+1, partial);
                    partial[d].erase(partial[d].size()-1);
                }
            }
        }

        if (partial.size() < K) {
            string newest;
            newest.push_back(alpha[j]);
            partial.push_back(newest);
            solve(j+1, partial);
            partial.pop_back();
        }
    }
}

int main(int argv, char** argc) {
    int trial=0;
    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        K = -1;
        trial++;
        myVec.clear();
        myMap.clear();
        alpha.clear();

        set<char> tempalpha;
        char extra;
        cin >> extra;

        if (extra != '-')
            tempalpha.insert(extra);
        for (int w=0; w<N; w++) {
            string word;
            cin >> word;
            if (K == -1)
                K = word.size();
            else if (word.size() != K) return 0;

            for (int i=0; i<K; i++) {
                tempalpha.insert(word[i]);
                for (int j=0; j<i; j++) {
                    myMap[word[i]].insert(word[j]);
                    myMap[word[j]].insert(word[i]);
                }
            }
        }

        alpha = string(tempalpha.begin(), tempalpha.end());

        vector<string> empty;
        solve(0, empty);
        print(myVec);

        if (alpha.size() != 6 * K) cout << "Incorrect alphabet size" << endl;
        if (trial > MAX_TRIALS) cout << "Too many trials: " << trial << endl;
        if (N > MAX_N) cout << "N is too large: " << N << endl;
        if (K > MAX_K) cout << "K is too large: " << N << endl;
        if (solution.empty()) cout << "UNSOLVABLE CASE" << endl;
    }
}