/*
Да се състави функция за търсене на родител на определен елемент 
в дадено двоично дърво за търсене.
*/
#include <iostream>

using namespace std;

// Define the structure of a node in the binary search tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

// Function to insert a node in the binary search tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to find the parent of a given value
TreeNode* findParent(TreeNode* root, int value) {
    //No parent if tree is empty or value is at root
    if (root == nullptr || root->value == value) {
        return nullptr;
    }

    // Traverse the tree to find the parent
    TreeNode* parent = nullptr;
    TreeNode* current = root;
    while (current != nullptr && current->value != value) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == nullptr) {
        // Value not found in the tree
        return nullptr; 
    }
    return parent;
}

int main() {
    // Creating a simple binary search tree
    TreeNode* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int value = 60;
    TreeNode* parent = findParent(root, value);

    if (parent != nullptr) {
        cout << "The parent of " << value << " is " << parent->value << endl;
    } else {
        cout << value << " does not have a parent in the tree (it might be the root or not present)." << endl;
    }
    return 0;
}
