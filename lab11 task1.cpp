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
//void inorder(Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    inorder(root->left);
//    cout << root->data << " ";
//    inorder(root->right);
//}
//
//void preorder(Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    cout << root->data << " ";
//    preorder(root->left);
//    preorder(root->right);
//}
//
//void postorder(Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    postorder(root->left);
//    postorder(root->right);
//    cout << root->data << " ";
//}
//
//bool search(Node* root, int key) {
//    if (root == NULL) {
//        return false;
//    }
//    if (root->data == key) {
//        return true;
//    }
//    if (key < root->data) {
//        return search(root->left, key);
//    }
//    else {
//        return search(root->right, key);
//    }
//}
//
//int main() {
//    Node* root = NULL;
//    int n, val, searchKey;
//
//    cout << "Enter number of values to insert: ";
//    cin >> n;
//
//    cout << "Enter values: ";
//    for (int i = 0; i < n; i++) {
//        cin >> val;
//        root = insert(root, val);
//    }
//
//    cout << "Inorder: ";
//    inorder(root);
//    cout << endl;
//
//    cout << "Preorder: ";
//    preorder(root);
//    cout << endl;
//
//    cout << "Postorder: ";
//    postorder(root);
//    cout << endl;
//
//    cout << "Enter value to search: ";
//    cin >> searchKey;
//
//    if (search(root, searchKey)) {
//        cout << "Key found in BST" << endl;
//    }
//    else {
//        cout << "Key not found in BST" << endl;
//    }
//
//    return 0;
//}