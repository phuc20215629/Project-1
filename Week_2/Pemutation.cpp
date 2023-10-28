/*
Description
Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
Example
Input 
3
Output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
*/

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> res;
vector<bool> check;

void print() {
    for(int i = 0; i < n; i++) cout << res[i] <<  " ";
    cout << endl;
}

void Try(int k) {
    for(int i = 1; i <= n; i++) {
        if(!check[i]) {
            res[k] = i;
            check[i] = true;
            if(k == n - 1) print();
            else Try(k + 1);
            check[i] = false;
        }
    }

}
int main() {
    cin >> n;
    res.resize(n + 1, 0);
    check.resize(n + 1, false);
    Try(0);
    return 0;
}