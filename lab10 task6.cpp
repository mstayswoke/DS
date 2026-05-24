//#include <iostream>
//using namespace std;
//
//struct DNode {
//    int data;
//    DNode* next;
//    DNode* prev;
//};
//
//DNode* insertAtBeginning(DNode* head, DNode*& tail, int val) {
//    DNode* newNode = new DNode();
//    newNode->data = val;
//    newNode->next = head;
//    newNode->prev = NULL;
//
//    if (head == NULL) {
//        tail = newNode;
//        return newNode;
//    }
//
//    head->prev = newNode;
//    return newNode;
//}
//
//DNode* insertAtEnd(DNode* head, DNode*& tail, int val) {
//    if (head == NULL) {
//        DNode* newNode = new DNode();
//        newNode->data = val;
//        newNode->next = NULL;
//        newNode->prev = NULL;
//        tail = newNode;
//        return newNode;
//    }
//    head->next = insertAtEnd(head->next, tail, val);
//    head->next->prev = head;
//    return head;
//}
//
//DNode* insertAtPos(DNode* head, DNode*& tail, int val, int pos) {
//    if (pos == 1 || head == NULL) {
//        DNode* newNode = new DNode();
//        newNode->data = val;
//        newNode->next = head;
//        newNode->prev = NULL;
//
//        if (head != NULL) {
//            head->prev = newNode;
//        }
//        else {
//            tail = newNode;
//        }
//        return newNode;
//    }
//    head->next = insertAtPos(head->next, tail, val, pos - 1);
//    head->next->prev = head;
//    return head;
//}
//
//DNode* deleteByValue(DNode* head, DNode*& tail, int val) {
//    if (head == NULL) {
//        return NULL;
//    }
//    if (head->data == val) {
//        DNode* temp = head->next;
//        if (temp != NULL) {
//            temp->prev = head->prev;
//        }
//        else {
//            tail = head->prev;
//        }
//        delete head;
//        return temp;
//    }
//    head->next = deleteByValue(head->next, tail, val);
//    if (head->next != NULL) {
//        head->next->prev = head;
//    }
//    return head;
//}
//
//DNode* deleteAtPos(DNode* head, DNode*& tail, int pos) {
//    if (head == NULL) {
//        return NULL;
//    }
//    if (pos == 1) {
//        DNode* temp = head->next;
//        if (temp != NULL) {
//            temp->prev = head->prev;
//        }
//        else {
//            tail = head->prev;
//        }
//        delete head;
//        return temp;
//    }
//    head->next = deleteAtPos(head->next, tail, pos - 1);
//    if (head->next != NULL) {
//        head->next->prev = head;
//    }
//    return head;
//}
//
//int search(DNode* head, int val, int pos) {
//    if (head == NULL) {
//        return -1;
//    }
//    if (head->data == val) {
//        return pos;
//    }
//    return search(head->next, val, pos + 1);
//}
//
//void printForward(DNode* head) {
//    if (head == NULL) {
//        return;
//    }
//    cout << head->data << " ";
//    printForward(head->next);
//}
//
//void printReverse(DNode* tail) {
//    if (tail == NULL) {
//        return;
//    }
//    cout << tail->data << " ";
//    printReverse(tail->prev);
//}
//
//bool checkPalindrome(DNode* front, DNode*& back) {
//    if (front == NULL) {
//        return true;
//    }
//    if (!checkPalindrome(front->next, back)) {
//        return false;
//    }
//    if (front->data != back->data) {
//        return false;
//    }
//    back = back->next;
//    return true;
//}
//
//bool isPalindrome(DNode* head) {
//    DNode* back = head;
//    return checkPalindrome(head, back);
//}
//
//int main() {
//    DNode* head = NULL;
//    DNode* tail = NULL;
//
//    head = insertAtEnd(head, tail, 1);
//    head = insertAtEnd(head, tail, 2);
//    head = insertAtEnd(head, tail, 3);
//    head = insertAtEnd(head, tail, 2);
//    head = insertAtEnd(head, tail, 1);
//
//    cout << "Forward: ";
//    printForward(head);
//    cout << endl;
//
//    cout << "Reverse: ";
//    printReverse(tail);
//    cout << endl;
//
//    if (isPalindrome(head)) {
//        cout << "List is palindrome" << endl;
//    }
//    else {
//        cout << "List is not palindrome" << endl;
//    }
//
//    head = insertAtBeginning(head, tail, 0);
//    cout << "After inserting 0 at beginning:" << endl;
//    cout << "Forward: ";
//    printForward(head);
//    cout << endl;
//
//    head = insertAtPos(head, tail, 99, 3);
//    cout << "After inserting 99 at position 3:" << endl;
//    cout << "Forward: ";
//    printForward(head);
//    cout << endl;
//
//    head = deleteByValue(head, tail, 99);
//    cout << "After deleting 99:" << endl;
//    cout << "Forward: ";
//    printForward(head);
//    cout << endl;
//
//    head = deleteAtPos(head, tail, 2);
//    cout << "After deleting position 2:" << endl;
//    cout << "Forward: ";
//    printForward(head);
//    cout << endl;
//
//    int pos = search(head, 3, 1);
//    if (pos != -1) {
//        cout << "3 found at position " << pos << endl;
//    }
//    else {
//        cout << "3 not found" << endl;
//    }
//
//    return 0;
//}