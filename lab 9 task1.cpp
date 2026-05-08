#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node* head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtStart(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtPosition(int value, int position)
    {
        if (position == 1)
        {
            insertAtStart(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
        {
            cout << "Invalid Position!" << endl;
            delete newNode;
            return;
        }

        if (temp->next == NULL)
        {
            temp->next = newNode;
            newNode->prev = temp;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteByValue(int value)
    {
        if (head == NULL)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Value not found!" << endl;
            return;
        }

        if (temp == head)
        {
            head = head->next;

            if (head != NULL)
            {
                head->prev = NULL;
            }

            delete temp;
            return;
        }

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        temp->prev->next = temp->next;

        delete temp;
    }

    void displayForward()
    {
        if (head == NULL)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Forward Traversal: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayReverse()
    {
        if (head == NULL)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        cout << "Reverse Traversal: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "After inserting at end:" << endl;
    list.displayForward();

    list.insertAtStart(5);

    cout << "\nAfter inserting at start:" << endl;
    list.displayForward();

    list.insertAtPosition(15, 3);

    cout << "\nAfter inserting 15 at position 3:" << endl;
    list.displayForward();

    cout << endl;
    list.displayReverse();

    list.deleteByValue(5);

    cout << "\nAfter deleting 5:" << endl;
    list.displayForward();

    list.deleteByValue(30);

    cout << "\nAfter deleting 30:" << endl;
    list.displayForward();

    cout << endl;
    list.displayReverse();

    return 0;
}
