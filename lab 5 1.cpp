#include<iostream>
using namespace std;

template <class T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};

template <class T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int maxSize;
    int topIndex;

public:
    myStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        topIndex = -1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack Full\n";
            return;
        }
        arr[++topIndex] = value;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[topIndex--];
    }

    T top() const {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == maxSize - 1;
    }

    void display() const {
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    myStack<int> s(5);
    int choice, val;

    do {
        cout << "\n1.Push\n2.Pop\n3.Top\n4.Empty\n5.Full\n6.Display\n0.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: cin >> val; s.push(val); break;
        case 2: cout << s.pop() << endl; break;
        case 3: cout << s.top() << endl; break;
        case 4: cout << s.isEmpty() << endl; break;
        case 5: cout << s.isFull() << endl; break;
        case 6: s.display(); break;
        }
    } while (choice != 0);

    return 0;
}