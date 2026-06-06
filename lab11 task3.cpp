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
//bool isIdentical(Node* root1, Node* root2) {
//    if (root1 == NULL && root2 == NULL) {
//        return true;
//    }
//    if (root1 == NULL || root2 == NULL) {
//        return false;
//    }
//    if (root1->data != root2->data) {
//        return false;
//    }
//    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
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
//    Node* root1 = NULL;
//    Node* root2 = NULL;
//    int n1, n2, val;
//
//    cout << "Enter number of nodes for first BST: ";
//    cin >> n1;
//    cout << "Enter values: ";
//    for (int i = 0; i < n1; i++) {
//        cin >> val;
//        root1 = insert(root1, val);
//    }
//
//    cout << "Enter number of nodes for second BST: ";
//    cin >> n2;
//    cout << "Enter values: ";
//    for (int i = 0; i < n2; i++) {
//        cin >> val;
//        root2 = insert(root2, val);
//    }
//
//    cout << "First BST inorder: ";
//    inorder(root1);
//    cout << endl;
//
//    cout << "Second BST inorder: ";
//    inorder(root2);
//    cout << endl;
//
//    if (isIdentical(root1, root2)) {
//        cout << "BSTs are identical" << endl;
//    }
//    else {
//        cout << "BSTs are not identical" << endl;
//    }
//
//    return 0;
//}