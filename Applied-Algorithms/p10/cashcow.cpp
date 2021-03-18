//Damaris Poppe
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<char> > board;
const int NUM_ROWS = 12;
const int NUM_COLS = 10;

void Board() {
    board.clear();
    for (int i=0; i < NUM_COLS; i++)
        board.push_back(vector<char>(NUM_ROWS,'.'));
    /*for ( const auto &row : board ){
        for ( const auto &s : row ) cout << s << ' ';
            cout << endl;
    }*/
    //INPUT board:
    for (int row=NUM_ROWS-1; row >= 0; row--) {
        string temp;
        cin >> temp;
        for (int col=0; col < NUM_COLS; col++) {
            board[col][row] = temp[col];
            //cout << board[col][row] << " ";
        }//cout << endl;
    }
}

int numPieces() {
    int total = 0;
    for (int row=NUM_ROWS-1; row >= 0; row--) {
        for (int col=0; col < NUM_COLS; col++)
            if (board[col][row] != '.')
                total++;
    }
    return total;
}

void find(int row, int col, set<pair<int,int> > &elem) {
    int delta[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    //cout << " R: " << row << " C: " << col << endl;
    for (int k=0; k < 4; k++) {
        int newR = row + delta[k][0];
        //cout << "newR: " << newR<< endl;
        int newC = col + delta[k][1];
        //cout << "newC: " << newC<< endl;
        if (newR >= 0 && newR < NUM_ROWS && newC >= 0 && newC < NUM_COLS
            && board[col][row] == board[newC][newR]
            && elem.find(make_pair(newC,newR)) == elem.end()) {
            elem.insert(make_pair(newC,newR));
            find(newR, newC, elem);
        }
    }
}

template <typename T>
void slideAndFill(vector<T> &data, T val) {
    typename vector<T>::iterator boundary = remove(data.begin(), data.end(), val);
    fill(boundary, data.end(), val);
}

void compact() {
    for (int c=0; c < NUM_COLS; c++)
        slideAndFill(board[c], '.');
    slideAndFill(board, vector<char>(NUM_ROWS, '.'));
}

void playerClick(int row, int col) {
    if (board[col][row] != '.') {
        set<pair<int,int> > group;
        group.insert(make_pair(col,row));
        find(row, col, group);
        if (group.size() >= 3) {
            for (set<pair<int,int> >::iterator it = group.begin(); it != group.end(); ++it)
            board[it->first][it->second] = '.';
            compact();
        }
    }
}

int main() {
    int t;
    while (true) {
        cin >> t;
        if (t == 0) break;
        Board();
        for (int j=0; j<t; j++){
            char c;
            int r;
            cin >> c >> r;
            //a = 0, zero index
            playerClick(r-1, c-'a');
        }
        cout << numPieces() << endl;
    }
}