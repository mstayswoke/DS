#include<iostream>
using namespace std;

template <class T>
class myStack {
private:
    T* arr;
    T* minArr;
    int topIndex, maxSize;

public:
    myStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        minArr = new T[maxSize];
        topIndex = -1;
    }

    void push(T value) {
        if (topIndex == maxSize - 1) return;

        arr[++topIndex] = value;

        if (topIndex == 0 || value < minArr[topIndex - 1])
            minArr[topIndex] = value;
        else
            minArr[topIndex] = minArr[topIndex - 1];
    }

    T pop() {
        if (topIndex == -1) return -1;
        return arr[topIndex--];
    }

    T getMin() {
        if (topIndex == -1) return -1;
        return minArr[topIndex];
    }

    void display() {
        for (int i = topIndex; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {

    myStack<int> s(5);
    int choice, val;

    do {
        cout << "\n1.Push\n2.Pop\n3.Display\n4.Min\n0.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: cin >> val; s.push(val); break;
        case 2: cout << s.pop() << endl; break;
        case 3: s.display(); break;
        case 4: cout << s.getMin() << endl; break;
        }
    } while (choice != 0);

    return 0;
}