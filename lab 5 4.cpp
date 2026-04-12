#include<iostream>
using namespace std;

class Stack {
public:
    string arr[100];
    int top;

    Stack() { top = -1; }

    void push(string s) { arr[++top] = s; }

    string pop() {
        if (top == -1) return "";
        return arr[top--];
    }

    bool isEmpty() { return top == -1; }
};

int main() {

    Stack undoS, redoS;
    string text = "";
    int choice;
    char ch;

    do {
        cout << "\n1.Type\n2.Delete\n3.Undo\n4.Redo\n5.Show\n0.Exit\n";
        cin >> choice;

        switch (choice) {

        case 1:
            cin >> ch;
            undoS.push(text);
            text += ch;
            break;

        case 2:
            if (text.length() > 0) {
                undoS.push(text);
                text = text.substr(0, text.length() - 1);
            }
            break;

        case 3:
            if (!undoS.isEmpty()) {
                redoS.push(text);
                text = undoS.pop();
            }
            break;

        case 4:
            if (!redoS.isEmpty()) {
                undoS.push(text);
                text = redoS.pop();
            }
            break;

        case 5:
            cout << text << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}