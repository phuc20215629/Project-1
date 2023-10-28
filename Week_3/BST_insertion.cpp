/*
Description
Given a BST initialized by NULL. Perform a sequence of operations on a BST including:
insert k: insert a key k into the BST (do not insert if the key k exists)
Input
•Each line contains command under the form: “insert k”
•The input is terminated by a line containing #
Output
•Write the sequence of keys of nodes visited by the pre-order traversal (separated by a SPACE character)
Example
Input
insert 20
insert 10
insert 26
insert 7
insert 15
insert 23
insert 30
insert 3
insert 8
#
Output
20 10 7 3 8 15 26 23 30
*/
#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
    int data;
    Node* leftNode;
    Node* rightNode;
} node;

node* makeNewNode(int x) {
    node* tmp = new node();
    tmp->data = x;
    tmp->leftNode = tmp->rightNode = NULL;
    return tmp;
}

node* insertNode(node* preNode, int data) {
    if(preNode == NULL) {
        preNode = makeNewNode(data);
    }
    else if(data < preNode->data) {
        preNode->leftNode = insertNode(preNode->leftNode, data);
    }
    else if(data > preNode->data) {
        preNode->rightNode = insertNode(preNode->rightNode, data);
    }
    return preNode;
}

void printPreorder(node* root) {
    if(root != NULL) {
        cout << root->data << " ";
        printPreorder(root->leftNode);
        printPreorder(root->rightNode);
    }
}

int main() {
    string order;
    node* root = NULL;
    while(getline(cin, order)) {
        if(order != "#") {
            order = order.erase(0, order.find(" ") + 1);
            int data = stoi(order);
            root = insertNode(root, data);
        }
        else break;
    }
    printPreorder(root);
    return 0;
}