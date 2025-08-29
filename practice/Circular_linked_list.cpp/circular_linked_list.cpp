#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->val << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to " << head->val << ")" << endl;
}

Node* insertAtHead(Node* head, int x) {
    Node* temp = new Node(x);
    if (head == nullptr) {
        temp->next = temp;
        return temp;
    }
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = temp;
    temp->next = head;
    return temp;
}

Node* insertAtEnd(Node* head, int x) {
    Node* temp = new Node(x);
    if (head == nullptr) {
        temp->next = temp;
        return temp;
    }
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = temp;
    temp->next = head;
    return head;
}

int main() {
    Node* head = nullptr;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    cout << "After inserting at end: ";
    display(head);

    head = insertAtHead(head, 5);
    cout << "After inserting at head: ";
    display(head);

    return 0;
}