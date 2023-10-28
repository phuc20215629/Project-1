/*
Description
There are two jugs, a-litres jug and b-litres jug (a, b are positive integers). There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.
Input
   Line 1: contains positive integers a,   b,  c  (1 <= a, b, c <= 900)
Output
  write the number of steps or write -1 (if no solution found)
Example

Input
6  8  4
Output
4
*/
#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c) {
    queue<pair<int, int>> q;
    unordered_set<int> visited; // keeping track of the operation to avoid infinite loop
    q.push({0, 0});

    int steps = 0;
    // BFS
    while (!q.empty()) {
        int size = q.size();
        // inner loop will try all the possible operation at the current level that leads to a non-visited status before and check for the answer
        while (size--) {    
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == c || y == c) {
                return steps;
            }

            // Fill jug a
            // the use of * 1000 is to make unique status of an operation
            if (!visited.count(a * 1000 + y)) {
                visited.insert(a * 1000 + y);
                q.push({a, y});
            }

            // Fill jug b
            if (!visited.count(x * 1000 + b)) {
                visited.insert(x * 1000 + b);
                q.push({x, b});
            }

            // Empty jug a
            if (!visited.count(0 * 1000 + y)) {
                visited.insert(0 * 1000 + y);
                q.push({0, y});
            }

            // Empty jug b
            if (!visited.count(x * 1000 + 0)) {
                visited.insert(x * 1000 + 0);
                q.push({x, 0});
            }

            // Pour from jug a to jug b
            int pourAmount = min(x, b - y); // b - y = the amount of water b can take -> x <= b - y
            if (!visited.count((x - pourAmount) * 1000 + (y + pourAmount))) {
                visited.insert((x - pourAmount) * 1000 + (y + pourAmount));
                q.push({x - pourAmount, y + pourAmount});
            }

            // Pour from jug b to jug a
            pourAmount = min(a - x, y); // a - x =  the amount of water a can take -> y <= a - x
            if (!visited.count((x + pourAmount) * 1000 + (y - pourAmount))) {
                visited.insert((x + pourAmount) * 1000 + (y - pourAmount));
                q.push({x + pourAmount, y - pourAmount});
            }
        }
        steps++;
    }

    return -1; // No solution found
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int steps = solve(a, b, c);

    cout << steps << endl;

    return 0;
}