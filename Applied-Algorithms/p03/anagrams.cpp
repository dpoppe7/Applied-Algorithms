//Damaris Poppe
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

template <typename Map>
bool map_compare (Map const &map1kv, Map const &map2kv) {
    return map1kv.size() == map2kv.size()       //operator == for pairs
           && equal(map1kv.begin(), map1kv.end(),
                         map2kv.begin());
}

map<char, int> newMap(string str){
    map<char, int> m;
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (int i = 0; str[i]; i++) {
        if (m.find(str[i]) == m.end()) {
            m.insert(make_pair(str[i], 1));
        }
        else
            m[str[i]]++;
    }
    return m;
}

string deleteNonAlpha(string sentence){
    for (int i = 0; i < sentence.size(); ++i) {
        if ((sentence[i] < 'A' || sentence[i] > 'Z')
        && (sentence[i] < 'a' || sentence[i] > 'z')){
            sentence.erase(i, 1);
            i--;
        }
    }
    return sentence;
}

int main(){
    string s1, s2;

    while(getline(cin, s1) && getline(cin, s2)
    && s1 != "<end>" && s2 != "<end>"){
        s1 = deleteNonAlpha(s1);
        s2 = deleteNonAlpha(s2);

        map <char, int> map1 = newMap(s1);
        map <char, int> map2 = newMap(s2);

        if (map_compare(map1, map2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

