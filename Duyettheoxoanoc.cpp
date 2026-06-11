#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void Add(Node *&root, int u, int v, char c) {
    if (root == NULL) {
        root = new Node(u);

        if (c == 'L')
            root->left = new Node(v);
        else
            root->right = new Node(v);
    }
    else {
        if (root->data == u) {
            if (c == 'L')
                root->left = new Node(v);
            else
                root->right = new Node(v);
        }
        else {
            if (root->left) Add(root->left, u, v, c);
            if (root->right) Add(root->right, u, v, c);
        }
    }
}

void SpiralOrder(Node *root) {
    if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty()) {

        while (!s1.empty()) {
            Node *cur = s1.top();
            s1.pop();

            cout << cur->data << " ";

            if (cur->right) s2.push(cur->right);
            if (cur->left)  s2.push(cur->left);
        }

        while (!s2.empty()) {
            Node *cur = s2.top();
            s2.pop();

            cout << cur->data << " ";

            if (cur->left)  s1.push(cur->left);
            if (cur->right) s1.push(cur->right);
        }
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

        for (int i = 0; i < n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;

            Add(root, u, v, c);
        }

        SpiralOrder(root);
        cout << '\n';
    }

    return 0;
}
