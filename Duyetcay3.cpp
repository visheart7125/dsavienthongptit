#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void add(Node* &root, int u, int v, char c) {
    if (!root) {
        root = new Node(u);
        if (c == 'L') root->left = new Node(v);
        else root->right = new Node(v);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *cur = q.front(); q.pop();

        if (cur->data == u) {
            if (c == 'L') cur->left = new Node(v);
            else cur->right = new Node(v);
            return;
        }

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

void levelOrder(Node *root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *cur = q.front(); q.pop();

        cout << cur->data << ' ';

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        Node *root = NULL;

        while (n--) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            add(root, u, v, c);
        }

        levelOrder(root);
        cout << '\n';
    }
}
