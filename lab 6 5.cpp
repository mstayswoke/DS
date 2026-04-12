#include<iostream>
using namespace std;

class StudentNode {
public:
    string name;
    int priority;
    StudentNode* next;

    StudentNode(string n, int p) {
        name = n;
        priority = p;
        next = NULL;
    }
};

class BookQueue {
private:
    StudentNode* head;
    string bookName;

public:
    BookQueue(string b) {
        bookName = b;
        head = NULL;
    }

    void addStudent(string name, int priority) {
        StudentNode* newNode = new StudentNode(name, priority);

        if (head == NULL || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            StudentNode* temp = head;

            while (temp->next != NULL && temp->next->priority <= priority) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void removeStudent(string name) {
        if (head == NULL) return;

        if (head->name == name) {
            StudentNode* del = head;
            head = head->next;
            delete del;
            return;
        }

        StudentNode* temp = head;

        while (temp->next != NULL && temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            StudentNode* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    void updatePriority(string name, int newPriority) {
        removeStudent(name);
        addStudent(name, newPriority);
    }

    void serveNext() {
        if (head == NULL) return;

        cout << "Serving: " << head->name << endl;

        StudentNode* del = head;
        head = head->next;
        delete del;
    }

    void display() {
        cout << "Book: " << bookName << endl;

        StudentNode* temp = head;

        while (temp != NULL) {
            cout << temp->name << "(" << temp->priority << ") -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void countStudents() {
        int count = 0;
        StudentNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Total Students: " << count << endl;
    }
};

int main() {

    BookQueue book1("DSA");
    BookQueue book2("OOP");

    // Book 1
    book1.addStudent("Ali", 2);
    book1.addStudent("Sara", 1);
    book1.addStudent("Ahmed", 3);

    cout << "Initial DSA Queue:\n";
    book1.display();

    cout << "\nAfter Priority Update:\n";
    book1.updatePriority("Ahmed", 1);
    book1.display();

    cout << "\nServing First Student:\n";
    book1.serveNext();
    book1.display();

    book1.countStudents();

    // Book 2
    cout << "\nOOP Queue:\n";
    book2.addStudent("Usman", 2);
    book2.addStudent("Hina", 1);
    book2.display();

    cout << "\nAfter Removing Usman:\n";
    book2.removeStudent("Usman");
    book2.display();

    return 0;
}