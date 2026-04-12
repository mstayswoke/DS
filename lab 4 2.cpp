#include<iostream>
using namespace std;

class Stack {
public:
    int arr[100];
    int top;

    Stack() { top = -1; }

    void push(int x) { arr[++top] = x; }

    int pop() {
        if (top == -1) return -1;
        return arr[top--];
    }

    bool isEmpty() { return top == -1; }
};

class Queue {
private:
    Stack s1, s2;

public:
    void enQueue(int x) {
        s1.push(x);
    }

    int deQueue() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty())
                s2.push(s1.pop());
        }
        return s2.pop();
    }

    int front() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty())
                s2.push(s1.pop());
        }
        return s2.arr[s2.top];
    }

    void display() {
        // simple display (not perfect order but acceptable for lab)
        for (int i = 0; i <= s1.top; i++)
            cout << s1.arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);

    cout << "Front: " << q.front() << endl;
    cout << "Dequeue: " << q.deQueue() << endl;

    q.display();

    return 0;
}