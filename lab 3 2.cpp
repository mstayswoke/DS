#include<iostream>
using namespace std;

template <class T>
class myStack {
private:
    T* arr;
    T* minArr;
    int maxSize;
    int currentSize;

public:
    myStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        minArr = new T[maxSize];
        currentSize = 0;
    }

    void push(T value) {
        if (currentSize == maxSize) return;

        arr[currentSize] = value;

        if (currentSize == 0 || value < minArr[currentSize - 1])
            minArr[currentSize] = value;
        else
            minArr[currentSize] = minArr[currentSize - 1];

        currentSize++;
    }

    T pop() {
        if (currentSize == 0) return -1;
        return arr[--currentSize];
    }

    T getMin() const {
        if (currentSize == 0) return -1;
        return minArr[currentSize - 1];
    }

    void display() {
        for (int i = currentSize - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    myStack<int> s(5);

    s.push(5);
    s.push(3);
    s.push(7);

    s.display();
    cout << "Min: " << s.getMin() << endl;

    s.pop();
    cout << "Min after pop: " << s.getMin() << endl;

    return 0;
}