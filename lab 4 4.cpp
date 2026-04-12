#include<iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear;

    Queue() { front = 0; rear = -1; }

    void enqueue(int x) { arr[++rear] = x; }

    int dequeue() { return arr[front++]; }

    int frontVal() { return arr[front]; }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {

    Queue q;

    q.enqueue(1234);
    q.enqueue(5678);

    q.display();

    cout << "Next: " << q.frontVal() << endl;

    q.dequeue();

    q.display();

    return 0;
}