/*
Description
Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text

Input
The Text

Output
Write the number Q of words

Example
Input
Hanoi University Of Science and Technology
School of Information and Communication Technology


Output
12
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int cnt = 0;
    while(!feof(stdin)) {
        cin >> s;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}