/*
Description
Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
Input
Line 1 contains 3 integers a, b, c 
Output
Write NO SOLUTION if the given equation has no solution 
Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation has two distinct solutions x1, x2 

Example
Input 
1 1 8
Output 
NO SOLUTION 


Input 
1 -2 1
Output
1.00

Input 
1 -7 10
Output 
2.00 5.00
*/

#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int a, b, c;
    cin >> a >> b >> c;
    int d = b * b - 4 * a * c;
    if(d < 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    else if(d == 0) {
        cout << fixed << setprecision(2) << (double) - b / (2 * a) << endl;
        return 0;
    }
    else {
        double sd = sqrt(d);
        cout << fixed << setprecision(2) << (- b - sd) / (2 * a) << " " << (- b + sd) / (2 * a) << endl;
        return 0;
    }
}
