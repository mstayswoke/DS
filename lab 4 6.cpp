#include<iostream>
using namespace std;

class Package {
public:
    int id;
    string address;
    int start, end;
};

class Queue {
public:
    Package arr[100];
    int front, rear;

    Queue() { front = 0; rear = -1; }

    void enqueue(Package p) {
        arr[++rear] = p;
    }

    void dequeue() {
        front++;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i].id << " " << arr[i].address << " "
                << arr[i].start << "-" << arr[i].end << endl;
        }
    }

    void timeToDeliver(int currentTime) {
        if (arr[front].end < currentTime) {
            cout << "Expired: " << arr[front].id << endl;
            dequeue();
        }
        else {
            cout << "Delivering: " << arr[front].id << endl;
            dequeue();
        }
    }
};

int main() {

    Queue q;

    Package p1 = { 1, "Lahore", 10, 15 };
    Package p2 = { 2, "Karachi", 12, 18 };

    q.enqueue(p1);
    q.enqueue(p2);

    q.display();

    q.timeToDeliver(16);

    q.display();

    return 0;
}