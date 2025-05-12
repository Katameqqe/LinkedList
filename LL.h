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
    void insert(T value){
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