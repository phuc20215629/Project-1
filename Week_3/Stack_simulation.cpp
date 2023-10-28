/*
Description
Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
Input
Each line contains a command (operration) of type 
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)
Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
3
2
5
*/
#include<bits/stdc++.h>
using namespace std;

struct node {
    string data;
    node* pre;
};

struct myStack {
    node* top;
};

void createStack(myStack &st) {
    st.top = NULL;
}

node* makeNewNode(string x) {
    node* tmp = new node();
    if(tmp == NULL) {
        cout << "Error creating new node" << endl;
        return NULL;
    }
    tmp->data = x;
    tmp->pre = NULL;
    return tmp;
}

void pushStack(string x, myStack &st) {
    node* tmp = makeNewNode(x);
    if(tmp != NULL) {
        if(st.top != NULL) {
            tmp->pre = st.top;
            st.top = tmp;
        }
        else {
            st.top = tmp;
        }
    }
}

string popStack(myStack &st) {
    node* tmp = st.top;
    if(st.top != NULL) {
        st.top = tmp->pre;
        string s = tmp->data;
        delete(tmp);
        return s;
    }
    else return "NULL";
}

int main() {
    string s;
    vector<string> res;
    myStack st;
    while(cin >> s) {
        if(s == "#") break;
        if(s == "PUSH") {
            cin >> s;
            pushStack(s, st);
        }
        if(s == "POP") {
            res.push_back(popStack(st));
        }
    }
    for(auto x : res) cout << x << endl;
    return 0;
}


