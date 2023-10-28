/*
Description
Given a string containing only characters (, ), [, ] {, }. Write a program that checks whether the string is correct in expression.
Example
 ([]{()}()[]): correct
 ([]{()]()[]): incorrect
Input
One line contains the string (the length of the string is less than or equal to $10^6$)One line contains the string (the length of the string is less than or equal to 10
6
)
Output
Write 1 if the sequence is correct, and write 0, otherwise
Example
Input
(()[][]{}){}{}[][]({[]()})
Output
1
*/
#include <bits/stdc++.h>
using namespace std;

int par(string str)
{
    int size = str.length();
    stack<char> S;
    char x, y;
    for (int i = 0; i < size; i++)
    {
        x = str[i];
        if (x == '(' || x == '[' || x == '{')
        {
            S.push(x);
        }
        else
        {
            if(S.empty()) {
                return 0;
            }
            if (x == ')')
            {
                if (S.top() == '(')
                {
                    S.pop();
                }
                else
                    return 0;
            }
            else if (x == ']')
            {
                if (S.top() == '[')
                {
                    S.pop();
                }
                else
                    return 0;
            }
            else if (x == '}')
            {
                if (S.top() == '{')
                {
                    S.pop();
                }
                else
                    return 0;
            }
        }
    }
    if (!S.empty())
    {
        return 0;
    }
    else
        return 1;
}

int main()
{
    string str;
    cin >> str;
    cout << par(str) << endl;
    return 0;
}