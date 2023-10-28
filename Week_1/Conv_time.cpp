/*
Description
Given a time moment which is a string under the format hh:mm:ss (in which hh (0 <= hh <= 23) is the hour, mm (0 <= mm <= 59) is the minute, and ss (0 <= ss <= 59) is the second). Convert this time moment in seconds (result = hh*3600 + mm*60 + ss).
Input
Line 1: contains a string s representing the time moment.  
Output
if s is not under the format hh:mm:ss, then write INCORRECT. Otherwise, write value converted.

Example
Input
13:05:26

Output
47126


Input
13:05:6

Output
INCORRECT 

Input
13:05 26

Output
INCORRECT
*/
//C/C++ 
#include <bits/stdc++.h> 
using namespace std;

int h, m, s;
bool checkFormat(string t) {
    if(t.length() != 8) return false;
    if(t[2] != ':' || t[5] != ':') return false;
    for(int i = 0; i < t.length(); i++) {
        if(i == 2 || i == 5) continue;
        if(!isdigit(t[i])) return false;
    }
    int index = 0;
    h = 10 * (t[index] - 48) + t[++index] - 48;
    if(h < 0 || h > 23) return false;

    index += 2;
    m = 10 * (t[index] - 48) + t[++index] - 48;
    if(m < 0 || m > 59) return false;

    index += 2;
    s = 10 * (t[index] - 48) + t[++index] - 48;
    if(s < 0 || s > 59) return false;
    return true;
}

int main() 
{ 
    string time;
    getline(cin, time);
    if(!checkFormat(time)) {
        cout << "INCORRECT" << endl;
        return 0;
    }
    else {
        cout << 3600 * h + 60 * m + s << endl;
        return 0;
    }
}
