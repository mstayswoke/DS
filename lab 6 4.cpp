#include<iostream>
using namespace std;

class PatientNode {
public:
    string name;
    PatientNode* next;

    PatientNode(string n) {
        name = n;
        next = NULL;
    }
};

class HospitalQueue {
private:
    PatientNode* head;

public:
    HospitalQueue() {
        head = NULL;
    }

    void addPatient(string name) {
        PatientNode* newNode = new PatientNode(name);

        if (head == NULL) {
            head = newNode;
        }
        else {
            PatientNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void removePatient(string name) {
        if (head == NULL) return;

        if (head->name == name) {
            PatientNode* del = head;
            head = head->next;
            delete del;
            return;
        }

        PatientNode* temp = head;

        while (temp->next != NULL && temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            PatientNode* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    void display() {
        PatientNode* temp = head;

        while (temp != NULL) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void countPatients() {
        int count = 0;
        PatientNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Total Patients: " << count << endl;
    }
};

int main() {

    HospitalQueue h;

    h.addPatient("Ali");
    h.addPatient("Ahmed");
    h.addPatient("Sara");

    cout << "Initial List:\n";
    h.display();

    cout << "\nAfter Removing Ahmed:\n";
    h.removePatient("Ahmed");
    h.display();

    h.countPatients();

    return 0;
}