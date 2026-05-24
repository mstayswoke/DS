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
//// minimum is the leftmost node in the tree
//int findMin(Node* root) {
//    // base case is if no left child means this is the smallest
//    if (root->left == NULL) {
//        return root->data;
//    }
//    // keep going left till the end
//    return findMin(root->left);
//}
//
//// maximum is the rightmost node in the tree
//int findMax(Node* root) {
//    // base case is if no right child means this is the largest
//    if (root->right == NULL) {
//        return root->data;
//    }
//    // keep going right till the end
//    return findMax(root->right);
//}
//
//int main() {
//    Node* root = NULL;
//
//    root = insert(root, 50);
//    root = insert(root, 30);
//    root = insert(root, 70);
//    root = insert(root, 20);
//    root = insert(root, 40);
//    root = insert(root, 60);
//    root = insert(root, 80);
//
//    cout << "minimum value in BST: " << findMin(root) << endl;
//    cout << "maximum value in BST: " << findMax(root) << endl;
//
//    return 0;
//}