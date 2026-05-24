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
//
//    return root;  
//}
//
//void inorder(Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    inorder(root->left);
//    cout << root->data << " ";
//    inorder(root->right);
//}
//
//int main() {
//    Node* root = NULL;
//    root = insert(root, 50);
//    root = insert(root, 30);
//    root = insert(root, 70);
//    root = insert(root, 20);
//    root = insert(root, 40);
//    root = insert(root, 60);
//    root = insert(root, 80);
//
//    cout << "sorted order: ";
//    inorder(root);
//    cout << endl;
//
//    return 0;
//}