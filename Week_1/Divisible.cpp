/*
Description
Given a positive integer n, find all integer having 3 digits which is divisible by n.
Input
Line 1: contains a positive integer n (1 <= n <= 999)
Output
Write the sequence of numbers found (elements are separated by a SPACE character)

Example
Input 
200

Output 
200 400 600 800
*/

#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int n, ans;
    cin >> n;
    int k = 100 / n;
    L: if(n * k >= 100) {
        do {
            ans = n * k;
            if(ans <= 999) cout << ans << " ";
            k++;
        } while(ans <= 999);
        return 0;
    }
    else {
        ++k;
        goto L;
    }
}
