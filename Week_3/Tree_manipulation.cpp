/*
Description
Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
· PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
· InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
· PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
Ví dụ
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
InOrder
Insert 5 11
Insert 4 11
Insert 8 3
PreOrder
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
InOrder
PostOrder
*
Kết quả
11 10 1 3
10 11 5 4 1 3 8
5 11 6 4 9 10 1 8 3 2 7
5 6 9 4 11 1 8 2 7 3 10
*/
#include<bits/stdc++.h>
using namespace std;


struct Node {
    int id;
    vector<int> children;
    Node() : id(0) {}
    Node(int _id) : id(_id) {}
};

unordered_map<int, Node> tree;
vector<vector<int>> res;
int root;

void MakeRoot(int u) {
    if (tree.find(u) == tree.end()) {
        tree[u] = Node(u);
    }
}

bool Insert(int u, int v) {
    //if u existed or v didn't exist return false -> no insertion is made
    if (tree.find(u) != tree.end() || tree.find(v) == tree.end()) {
        return false;
    }

    tree[u] = Node(u);
    tree[v].children.push_back(u);
    
    return true;
}

void PreOrder(int resCount, int u) {
    //there are nothing below the leaf
    if (tree.find(u) == tree.end()) {
        return;
    }

    res[resCount].push_back(u);

    for (int child : tree[u].children) {
        PreOrder(resCount, child);
    }
}

void InOrder(int resCount, int u) {
    if (tree.find(u) == tree.end()) {
        return;
    }
    //if it's not a leaf go down the tree
    if (!tree[u].children.empty()) {
        InOrder(resCount, tree[u].children[0]);
    }
    //after recursive u was visited the second time so also pushing u into inOrderResult or if u is really a leaf
    res[resCount].push_back(u);
    //find other descendants of u to continue the recursion or finding other leaf on the same level
    for (int i = 1; i < tree[u].children.size(); i++) {
        InOrder(resCount, tree[u].children[i]);
    }
}

void PostOrder(int resCount, int u) {
    if (tree.find(u) == tree.end()) {
        return;
    }

    for (int child : tree[u].children) {
        PostOrder(resCount, child);
    }
    //if u has no children -> it comes back after being visited 1 time -> pushing into postOrderResult
    res[resCount].push_back(u);
}

int main() {
    string action;
    int countRes = 0;
    while (cin >> action) {
        if (action == "MakeRoot") {
            cin >> root;
            MakeRoot(root);
        } else if (action == "Insert") {
            int u, v;
            cin >> u >> v;
            bool success = Insert(u, v);
            if (!success) {
                cout << "Insertion failed. Node " << v << " already exists or Node " << u << " does not exist." << endl;
            }
        } else if (action == "PreOrder") {
            res.push_back(vector<int>());
            PreOrder(countRes, root);
            countRes++;
        } else if (action == "InOrder") {
            res.push_back(vector<int>());
            InOrder(countRes, root);
            countRes++;
        } else if (action == "PostOrder") {
            res.push_back(vector<int>());
            PostOrder(countRes, root);
            countRes++;
        } else if (action == "*") {
            break;
        }
    }
    for(auto x : res) {
        for(auto y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}