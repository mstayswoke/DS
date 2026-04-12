#include<iostream>
using namespace std;

class Stack {
public:
    string arr[8];
    int top;

    Stack() { top = -1; }

    void push(string x) {
        if (top == 7) return;
        arr[++top] = x;
    }

    string pop() {
        if (top == -1) return "";
        return arr[top--];
    }
};

int main() {

    Stack mainStack, temp;
    string car;

    mainStack.push("A1");
    mainStack.push("B2");
    mainStack.push("C3");

    cout << "Removing B2...\n";

    while (mainStack.top != -1 && mainStack.arr[mainStack.top] != "B2")
        temp.push(mainStack.pop());

    mainStack.pop(); // remove target

    while (temp.top != -1)
        mainStack.push(temp.pop());

    for (int i = mainStack.top; i >= 0; i--)
        cout << mainStack.arr[i] << " ";

    return 0;
}