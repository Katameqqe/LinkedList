#ifndef LL_H
#define LL_H

#include <iostream>
#include <string>
template <typename T>
class Node{
    public:
        T data;
        Node<T>* next;

        Node(T data){
            this->data = data;
            this->next = nullptr;
        }
};

template <typename T>
class LinkedList{
private:
    Node<T>* head;
public:
    LinkedList(){
        head = nullptr;
    }
    int size(){
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void insertToN(int n, T value){
        Node<T>* newNode = new Node<T>(value);
        if (n == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* temp = head;
            for (int i = 0; i < n - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                delete newNode;
            }
        }
    }
    void insertToStart(T value){
        insertToN(0,value);
    }
    void insertToEnd(T value){
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr){
            head = newNode;
        } else {
            Node<T>* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void deleteN(int n){
        if (head == nullptr) return;
        Node<T>* temp = head;
        if (n == 0) {
            head = temp->next;
            delete temp;
            return;
        }
        for (int i = 0; i < n - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) return;
        Node<T>* nextNode = temp->next->next;
        delete temp->next;
        temp->next = nextNode;
    }
    void deleteEnd(){
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void deleteList(){
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }
    void display(){
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};
#endif