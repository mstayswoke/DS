#include<iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    void enQueue(int x) { arr[++rear] = x; }

    int deQueue() { return arr[front++]; }

    int size() { return rear - front + 1; }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class Stack {
public:
    int arr[100];
    int top;
    Stack() { top = -1; }

    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
};

int main() {

    Queue q;
    int n, k, x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enQueue(x);
    }

    cin >> k;

    if (k > q.size()) k = q.size();
    if (k <= 1) {
        q.display();
        return 0;
    }

    Stack s;

    for (int i = 0; i < k; i++)
        s.push(q.deQueue());

    while (s.top != -1)
        q.enQueue(s.pop());

    int remaining = q.size() - k;

    for (int i = 0; i < remaining; i++)
        q.enQueue(q.deQueue());

    q.display();

    return 0;
}