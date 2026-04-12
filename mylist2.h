//#pragma once
//#include "ListADT.h"
//#include "Node.h"
//#include<iostream>
//using namespace std;
//
//template <class T>
//class myList : public ListADT<T> {
//private:
//    Node<T>* head;
//
//public:
//    myList() {
//        head = NULL;
//    }
//
//    void insertAtBeginning(T value) {
//        Node<T>* newNode = new Node<T>(value);
//
//        newNode->next = head;
//        head = newNode;
//    }
//
//    void insertAtEnd(T value) {
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
//    void deleteByValue(T value) {
//        if (head == NULL) return;
//
//        if (head->data == value) {
//            Node<T>* del = head;
//            head = head->next;
//            delete del;
//            return;
//        }
//
//        Node<T>* temp = head;
//
//        while (temp->next != NULL && temp->next->data != value) {
//            temp = temp->next;
//        }
//
//        if (temp->next != NULL) {
//            Node<T>* del = temp->next;
//            temp->next = del->next;
//            delete del;
//        }
//    }
//
//    void display() {
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