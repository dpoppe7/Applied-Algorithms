//Name: Damaris Poppe
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

bool isFound(char (&myarray) [4][4], int i, int j, string word, int index) {
    if(index == word.length()){
        return true;
    }
    if(i < 0 || j < 0 || i >= 4 || j >= 4) return false;
    if(word[index] != myarray[i][j]) return false;
    char temp = myarray[i][j];
    myarray[i][j] = '*';

    /*for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << myarray[i][j] << " ";
        }
        cout << endl;
    }cout << endl;*/

    if(isFound(myarray, i + 1, j, word, index + 1) ||
       isFound(myarray, i - 1, j, word, index + 1) ||
       isFound(myarray, i, j + 1, word, index + 1) ||
       isFound(myarray, i, j - 1, word, index + 1) ||
       isFound(myarray, i + 1, j + 1, word, index + 1) ||
       isFound(myarray, i + 1, j - 1, word, index + 1) ||
       isFound(myarray, i - 1, j + 1, word, index + 1) ||
       isFound(myarray, i - 1, j - 1, word, index + 1) ) {
        return true;
    }
    myarray[i][j] = temp;

    return false;
}

bool exist(char (&myArray) [4][4], string word) {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(myArray[i][j] == word[0] && isFound(myArray, i, j, word, 0))
                return true;

    return false;
}

int main(){
    string letterSet;
    string word;
    char myArray[4][4];

    for (int i = 0; i < 4; i++){
        cin >> letterSet;
        int curr = 0;
        for (int j = 0; j < 4; j++){
            myArray[i][j] = letterSet[curr];
            curr++;
        }
    }

    char tempArr[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tempArr[i][j] = myArray[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }

    while (cin >> word && word != "*") {
        cout << left << setw(17) << word;

        bool istrue = exist(myArray, word);
        if (!istrue) {
            cout << "NOT VALID" << endl;
        } else {
            cout << "VALID" << endl;
        }
        //set array to original grid tempArr is a copy of it
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                myArray[i][j] = tempArr[i][j];
            }
        }
    }
}