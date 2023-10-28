/*
Description
Perform a sequence of operations over a queue, each element is an integer:
PUSH v: push a value v into the queue
POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
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
1
2
3

Input
PUSH 1
POP
POP
PUSH 4
POP
#
Output
1
NULL
4
*/
#include<bits/stdc++.h>
using namespace std;

struct node {
    string data;
    node* next;
};

struct myQueue {
    node* head;
    node* tail;
};

void createQueue(myQueue &q) {
    q.head = NULL;
    q.tail = NULL;
}

node* makeNewNode(string x) {
    node* tmp = new node();
    if(tmp == NULL) {
        cout << "Error creating node!" << endl;
        return NULL;
    }
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

void enqueue(string x, myQueue &q) {
    node* tmp = makeNewNode(x);
    if(q.tail != NULL) {
        q.tail->next = tmp;
        q.tail = tmp;
    }
    else {
        q.head = q.tail = tmp;
    }
}

string dequeue(myQueue &q) {
    node* tmp = q.head;
    if(q.head != NULL) {
        q.head = q.head->next;
        if(q.head == NULL) q.tail = NULL;
        string s = tmp->data;
        delete(tmp);
        return s;
    }
    else return "NULL";
}

int main() {
    string s;
    vector<string> res;
    myQueue q;
    createQueue(q);

    while(cin >> s) {
        if(s == "#") break;
        if(s == "PUSH") {
            cin >> s;
            enqueue(s, q);;
        }
        if(s == "POP") {
            res.push_back(dequeue(q));
        }
    }
    for(auto x : res) cout << x << endl;
    return 0;
}