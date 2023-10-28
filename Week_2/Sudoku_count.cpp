/*
Write a program to compute the number of sudoku solutions (fill the zero elements of a given partial sudoku table)
Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:
Numbers of each row are distinct
Numbers of each column are distinct
Numbers on each sub-square 3 x 3 are distinct
Input
Each line i (i = 1, 2, ..., 9) contains elements of the i
th
 row of the Sudoku table: elements are numbers from 0 to 9 (value 0 means the empty cell of the table)
Output
Write the number of solutions found

Example
Input
0 0 3 4 0 0 0 8 9
0 0 6 7 8 9 0 2 3
0 8 0 0 2 3 4 5 6
0 0 4 0 6 5 0 9 7
0 6 0 0 9 0 0 1 4
0 0 7 2 0 4 3 6 5
0 3 0 6 0 2 0 7 8
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
Output
64
*/
#include<bits/stdc++.h>
using namespace std;

const int SIZE = 9;

bool isValid(vector<vector<int>> a, int row, int col, int num) {
    for(int i = 0; i < 9; i++) {
        if(a[row][i] == num || a[i][col] == num) return false;
    }

    int rs = (row / 3) * 3;
    int cs = (col / 3) * 3;
    for(int i = rs; i < rs + 3; i++) {
        for(int j = cs; j < cs + 3; j++) {
            if(a[i][j] == num) return false;
        }
    }
    return true;
}

int countSudokuSolutions(vector<vector<int>>& a) {
    int count = 0;
    int row = -1;
    int col = -1;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (a[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    if (row == -1) {
        return 1;
    }

    for (int num = 1; num <= 9; ++num) {
        if (isValid(a, row, col, num)) {
            a[row][col] = num;

            count += countSudokuSolutions(a);

            a[row][col] = 0;
        }
    }

    return count;
}

int main() {
    vector<vector<int>> a(SIZE, vector<int>(SIZE));
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            cin >> a[row][col];
        }
    }

    int solutions = countSudokuSolutions(a);

    cout  << solutions << endl;

    return 0;
}
