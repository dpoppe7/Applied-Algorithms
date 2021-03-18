//Damaris Poppe
#include <iostream>
#include <string>

using namespace std;

bool str_validate(string str) {
    bool isvalid;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '/' || str[i] == 'X' ||
            (str[i] >= '0' && str[i] <= '9')) {
            isvalid = true;
        } else {
            isvalid = false;
            break;
        }
    }
    return isvalid;
}

int open(int i, string seq) {
    if ((seq[i] >= '0' && seq[i] <= '9') &&
        (seq[i+1] >= '0' && seq[i+1] <= '9')) {
        int num1 = seq[i] - '0';
        int num2 = seq[i + 1] - '0';
        int sum = num1 + num2;
        if (sum < 10) {
            return sum;
        }
    }
    return -1;
}

int spare(int i, string seq){
    int sum;
    if ((seq[i] >= '0' && seq[i] <= '9') &&
        (seq[i+1] == '/')) {
        if (seq[i+2] == 'X') {
            sum = 20;
        }
        else if (seq[i+2] >= '0' && seq[i+2] <= '9'){
            int num = seq[i+2] - '0';
            sum = 10 + num;
        }
        else{
            sum = -1;
        }
        return sum;
    }
    return -1;
}

int strike(int i, string seq){
    int sum;
    if (seq[i] == 'X') {
        //cout << " " << seq[i] << " ";
        if (seq[i+1] == 'X' && seq[i+2] == 'X') {  // X X X
            sum = 30;
        }
        else if (seq[i+1] == 'X' &&
            (seq[i+2] >= '0' && seq[i+2] <= '9')) { // X X 8
            int num = seq[i + 2] - '0';
            sum = 20 + num;
        }
        else if ((seq[i+1] >= '0' && seq[i+1] <= '9') && // X 7 2
            (seq[i+2] >= '0' && seq[i+2] <= '9')){
            /*int num1 = seq[i + 1] - '0';
            int num2 = seq[i + 2] - '0';
            sum = 10 + num1 + num2;*/
            if (open(i+1, seq) != -1)
                sum = 10 + open(i+1, seq);
            else
                sum = -1;
        }
        else if ((seq[i+1] >= '0' && seq[i+1] <= '9') && // X 7 /
            seq[i+2] == '/'){
            sum = 20;
        }
        else {   // X / 7, X X /
            sum = -1;
        }
        return sum;
    }
    return -1;
}

int main() {
    string seq;

    while (cin >> seq && seq != "*") {
        int i = 0;
        if (seq[i] == '*'){ //first char is *, end of input
            return 0;
        }
        /*for (int i = 0; i< seq.length(); i++){
            cout << seq[i] ;
        }cout << endl;*/

        if (str_validate(seq)) {
            int frame = 0;
            int total = 0;
            int counter = 0;
            bool isfull = false;
            while (frame != 10) {
                //OPEN CASE
                if (open(i, seq) != -1) {
                    //cout << seq[i] << " " << seq[i + 1] << " : " << open(i, seq) << " ";
                    total += open(i, seq);
                    i = i + 2;
                    counter++;
                    if (frame == 9 && (i == seq.length())) //last one, full
                        isfull = true;
                }
                //SPARE CASE
                else if (spare(i, seq) != -1) {
                    //cout << seq[i] << seq[i + 1] << seq[i + 2] << " : " << spare(i, seq) << " ";
                    total += spare(i, seq);
                    i = i + 2;
                    counter++;
                    if (frame == 9 && (i + 1 == seq.length()))  //last one, full
                        isfull = true;
                }
                //STRIKE CASE
                else if (strike(i, seq) != -1) {
                    //cout << seq[i] << seq[i + 1] << seq[i + 2] << " : " << strike(i, seq) << " ";
                    total += strike(i, seq);
                    i = i + 1;
                    counter++;
                    if (frame == 9 && (i + 2 == seq.length())) //last one, full
                        isfull = true;
                }
                frame++;
                //cout << "F: " << frame << " char_at: " << i << " & " << seq.length() << endl;
            }
            //cout << "counter : " << counter << endl;
            if (counter == 10 && isfull == true)
                cout << total << endl;
            else
                cout << "INVALID" << endl;
        }
        else {
            cout << "INVALID" << endl;
        }
        //cout << endl;
    }
    return 0;
}