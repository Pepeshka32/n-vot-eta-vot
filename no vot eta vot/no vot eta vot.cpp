#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    LinkedList(const LinkedList& other) {
        if (other.head == nullptr) {
            head = nullptr;
        }
        else {
            head = new Node(other.head->data);
            Node* current = head;
            Node* otherCurrent = other.head->next;
            while (otherCurrent != nullptr) {
                current->next = new Node(otherCurrent->data);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }

    void push_back(int value) {
        if (head == nullptr) {
            head = new Node(value);
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);
        }
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    cout << "Original list: ";
    list1.print();

    LinkedList list2 = list1;

    cout << "Copied list: ";
    list2.print();

    return 0;
}
