#include <iostream>
class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = nullptr;
        }

        void insert(int value){
            Node* newNode = new Node(value);
            if (head == nullptr){
                head = newNode;
            } else {
                Node* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void display(){
            Node* temp = head;
            while (temp != nullptr) {
                std::cout << temp->data << " -> ";
                temp = temp->next;
            }
            std::cout << "nullptr" << std::endl;
        }

        ~LinkedList() {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
};

int main(){
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.display();

    return 0;
}