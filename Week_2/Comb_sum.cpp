/*
Description
Given two integer n and M. Write a program that generates all ordered collection (X1, X2, ..., Xn) such that: X1 + X2 + . . . + Xn = M
Input
Line 1: contains 2 integers n and M (2 <= n <= 10, 1 <= M <= 20)
Output
Write in each line X1, X2, ..., Xn separated by a SPACE character
Example
Input
3  5
Output
1 1 3
1 2 2
1 3 1
2 1 2
2 2 1
3 1 1
*/
#include<bits/stdc++.h>
using namespace std;

int n, target;

void print(vector<int> combo) {
    for(int i = 0; i < combo.size(); i++) {
        cout << combo[i] << " ";
    }
    cout << endl;
}

void combSum(vector<int>& combo, int total, int count) {
    if(total > target) return;
    if(total == target && count == n) {
        print(combo);
        return;
    }

    for(int i = 1; i < target; i++) {
        combo.push_back(i);
        combSum(combo, total + i, count + 1);
        combo.pop_back();
    }
}

int main() {
    cin >> n >> target;
    vector<int> combo;
    combSum(combo, 0, 0);

    return 0;
}
