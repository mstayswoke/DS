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
//void postorder(Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    postorder(root->left);         
//    postorder(root->right);      
//    cout << root->data << " ";     
//}
//
//int main() {
//
//    Node* root = createNode(10);
//    root->left = createNode(5);
//    root->right = createNode(15);
//    root->left->left = createNode(3);
//    root->left->right = createNode(7);
//    root->right->left = createNode(12);
//    root->right->right = createNode(18);
//
//    cout << "Inorder traversal: ";
//    inorder(root);
//    cout << endl;
//
//    cout << "Preorder traversal: ";
//    preorder(root);
//    cout << endl;
//
//    cout << "Postorder traversal: ";
//    postorder(root);
//    cout << endl;
//
//    return 0;
//}