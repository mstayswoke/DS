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
//// function to find the smallest node in a subtree as it is used when it has tpo delete a node that has two children
//Node* findMinNode(Node* root) {
//    if (root->left == NULL) {
//        return root;
//    }
//    return findMinNode(root->left);
//}
//
//// delete function
//Node* deleteNode(Node* root, int val) {
//    // base case check if it is empty tree
//    if (root == NULL) {
//        return NULL;
//    }
//
//    // search for the node to delete
//    if (val < root->data) {
//        root->left = deleteNode(root->left, val);
//    }
//    else if (val > root->data) {
//        root->right = deleteNode(root->right, val);
//    }
//    else {
//        // if found the node then now handle the 3 cases
//
//        // case 1: if no children then just delete it
//        if (root->left == NULL && root->right == NULL) {
//            delete root;
//            return NULL;
//        }
//
//        // case 2: if one child then replacing with that child
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
//        // case 3: if two children then have to find inorder successor which is smallest node in right subtree
//        Node* successor = findMinNode(root->right);
//        root->data = successor->data;
//        // deleting duplicate
//        root->right = deleteNode(root->right, successor->data);   
//    }
//
//    return root;
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
//    int delVal;
//
//    root = insert(root, 50);
//    root = insert(root, 30);
//    root = insert(root, 70);
//    root = insert(root, 20);
//    root = insert(root, 40);
//    root = insert(root, 60);
//    root = insert(root, 80);
//
//    cout << "original tree: ";
//    inorder(root);
//    cout << endl;
//
//    cout << "enter value to delete: ";
//    cin >> delVal;
//
//    root = deleteNode(root, delVal);
//
//    cout << "tree after deletion: ";
//    inorder(root);
//    cout << endl;
//
//    return 0;
//}