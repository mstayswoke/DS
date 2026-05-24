//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* next;
//};
//
//Node* insertAtBeginning(Node* head, int val) {
//    Node* newNode = new Node();
//    newNode->data = val;
//    newNode->next = head;
//    return newNode;
//}
//
//Node* insertAtEnd(Node* head, int val) {
//    if (head == NULL) {
//        Node* newNode = new Node();
//        newNode->data = val;
//        newNode->next = NULL;
//        return newNode;
//    }
//    head->next = insertAtEnd(head->next, val);
//    return head;
//}
//
//Node* insertAtPos(Node* head, int val, int pos) {
//    if (pos == 1 || head == NULL) {
//        Node* newNode = new Node();
//        newNode->data = val;
//        newNode->next = head;
//        return newNode;
//    }
//    head->next = insertAtPos(head->next, val, pos - 1);
//    return head;
//}
//
//Node* deleteByValue(Node* head, int val) {
//    if (head == NULL) {
//        return NULL;
//    }
//    if (head->data == val) {
//        Node* temp = head->next;
//        delete head;
//        return temp;
//    }
//    head->next = deleteByValue(head->next, val);
//    return head;
//}
//
//Node* deleteAtPos(Node* head, int pos) {
//    if (head == NULL) {
//        return NULL;
//    }
//    if (pos == 1) {
//        Node* temp = head->next;
//        delete head;
//        return temp;
//    }
//    head->next = deleteAtPos(head->next, pos - 1);
//    return head;
//}
//
//int search(Node* head, int val, int pos) {
//    if (head == NULL) {
//        return -1;
//    }
//    if (head->data == val) {
//        return pos;
//    }
//    return search(head->next, val, pos + 1);
//}
//
//void printList(Node* head) {
//    if (head == NULL) {
//        return;
//    }
//    cout << head->data << " ";
//    printList(head->next);
//}
//
//int main() {
//    Node* head = NULL;
//
//    head = insertAtEnd(head, 10);
//    head = insertAtEnd(head, 20);
//    head = insertAtEnd(head, 30);
//    cout << "After inserting at end: ";
//    printList(head);
//    cout << endl;
//
//    head = insertAtBeginning(head, 5);
//    cout << "After inserting at beginning: ";
//    printList(head);
//    cout << endl;
//
//    head = insertAtPos(head, 15, 3);
//    cout << "After inserting at position 3: ";
//    printList(head);
//    cout << endl;
//
//    head = deleteByValue(head, 20);
//    cout << "After deleting 20: ";
//    printList(head);
//    cout << endl;
//
//    head = deleteAtPos(head, 2);
//    cout << "After deleting position 2: ";
//    printList(head);
//    cout << endl;
//
//    int pos = search(head, 15, 1);
//    if (pos != -1) {
//        cout << "15 found at position " << pos << endl;
//    }
//    else {
//        cout << "15 not found" << endl;
//    }
//
//    pos = search(head, 100, 1);
//    if (pos != -1) {
//        cout << "100 found at position " << pos << endl;
//    }
//    else {
//        cout << "100 not found" << endl;
//    }
//
//    return 0;
//}