/*
Description
Given a fibonacci sequence a[0], a[1], a[2], ... in which:  a[0] = 0, a[1] = 1, a[n] = a[n-1] + a[n-2], for all n >= 2
Given  positive integer n, compute a[n-1].
Input
Line 1: contains a positive integer n (2 <= n <= 21)
Output
Write a[n-1]
Example
Input
9
Output
21
*/

#include<bits/stdc++.h>
using namespace std;

int fibo(int n) {
    if(n <= 1) return n;
    else return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n; 
    cin >> n;
    cout << fibo(n - 1) << endl;
    return 0;
}