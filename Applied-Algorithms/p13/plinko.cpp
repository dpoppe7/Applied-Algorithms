#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

bool printPath(Node *root, int sum) {
    if (sum == 0)
        return true;

    if (root == nullptr)
        return false;

    bool left = printPath(root->left, sum - root->data);
    bool right = printPath(root->right, sum - root->data);

    if (left || right)
        cout << root->data << " ";

    return left || right;
}

int rootToLeafSum(Node *root) {
    if (root == nullptr)
        return 0;

    int left = rootToLeafSum(root->left);

    int right = rootToLeafSum(root->right);

    return (left > right ? left : right) + root->data;
}

void findMaxSumPath(Node *root) {
    int sum = rootToLeafSum(root);
    cout << "Maximum sum is " << sum << endl;
    cout << "Maximum sum path is: " << printPath(root, sum) << endl;
}

Node *buildtree() {
    int d;
    cin >> d;
    Node *root;
    if (d == -1) {
        return NULL;
    }
    root = new Node(d);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

int main() {
    int size;
    cin >> size;

    if (size == 0) {
        return 0;
    }

    int root;
    for (int i = 1; i <= size; i++) {
        string str;
        getline(cin, str);
        stringstream ss(str);

        auto start = istream_iterator<int>{ ss };
        auto end= istream_iterator<int>{};
        vector<int> input(start, end);

        for (int e : input){
            cout << e << " ";
        }cout << endl;

        for (int e : input){
            root = e;

        }

        input.clear();
    }


    //Node *root = buildtree();
    //print(root);
    //findMaxSumPath(root);

    return 0;
}



