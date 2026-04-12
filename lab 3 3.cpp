#include<iostream>
using namespace std;

class CarStack {
private:
    string arr[8];
    int top;

public:
    CarStack() {
        top = -1;
    }

    void push(string car) {
        if (top == 7) {
            cout << "Parking Full\n";
            return;
        }
        arr[++top] = car;
    }

    string pop() {
        if (top == -1) return "";
        return arr[top--];
    }

    void removeCar(string car) {
        string temp[8];
        int t = -1;

        while (top != -1 && arr[top] != car) {
            temp[++t] = pop();
        }

        if (top != -1) pop(); // remove target

        while (t != -1) {
            push(temp[t--]);
        }
    }

    void search(string car) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == car) {
                cout << "Found\n";
                return;
            }
        }
        cout << "Not Found\n";
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int count() {
        return top + 1;
    }
};

int main() {

    CarStack p;

    p.push("A1");
    p.push("B2");
    p.push("C3");

    p.display();

    p.removeCar("B2");
    p.display();

    p.search("A1");

    cout << "Total: " << p.count() << endl;

    return 0;
}