#include<iostream>
using namespace std;

class Queue {
public:
    string arr[100];
    int front, rear;

    Queue() { front = 0; rear = -1; }

    void enqueue(string x) { arr[++rear] = x; }

    string dequeue() { return arr[front++]; }

    string frontVal() { return arr[front]; }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {

    Queue q;

    q.enqueue("doc1");
    q.enqueue("doc2");

    q.display();

    cout << "Printing: " << q.dequeue() << endl;

    q.display();

    return 0;
}