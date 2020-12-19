// UVa Online Judge 227: Puzzle
//  227
//  Created by David del Val on 16/12/2020
//
//
#include <bits/stdc++.h>

using namespace std;

char board[5][5];
int empty_i, empty_j;

void loadboard(string s[5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < s[i].length(); ++j) {
            board[i][j] = s[i][j];
            if (s[i][j] == ' ') {
                //cout << "empty" << i << " " << j << endl;
                empty_i = i;
                empty_j = j;
            }
        }
        if (s[i].length() < 5) {
            //cout << "empty" << i << " " << 5 << endl;
            empty_i = i;
            empty_j = 4;
            board[i][4] = ' ';
        }
    }
}
void printboard() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (j) {
                cout << " ";
            }
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int move(string moves) {
    for (char c : moves) {
        int n_empty_i = empty_i;
        int n_empty_j = empty_j;
        if (c == 'A') {
            n_empty_i--;
        }
        if (c == 'B') {
            n_empty_i++;
        }
        if (c == 'R') {
            n_empty_j++;
        }
        if (c == 'L') {
            n_empty_j--;
        }
        if (n_empty_i < 0 || n_empty_j < 0 || n_empty_j > 4 || n_empty_i > 4) {
            return -1;
        } else {
            /*cout << "swap:" << c << "\n";
            printboard();
            cout << empty_i << " " << empty_j << " " << n_empty_i << " " << n_empty_j << "\n";*/
            swap(board[n_empty_i][n_empty_j], board[empty_i][empty_j]);
            /*cout << "swap2:\n";
            printboard();*/
        }
        empty_i = n_empty_i;
        empty_j = n_empty_j;
    }
    return 0;
}

int main() {
    string in[5];
    getline(cin, in[0]);
    in[0];
    int z = 1;
    while (1) {
        for (int i = 1; i < 5; ++i) {
            getline(cin, in[i]);
        }
        loadboard(in);
        //printboard();
        string s;
        getline(cin, s);
        while (s.back() != '0') {
            string s2;
            getline(cin, s2);

            s.append(s2);
        }
        cout << "Puzzle #" << z << ":\n";
        if (move(s)) {
            cout << "This puzzle has no final configuration.\n";
        } else {
            printboard();
        }
        z++;
        getline(cin, in[0]);
        if (in[0][0] == 'Z') {
            break;
        } else {
            cout << "\n";
        }
    }
}