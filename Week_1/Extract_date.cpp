/*
Description
Given a date which is a string under the format YYYY-MM-DD (in which YYYY is the year, MM is the month (the month í from 1 to 12), and DD is the date (the date is from 1 to 31)). Extract the year, month and date.
Input
Line 1: contains a string s  
Output
if s is not under the format YYYY-MM-DD, then write INCORRECT. Otherwise, write year, month, and date separated by a SPACE character

Example
Input
2023-10-04
Output
2023 10 4


Input
2023-10-4
Output
INCORRECT 

Input
2023-10 04
Output
INCORRECT
*/

#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    string s;
    getline(cin, s);
    if(s.length() != 10) {
        cout << "INCORRECT" << endl;
        return 0;
    }
    else {
        if(s[4] != '-' || s[7] != '-') {
            cout << "INCORRECT" << endl;
            return 0;
        }
        string year;
        int index = 0;
        for(int i = 0; i < 4; i++) {
            if(isdigit(s[index++])){ 
                year[i] = s[index - 1];
            }
            else {
                cout << "INCORRECT" << endl;
                return 0; 
            }
        }
        index++;
        int month;
        if(isdigit(s[index]) && isdigit(s[index + 1])) {
            month = 10 * (s[index] - 48) + s[++index] - 48;
            if(month < 1 || month > 12) {
                cout << "INCORRECT" << endl;
                return 0; 
            }
        }
        else {
            cout << "INCORRECT" << endl;
            return 0;
        }
        index += 2;
        int day;
        if(isdigit(s[index]) && isdigit(s[index + 1])) {
            day = 10 * (s[index] - 48) + s[++index] - 48;
            if(day < 1 || day > 31) {
                cout << "INCORRECT" << endl;
                return 0; 
            }
        }
        else {
            cout << "INCORRECT" << endl;
            return 0;
        }
        for(int i = 0; i < 4; i++) cout << year[i];
        cout << " " << month << " " << day << endl;
    }
}
