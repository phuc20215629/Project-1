/*
Description
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder, eac sequence in a line
*/

//C++ 
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> res;

void Try(int k, vector<int> seq) {
    if(k == n) {
        for(auto bit : seq) cout << bit;
        cout << endl;
        return;
    }
    seq[k] = 0;
    Try(k + 1, seq);

    seq[k] = 1;
    Try(k + 1, seq);
}

int main() {
    cin >> n;
    res.resize(n, 0);
    Try(0, res);
    return 0;
}
