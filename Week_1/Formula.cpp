/*
Description
Given 2 integers a and b. Compute a+b, a-b, a*b, a/b.
Input
Line 1 contains 2 integers a and b (1 <= a,b <= 1000)
Output
Write a+b, a-b, a*b, a/b  (4 integers are separated by a SPACE characters)

Example
Input
9 4

Output 
13 5 36 2
*/

#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int a, b;
    cin >> a >> b;
    cout << a + b << " " << a - b << " " << a * b << " " << a / b << endl;
}
