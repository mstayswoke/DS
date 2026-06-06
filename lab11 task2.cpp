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
//Node* findMin(Node* root) {
//    if (root->left == NULL) {
//        return root;
//    }
//    return findMin(root->left);
//}
//
//Node* deleteNode(Node* root, int key) {
//    if (root == NULL) {
//        return NULL;
//    }
//
//    if (key < root->data) {
//        root->left = deleteNode(root->left, key);
//    }
//    else if (key > root->data) {
//        root->right = deleteNode(root->right, key);
//    }
//    else {
//        if (root->left == NULL && root->right == NULL) {
//            delete root;
//            return NULL;
//        }
//
//        if (root->left == NULL) {
//            Node* temp = root->right;
//            delete root;
//            return temp;
//        }
//        if (root->right == NULL) {
//            Node* temp = root->left;
//            delete root;
//            return temp;
//        }
//
//        Node* temp = findMin(root->right);
//        root->data = temp->data;
//        root->right = deleteNode(root->right, temp->data);
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
//int main() {
//    Node* root = NULL;
//    int n, val, delKey;
//
//    cout << "Enter number of values: ";
//    cin >> n;
//
//    cout << "Enter values: ";
//    for (int i = 0; i < n; i++) {
//        cin >> val;
//        root = insert(root, val);
//    }
//
//    cout << "Inorder before deletion: ";
//    inorder(root);
//    cout << endl;
//
//    cout << "Enter value to delete: ";
//    cin >> delKey;
//
//    root = deleteNode(root, delKey);
//
//    cout << "Inorder after deletion: ";
//    inorder(root);
//    cout << endl;
//
//    return 0;
//}