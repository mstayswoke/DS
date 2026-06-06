//#include <iostream>
//using namespace std;
//
//struct TreeNode {
//    int isbn;
//    string title;
//    TreeNode* left;
//    TreeNode* right;
//};
//
//struct ListNode {
//    int isbn;
//    string title;
//    ListNode* next;
//};
//
//TreeNode* createTreeNode(int isbn, string title) {
//    TreeNode* newNode = new TreeNode();
//    newNode->isbn = isbn;
//    newNode->title = title;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//ListNode* createListNode(int isbn, string title) {
//    ListNode* newNode = new ListNode();
//    newNode->isbn = isbn;
//    newNode->title = title;
//    newNode->next = NULL;
//    return newNode;
//}
//
//TreeNode* insert(TreeNode* root, int isbn, string title) {
//    if (root == NULL) {
//        return createTreeNode(isbn, title);
//    }
//    if (isbn < root->isbn) {
//        root->left = insert(root->left, isbn, title);
//    }
//    else if (isbn > root->isbn) {
//        root->right = insert(root->right, isbn, title);
//    }
//    return root;
//}
//
//void inorderBST(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    inorderBST(root->left);
//    cout << root->isbn << " " << root->title << endl;
//    inorderBST(root->right);
//}
//
//void bstToLinkedList(TreeNode* root, ListNode*& head, ListNode*& tail) {
//    if (root == NULL) {
//        return;
//    }
//
//    bstToLinkedList(root->left, head, tail);
//
//    ListNode* newNode = createListNode(root->isbn, root->title);
//
//    if (head == NULL) {
//        head = newNode;
//        tail = newNode;
//    }
//    else {
//        tail->next = newNode;
//        tail = newNode;
//    }
//
//    bstToLinkedList(root->right, head, tail);
//}
//
//void printLinkedList(ListNode* head) {
//    if (head == NULL) {
//        cout << "List is empty" << endl;
//        return;
//    }
//
//    ListNode* temp = head;
//    while (temp != NULL) {
//        cout << temp->isbn << " -> " << temp->title << endl;
//        temp = temp->next;
//    }
//}
//
//int main() {
//    TreeNode* root = NULL;
//    ListNode* head = NULL;
//    ListNode* tail = NULL;
//    int n, isbn;
//    string title;
//
//    cout << "Enter number of books: ";
//    cin >> n;
//
//    for (int i = 0; i < n; i++) {
//        cout << "Enter ISBN and title: ";
//        cin >> isbn;
//        cin.ignore();
//        getline(cin, title);
//    }
//
//    cout << "\nBST Inorder traversal:" << endl;
//    inorderBST(root);
//
//    bstToLinkedList(root, head, tail);
//
//    cout << "\nSorted Linked List catalog:" << endl;
//    printLinkedList(head);
//
//    return 0;
//}