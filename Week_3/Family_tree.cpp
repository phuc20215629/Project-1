/*
Description
Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>

Note that: the total number of people in the family is less than or equal to 10
4
Input
Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
Output
Each line is the result of a corresponding query.
Example
Input
Peter Newman
Michael Thomas
John David
Paul Mark
Stephan Mark
Pierre Thomas
Mark Newman
Bill David
David Newman
Thomas Mark
***
descendants Newman
descendants Mark
descendants David
generation Mark
***
Output
10
5
2
2
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> familyTree;
unordered_map<string, int> generationCount;

void buildFamilyTree() {
    string child, parent;
    while (cin >> child) {
        if (child == "***")
            break;
        cin >> parent;
        familyTree[parent].push_back(child);
    }
}

int countDescendants(const string& name) {
    if (familyTree.find(name) == familyTree.end())
        return 0;

    int count = 0;
    const vector<string>& children = familyTree[name];
    for (const string& child : children) {
        count += 1 + countDescendants(child);
    }
    return count;
}

int countGenerations(const string& name) {
    if (generationCount.find(name) != generationCount.end())
        return generationCount[name];

    int maxGeneration = 0;
    if (familyTree.find(name) != familyTree.end()) {
        const vector<string>& children = familyTree[name];
        for (const string& child : children) {
            int childGeneration = countGenerations(child);
            maxGeneration = max(maxGeneration, childGeneration + 1);
        }
    }
    generationCount[name] = maxGeneration;
    return maxGeneration;
}

int main() {
    buildFamilyTree();
    vector<int> count;
    string cmd, param;
    while (cin >> cmd) {
        if (cmd == "***")
            break;
        cin >> param;
        if (cmd == "descendants") {
            count.push_back(countDescendants(param));
        } else if (cmd == "generation") {
            count.push_back(countGenerations(param));
        }
    }
    for(auto x : count) cout << x << endl;
    return 0;
}