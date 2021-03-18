//Name: Damaris Poppe
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
void mayanCharacter(int num){
    int fives;
    fives = num / 5;
                            //num = 12
    int temp = fives * 5;//ie. 2 * 5 = 10...num of fives
    int ones = num - temp;//ie. 12 - 10 = 2..num of ones

    if(num == 0){
        cout << "@" << endl;
    }
    bool done =  false;
    while (ones > 0){
        cout << "*";
        ones--;
        done = true;
    }
    if(done == true) cout << endl;
    while (fives > 0){
        cout << "-----" << endl;
        fives--;
    }
}

void mayan_to_decimal(int n){
    int exp = 4;
    int mayanNum;

    //0 case
    if(n == 0){
        mayanCharacter(n);
        cout << "#" << endl;
    }

    //find higest power of 20
    while(n / pow(20, exp) < 1){
        exp--;
    }
    int temp_ex = exp;
    //cout << "Exp : " << exp << endl;

    int count = 0;
    while(n / pow(20, exp) > 0){ //ie. 15/1 = 15...last one
        mayanNum = n / pow(20, exp);
        //cout << mayanNum << " ";
        count++;
        mayanCharacter(mayanNum);
        if (pow(20, exp) > 1){
            cout << endl;
        }
        else{
            cout << "#" << endl;
        }

        int temp = pow(20, exp);
        n = n % temp; //215 % 20 = 15...next n

        exp--;
    }
    //cout << "Count : " << count << endl;

    while (count < temp_ex + 1){ //1 , 4
        cout << "@" << endl;
        if (count < temp_ex){
            cout << endl;
        }
        else{
            cout << "#" << endl;
        }
        count++;
    }
}

int sum(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int to_digit(vector <int> v1){
    int result = 0;
    int exponent = v1.size() - 1;
    for(int i = 0; i < v1.size(); i++){
        result += v1[i] * pow(20, exponent);
        exponent--;
    }
    return result;
}

int main(){
    string character;
    char op;
    int decimal = 0;
    vector <int> convertedDigits;
    vector <int> numbers;

    while (getline(cin, character) && character != "0"){
        int x, y;
        bool isready;
        if(character == "+" || character == "-"){
            isready = true;
            x = y;

            if(character == "+") op = '+';
            if(character == "-") op = '-';

            numbers.clear();
            decimal = 0;
            //cout << endl;
        }
        if(character != "#") {
            if (!character.empty()) {
                //cout << character << endl;
                if (character == "@") {
                    decimal += 0;
                }
                if (character.find("*") != string::npos) {
                    decimal += character.length();
                } else if (character == "-----") {
                    decimal += 5;
                }
            }else {
                numbers.push_back(decimal);
                //cout << decimal << endl;
                decimal = 0;
                //cout << endl;
            }
        }
        else{
            numbers.push_back(decimal);
            //cout << decimal << endl;
            y = to_digit(numbers);
            //cout << "Digit = " << y << endl;
            //cout << "#" << endl;

            if (isready == true){
                int newElem;
                if (op == '+') {
                    newElem = sum(x, y);
                    convertedDigits.push_back(newElem);
                    //cout << newElem << endl;
                }
                if (op == '-') {
                    newElem = sub(x, y);
                    convertedDigits.push_back(newElem);
                    //cout << newElem << endl;
                }

                //clear vector, set new decimal
                numbers.clear();
                decimal = 0;
                //cout << endl;
                isready = false;
            }
        }
    }

    for (auto e : convertedDigits){
        //cout << e << endl;
        mayan_to_decimal(e);
    }

    return 0;
}