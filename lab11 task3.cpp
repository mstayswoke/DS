//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* left;
//    Node* right;
//};
//
//Node* createNode(int val) {
//    Node* newNode = new Node();
//    newNode->data = val;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//Node* insert(Node* root, int val) {
//    if (root == NULL) {
//        return createNode(val);
//    }
//    if (val < root->data) {
//        root->left = insert(root->left, val);
//    }
//    else if (val > root->data) {
//        root->right = insert(root->right, val);
//    }
//    return root;
//}
//
//// using recursion for going left or right
//bool search(Node* root, int key) {
//    // base case 1 if reached end and value is not found
//    if (root == NULL) {
//        return false;
//    }
//    // base case 2 value is found
//    if (root->data == key) {
//        return true;
//    }
//    // if key is smaller then it should be in left subtree
//    if (key < root->data) {
//        return search(root->left, key);
//    }
//    // otherwise it must be in right subtree
//    else {
//        return search(root->right, key);
//    }
//}
//
//void inorder(Node* root) {
//    if (root == NULL) return;
//    inorder(root->left);
//    cout << root->data << " ";
//    inorder(root->right);
//}
//
//int main() {
//    Node* root = NULL;
//    int searchVal;
//
//    root = insert(root, 50);
//    root = insert(root, 30);
//    root = insert(root, 70);
//    root = insert(root, 20);
//    root = insert(root, 40);
//    root = insert(root, 60);
//    root = insert(root, 80);
//
//    cout << "tree elements: ";
//    inorder(root);
//    cout << endl;
//
//    cout << "enter value to search: ";
//    cin >> searchVal;
//
//    if (search(root, searchVal)) {
//        cout << searchVal << " found in the BST" << endl;
//    }
//    else {
//        cout << searchVal << " not found in the BST" << endl;
//    }
//
//    return 0;
//}