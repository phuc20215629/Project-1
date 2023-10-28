/*
Description
Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic order, each sequence in a line
*/
#include<bits/stdc++.h>
using namespace std;

void binGen(int n, vector<int> seq, int i) {
    if(i == n) {
        for(auto bit : seq) cout << bit;
        cout << endl;
        return;
    }

    seq[i] = 0;
    binGen(n, seq, i + 1);
    
    if(seq[i - 1] == 1) return;
    seq[i] = 1;
    binGen(n, seq, i + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> res;
    res.resize(n, 0);
    binGen(n, res, 0);
    return 0;
}
