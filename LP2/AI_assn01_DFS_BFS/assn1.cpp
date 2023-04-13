// Atharv Kulkarni
// Assn01


// Problem Statement
// Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected
// graph and develop a recursive algorithm for searching all the vertices of a graph or tree data
// structure.



// inorder = left - root - right
// preorder = root - left - right
// postorder = left - right - root



#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

public:
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    friend class BinaryTree;
};

class BinaryTree {
public:
    Node *root;

    BinaryTree() {
        root = nullptr;
    }

    vector<int> path;

    void addNode(int data) {
        Node *newNode = new Node(data);

        if(root == nullptr) {
            root = newNode;
        }
        else {
            Node *ptr = root;
            Node *parent;

            while(true) {
                parent = ptr;

                if(data < ptr->data) {
                    ptr = ptr->left;
                    if(ptr == nullptr) {
                        parent->left = newNode;
                        return;
                    }
                }
                else {
                    ptr = ptr->right;
                    if(ptr == nullptr) {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    void dfs(Node *ptr) {       //preorder
        if(ptr != nullptr) {
            cout << ptr->data << " ";
            dfs(ptr->left);
            dfs(ptr->right);
        }
    }

    void bfs(Node* root) {
        if(root == nullptr) 
            return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                cout << node->data << " ";
                if (node->left != nullptr) 
                    q.push(node->left);
                if (node->right != nullptr) 
                    q.push(node->right);
            }
            cout<<endl;
        }
    }


    void input(){
        int n;
        cout<<"Enter total number no of nodes in binary tree: ";
        cin>>n;
        for(int i=0; i<n; i++){
            cout<<"Enter data of node: ";
            int temp;
            cin>>temp;
            addNode(temp);
        }
    }
};

int main() {
    BinaryTree tree;

    tree.input();

    cout<<"DFS (Recursive preorder): "<<endl;
    tree.dfs(tree.root);        //preorder
    cout<<"\nBFS (Non-Recursive): "<<endl;
    tree.bfs(tree.root);


    return 0;
}
