/*
Description
Given a TEXT, write a program that converts the TEXT to upper-case. 

Input
The TEXT

Output
The TEXT in which characters are converted into upper-case

Example 
Input 
Hello John,
How are you?

Bye,

Output 
HELLO JOHN,
HOW ARE YOU?

BYE, 
*/

//C/C++ 
// #include <bits/stdc++.h> 
// using namespace std;

// int main() 
// { 
//     string s;
//     vector<string> paragraph;
//     while(getline(cin, s)) {
//         paragraph.push_back(s);
//     }
//     for(auto &p : paragraph) {
//         for(auto &c : p) {
//             c = toupper(c);
//         }
//     }
//     for(auto p : paragraph) cout << p << endl;
//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;

int main() {
    int q = 0;
    string word;

    while (!feof(stdin))
    {
        cin >> word;
        q++;
    }
    
    cout << q;

    return 0;
}
