#include<iostream>
using namespace std;

class Stack {
public:
    string arr[100];
    int top;

    Stack() {
        top = -1;
    }

    void push(string s) {
        arr[++top] = s;
    }

    string pop() {
        if (top == -1) return "";
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {

    Stack undoStack, redoStack;
    string text = "";
    int choice;
    char ch;

    do {
        cout << "\n1.Type\n2.Delete\n3.Undo\n4.Redo\n5.Show\n0.Exit\n";
        cin >> choice;

        switch (choice) {

        case 1:
            cin >> ch;
            undoStack.push(text);
            text += ch;
            break;

        case 2:
            if (text.length() > 0) {
                undoStack.push(text);
                text = text.substr(0, text.length() - 1);
            }
            break;

        case 3:
            if (!undoStack.isEmpty()) {
                redoStack.push(text);
                text = undoStack.pop();
            }
            break;

        case 4:
            if (!redoStack.isEmpty()) {
                undoStack.push(text);
                text = redoStack.pop();
            }
            break;

        case 5:
            cout << "Text: " << text << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}