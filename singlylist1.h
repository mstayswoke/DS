//#pragma once
//#include "Node.h"
//#include<iostream>
//using namespace std;
//
//template <class T>
//class SinglyList {
//private:
//    Node<T>* head;
//
//public:
//    SinglyList() {
//        head = NULL;
//    }
//
//    void CreateNode(T value) {
//        Node<T>* newNode = new Node<T>(value);
//
//        if (head == NULL) {
//            head = newNode;
//        }
//        else {
//            Node<T>* temp = head;
//
//            while (temp->next != NULL) {
//                temp = temp->next;
//            }
//
//            temp->next = newNode;
//        }
//    }
//
//    void Display() {
//        Node<T>* temp = head;
//
//        while (temp != NULL) {
//            cout << temp->data << " -> ";
//            temp = temp->next;
//        }
//
//        cout << "NULL" << endl;
//    }
//};