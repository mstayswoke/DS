#include<iostream>
using namespace std;

template <class T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};

template <class T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int frontIndex, rear, maxSize;

public:
    myQueue(int size) {
        maxSize = size;
        arr = new T[maxSize];
        frontIndex = 0;
        rear = -1;
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue Full\n";
            return;
        }
        arr[++rear] = value;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[frontIndex++];
    }

    T front() const {
        if (frontIndex > rear) return -1;
        return arr[frontIndex];
    }

    bool isEmpty() const {
        return frontIndex > rear;
    }

    bool isFull() const {
        return rear == maxSize - 1;
    }

    void display() const {
        for (int i = frontIndex; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    myQueue<int> q(5);
    int choice, val;

    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Front\n4.Empty\n5.Full\n6.Display\n0.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> val;
            q.enQueue(val);
            break;
        case 2:
            cout << q.deQueue() << endl;
            break;
        case 3:
            cout << q.front() << endl;
            break;
        case 4:
            cout << q.isEmpty() << endl;
            break;
        case 5:
            cout << q.isFull() << endl;
            break;
        case 6:
            q.display();
            break;
        }
    } while (choice != 0);

    return 0;
}