#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int x): val(x), next(nullptr), prev(nullptr) {}
};

Node* insertAtHead(Node* head, int num) {
    Node* temp = new Node(num);
    temp->next = head;
    if (head != nullptr) {
        head->prev = temp;
    }
    return temp;
}

Node* insertAtTail(Node* head, int num) {
    Node* temp = new Node(num);
    if (head == nullptr) {
        return temp;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* deleteByValue(Node* head, int val) {
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->val == val) {
            Node* nodeToDelete = curr;
            
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            } else {
                head = curr->next;
            }

            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }

            curr = curr->next;
            delete nodeToDelete;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    Node* head = nullptr;
    int choice;
    int data;

    do {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Tail" << endl;
        cout << "3. Delete by Value" << endl;
        cout << "4. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at head: ";
                cin >> data;
                head = insertAtHead(head, data);
                cout << data << " inserted." << endl;
                break;
            case 2:
                cout << "Enter data to insert at tail: ";
                cin >> data;
                head = insertAtTail(head, data);
                cout << data << " inserted." << endl;
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> data;
                head = deleteByValue(head, data);
                cout << "All occurrences of " << data << " deleted." << endl;
                break;
            case 4:
                cout << "Current List: ";
                display(head);
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}