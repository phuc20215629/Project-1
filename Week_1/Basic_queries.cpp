/*
Description
Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
find-max: return the maximum element of the given sequence
find-min: return the minimum element of the given sequence 
sum: return the sum of the elements of the given sequence 
find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)

Input
The first block contains the information about the given sequence with the following format:
Line 1: contains a positive integer n (1 <= n <= 10000)
Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
The first block is terminated by a character *
The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***

Output
Write the result of each query in a corresponding line
 
Example
Input
5
1 4 3 2 5
*
find-max
find-min
find-max-segment 1 3
find-max-segment 2 5
sum
***

Output
5
1
4
5
15
*/

#include<bits/stdc++.h>
using namespace std;

int n;

int find_max(vector<int> a, int start = 0, int end = n) {
    int max = -1001;
    for(int i = start; i < end; i++) {
        if(a[i] > max) max = a[i];
    }
    return max;
}

int find_min(vector<int> a, int start = 0, int end = n) {
    int min = 1001;
    for(int i = start; i < end; i++) {
        if(a[i] < min) min = a[i];
    }
    return min;
}

int sum(vector<int> a) {
    int s = 0;
    for(auto x : a) s += x;
    return s;
}

int main() {
    string s;
    vector<int> a;

    getline(cin, s);
    n = stoi(s);
    a.resize(n + 1, 0);

    getline(cin, s);
    int i = -1;
    while(!s.empty() && i++ < n) {
        string tmp = s.substr(0, s.find(" "));
        a[i] = stoi(tmp);
        if(s.find(" ") > s.length()) break;
        else s.erase(0, s.find(" ") + 1);
    }
    getline(cin, s);

    string order1 = "find-max", order2 = "find-min", order3 = "find-max-segment", order4 = "find-max-segment", order5 = "sum";
    vector<int> res;
    while(s != "***") {
        getline(cin, s);
        if(s == order1) res.push_back(find_max(a));
        else if(s == order2) res.push_back(find_min(a));
        else if(s == order5) res.push_back(sum(a));
        else if(s != "***") {
            string tmp = s.substr(0, s.find(" "));
            s.erase(0, s.find(" ") + 1);
            int i = stoi(s.substr(0, s.find(" ")));
            s.erase(0, s.find(" ") + 1);
            int j = stoi(s.substr(0, s.find(" ")));
            if(tmp == order3) res.push_back(find_max(a, i, j));
            else res.push_back(find_min(a, i, j));
        }
    }
    for(auto x : res) cout << x << endl;
    return 0;
}