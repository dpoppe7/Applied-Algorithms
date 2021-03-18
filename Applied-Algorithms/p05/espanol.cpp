//Name: Damaris Poppe
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <iostream>

using namespace std;

map <string, string> create_map(){
    map <string, string> m;
    m["a"] = "10"; m["b"] = "11"; m["c"] = "12"; m["ch"] = "13";
    m["d"] = "14"; m["e"] = "15"; m["f"] = "16"; m["g"] = "17";
    m["h"] = "18"; m["i"] = "19"; m["j"] = "20"; m["k"] = "21";
    m["l"] = "22"; m["ll"] = "23"; m["m"] = "24"; m["n"] = "25";
    m["~n"] = "26"; m["o"] = "27"; m["p"] = "28"; m["q"] = "29";
    m["r"] = "30"; m["rr"] = "31"; m["s"] = "32"; m["t"] = "33";
    m["u"] = "34"; m["v"] = "35"; m["w"] = "36"; m["x"] = "37";
    m["y"] = "38"; m["z"] = "39";
    return m;
}

int main(){
    int TC;
    string s1;

    vector <vector<string>> data;
    vector <vector<string>> numData;

    map <string, string> myMap = create_map();
    map <string, string>::iterator it = myMap.begin();

    cin >> TC;
    while(TC-- && cin >> s1){
        vector <string> newString;
        for (int i = 0; i < s1.length(); i++){
            if(s1[i] == 'c' && s1[i+1] == 'h') {
                newString.push_back("ch");
                i = i + 2;
            }
            if(s1[i] == 'l' && s1[i+1] == 'l') {
                newString.push_back("ll");
                i = i + 2;
            }
            if(s1[i] == 'r' && s1[i+1] == 'r') {
                newString.push_back("rr");
                i = i + 2;
            }
            if(s1[i] == '~' && s1[i+1] == 'n') {
                newString.push_back("~n");
                i = i + 1;
            }
            else{
                string s(1, s1[i]);
                newString.push_back(s);
            }
        }

        vector <string> newstrNums;
        string numerical;
        for (int i = 0 ; i < newString.size(); i++){
            it = myMap.find(newString[i]);
            if(it != myMap.end()){
                numerical += it->second;
            }
        }
        newstrNums.push_back(numerical);
        numData.push_back(newstrNums);

        data.push_back(newString);

    }
    sort(numData.begin(), numData.end());

    /*for (int i = 0; i < numData.size(); i++) {
        for (int j = 0; j < numData[i].size(); j++) {
            cout << i << " : " << numData[i][j];
        }
        cout << endl;
    }*/

    for (int i = 0; i < numData.size(); i++) {
        for (int j = 0; j < numData[i].size(); j++) {
            string strNum;
            string valueToFind;

            strNum = numData[i][j];

            for (int k = 0; k < strNum.length(); k++){
                string one, two;
                one = strNum[k];
                two = strNum[k+1];
                valueToFind = one + two;

                map <string, string>::iterator it2 = myMap.begin();
                string foundkey;

                while(it2 != myMap.end()){
                    if(it2->second == valueToFind){
                        foundkey = it2->first;
                    }
                    it2++;
                }

                cout << foundkey;
                k++;
            }
            cout << endl;
        }
    }

    return 0;
}

