/*
Description
Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
Given positive integers k and m. Compute the number Q of k-subsequences such that the weight is even.
Input
Line 1: contains 2 positive integers n, k (1 <= n <= 100000, 1 <= k <= n/2)
Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
Output
Write the value Q
Example
Input
6  3
2 4 5 1 1 2 
Output
2
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i  = 0; i <= n - k; i++) {
        int sum = 0;
        for(int j = i; j < i + k; j++) {
            sum += arr[j];
        }
        if(sum % 2 == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
