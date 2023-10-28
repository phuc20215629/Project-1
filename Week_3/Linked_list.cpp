/*
Description
Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a1, a2, ..., an, sau đó thực hiện các thao tác trên danh sách bao gồm: 
thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách

Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a1, a2, ..., an
Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)
Output
Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho

Example
Input
5
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#

Output
5 4 3 2 10
*/

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

struct douList {
    node *head;
    node *tail;
};

void createDouList(douList &l) {
    l.head = NULL;
    l.tail = NULL;
}

node* makeNewNode(int x) {
    node* tmp = new node();
    if(tmp == NULL) {
        cout << "Error creating new node!" << endl;
        return NULL;
    }
    tmp->data = x;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

bool checkExist(int x, douList &l) {
    node* tmp = l.head;
    if(tmp == NULL) {
        cout << "List empty!" << endl;
        return false;
    }
    else {
        while(tmp != NULL) {
            if(tmp->data == x) return true;
            tmp = tmp->next;
        }
        return false;
    }
}

void insertFirst(int x, douList &l) {
    node* tmp = makeNewNode(x);
    if(l.head == NULL) {
        l.head = l.tail = tmp;
        return;
    }
    tmp->next = l.head;
    l.head->prev = tmp;
    l.head = tmp;
    return;
}

void insertLast(int x, douList &l) {
    node* tmp = makeNewNode(x);
    if(l.head == NULL) {
        l.head = l.tail = tmp;
        return;
    }
    l.tail->next = tmp;
    tmp->prev = l.tail;
    l.tail = tmp;
    return;
}

void insertAfter(int x, int y, douList &l) {
    node* p = l.head;
    while(p != NULL) {
        if(p->data == y) break;
        p = p->next;
    };
    if(p != NULL) {
        node* tmp = makeNewNode(x);
        tmp->prev = p;
        tmp->next = p->next;
        if(p->next != NULL) {
            p->next->prev = tmp;
        }
        else {
            l.tail = tmp;
        }
        p->next = tmp;
        return;
    }
    else {
        cout << "Node not found!" << endl;
        return;
    }
}

void insertBefore(int x, int y, douList &l) {
    node* p = l.head;
    while(p != NULL) {
        if(p->data == y) break;
        p = p->next;
    };
    if(p != NULL) {
        node* tmp = makeNewNode(x);
        tmp->next = p;
        tmp->prev = p->prev;
        if(p->prev != NULL) {
            p->prev->next = tmp;
        }
        else {
            l.head = tmp;
        }
        p->prev = tmp;
        return;
    }
    else {
        cout << "Node not found!" << endl;
        return;
    }
}

void reverse(douList &l) {
    node* p = l.head;
    while (p != NULL) {
        node* tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        if (tmp == NULL) {
            l.tail = l.head;
            l.head = p;
        }
        p = tmp;
    }
}

void delNode(int x, douList &l) {
    node* p = l.head;
    while(p != NULL) {
        if(p->data == x) break;
        p = p->next;
    }
    if(p != NULL) {
        if (p->prev == NULL) {
            // Deleting the first node
            l.head = p->next;
            if (l.head != NULL) {
                l.head->prev = NULL;
            } else {
                l.tail = NULL; // Update tail if the list becomes empty
            }
        } else {
            p->prev->next = p->next;
            if (p->next != NULL) {
                p->next->prev = p->prev;
            } else {
                l.tail = p->prev; // Update tail if deleting the last node
            }
        }
        delete p;
        return;
    }
    else {
        cout << "Node not found!" << endl;
        return;
    }
}

void traverseList(douList &l) {
    if(l.head == NULL) {
        cout << "List empty!" << endl;
        return;
    }
    else {
        node* tmp = l.head;
        while(tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
        return;
    }
}

int main() {
    douList dList;
    createDouList(dList);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        insertLast(x, dList);
    }
    string input;
    while(getline(cin, input)) {
        if(input == "#") break;
        string order = input.substr(0, input.find(" "));
        if(order == "addlast") {
            int x = stoi(input.substr(input.find(" "), input.size()));
            if(!checkExist(x, dList)) insertLast(x, dList);
        }
        if(order == "addfirst") {
            int x = stoi(input.substr(input.find(" "), input.size()));
            if(!checkExist(x, dList)) insertFirst(x, dList);
        }
        if(order == "addafter") {
            string tmp = input.erase(0, input.find(" ") + 1);
            int x = stoi(tmp.substr(0, tmp.find(" ")));
            tmp = tmp.erase(0, tmp.find(" ") + 1);
            int y = stoi(tmp);
            if(checkExist(x, dList) == false && checkExist(y, dList) == true) insertAfter(x, y, dList);
        }
        if(order == "addbefore") {
            string tmp = input.erase(0, input.find(" ") + 1);
            int x = stoi(tmp.substr(0, tmp.find(" ")));
            tmp = tmp.erase(0, tmp.find(" ") + 1);
            int y = stoi(tmp);
            if(checkExist(x, dList) == false && checkExist(y, dList) == true) insertBefore(x, y, dList);
        }
        if(order == "remove") {
            int x = stoi(input.substr(input.find(" "), input.size()));
            while(checkExist(x, dList)) delNode(x, dList);
        }
        if(order == "reverse") {
            reverse(dList);
        }
    }
    traverseList(dList);
    return 0;
}