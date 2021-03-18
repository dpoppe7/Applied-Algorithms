//Damaris Poppe
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int Pair(string line){
    int i = 0;
    int j = 1;
    int totalpair = 0;
    while (line.length() != 2) {
        for (int temp = 3; temp < line.length(); temp += 3) {
            //cout << line[i] << " " << line[temp] << endl;
            if (line[i] == line[temp] && line[j] != line[j+3]) {
                totalpair++;
            }
        }
        line.erase(0, 3);
    }
    return totalpair;
}

int SameSuit(string line){
    vector<char> suits;
    for (int curr = 1; curr < line.length(); curr += 3){
        suits.push_back(line[curr]);
    }

    int count = 0;
    for (int i = 0; i < suits.size() - 1; i++){
        if (suits[i] == suits[0]){
            count++;
        }
    }

    if (count > 3) { //first 4 are the same suit
        if (suits[4] == suits[0]) {
            return 5;
        }
        return 4;
    }

    return 0;
}

int char_to_val(char elem){
    int value = 0;
    if (elem == 'A') value = 1;
    if (elem == 'T') value = 10;
    if (elem == 'J') value = 11;
    if (elem == 'Q') value = 12;
    if (elem == 'K') value = 13;
    return value;
}

int DistinctStraights(vector<pair<int, char>> cards){
    vector<pair<int, char> >::iterator it;
    vector<int> temp;
    for (it = cards.begin(); it < cards.end(); it++){
        temp.push_back(it->first);
    }

    int total = 0;
    for (int i = 0; i < 5; ) {
        int dups = count(temp.begin(), temp.end(), temp[i]);

        if ( dups > 1 ) {
            //cout << temp[i] << " is a duplicated number, times: " << dups << endl;
            total += dups;
        }
        int last = temp[i];
        i++;

        while(temp[i] == last) {
            ++i;
        }
    }
    return total;
}

int StraightCounter(vector<pair<int, char>> cards) {
    int total = 0;

    map<int, char> straight;
    map<int, char>::iterator it;

    int count = 0;
    do{
        int min = cards[count].first;
        int next = min + 1;
        int i = 0;
        while (i < cards.size()) {
            //cout << i << " - " << min << " - " << next << " - " << count << " c: " << endl;
            if (cards[i].first == next) { //found
                it = straight.find(cards[i].first);
                if (it != straight.end()) {
                    straight.insert(pair<int, char>(cards[i].first, cards[i].second));
                } else {
                    straight.insert(pair<int, char>(cards[count].first, cards[count].second));
                    straight.insert(pair<int, char>(cards[i].first, cards[i].second));
                }

                count++;
                next++;
                i = 0;
            } else {
                i++;
            }
        }
        if(straight.size() < 3){
            //cout << "clear()" << endl;
            straight.clear();
        }

        count++;
    }while(count < 3);
    //Printing straight map
     /*for (it = straight.begin(); it != straight.end(); ++it)
        cout << it->first << " => " << it->second << '\n';*/

    if(straight.size() > 2 && straight.size() <= 5){
        //cout << "Size: " << straight.size() << endl;
        if (DistinctStraights(cards) > 1){
            total = DistinctStraights(cards);
        }
        else{
            total++; // only one straight
        }
    }
    //cout << "total straights: " << total << endl;
    int straight_points = total * straight.size();

    return straight_points;
}

int Straights(string line){
    vector<pair<int, char>> cards;
    int num;
    for (int i = 0; i < line.length(); i += 3){
        char suit = line[i + 1];
        if (char_to_val(line[i]) > 0){
            num = char_to_val(line[i]);
        }
        else {
            num = line[i] - '0';
        }
        pair<int, char> tuple = make_pair(num, suit);
        cards.push_back(tuple);
    }
    sort(cards.begin(), cards.end());

    return StraightCounter(cards);
}

int sum_up(vector<int> numbers, int target, vector<int> partial, int &count){
    int s = 0;
    for (vector<int>::const_iterator cit = partial.begin(); cit != partial.end(); cit++){
        //cout << s << " - " << *cit << endl;
        s += *cit;
    }

    if(s == target){
        count++;
        /*cout << "sum([";
        for (vector<int>::const_iterator cit = partial.begin(); cit != partial.end(); cit++){
            cout << *cit << ",";
        }
        cout << "])=" << target << endl;*/
    }

    int n;
    for (vector<int>::const_iterator ai = numbers.begin(); ai != numbers.end(); ai++){
        n = *ai;
        vector<int> remaining;

        for(vector<int>::const_iterator aj = ai; aj != numbers.end(); aj++){
            if(aj == ai){
                continue;
            }
            remaining.push_back(*aj);
        }

        vector<int> partial_rec = partial;
        partial_rec.push_back(n);
        sum_up(remaining, target, partial_rec, count);
    }
    return count;
}

int Combination(string line){
    vector<int> cardValues;

    for (int i = 0; i < line.length(); i += 3){
        if (line[i] == 'T' || line[i] == 'J' || line[i] == 'Q' || line[i] == 'K'){
            cardValues.push_back(10);
        }
        else if (line[i] == 'A'){
            cardValues.push_back(1);
        }
        else {
            int num = line[i] - '0';
            cardValues.push_back(num);
        }
    }
    sort(cardValues.begin(), cardValues.end());
    /*for (auto e : cardValues){
        cout << e << " ";
    }cout << endl;*/

    int count = 0;
    vector<int> temp;
    return sum_up(cardValues, 15, temp, count);
}

bool JackSuit (string line){
    char startCardSuit = line[13];
    line.erase(11, 13);
    int pos = line.find('J');
    if (line[pos + 1] == startCardSuit){
        //cout << "Found : " << line[pos] << line[pos+1] << endl;
        return true;
    }
    return false;
}

int main() {
    string line;
    while (getline(cin, line) &&
           line != "0 0 0 0 0"){
        /*
        cout << line << endl;
        cout << "Pair Points: " << Pair(line) * 2 << endl;
        cout << "Suit Points: " << SameSuit(line) << endl;
        cout << "Straight Points: " << Straights(line) << endl;
        cout << "addUpTo 15 Points: " << Combination(line) * 2 << endl;
        cout << "Jack suit Points: " << JackSuit(line) << endl;
        */

        int totalScore = 0;
        totalScore += Pair(line) * 2;
        totalScore += SameSuit(line);
        totalScore += Straights(line);
        totalScore += Combination(line) * 2;
        totalScore += JackSuit(line);
        cout << totalScore << endl;
        //cout << endl;
    }
    return 0;
}