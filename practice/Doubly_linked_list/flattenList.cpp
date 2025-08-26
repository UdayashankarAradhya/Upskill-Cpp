#include <iostream>

using namespace std;

// The Node class definition for a multilevel doubly linked list
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int v) : val(v), prev(nullptr), next(nullptr), child(nullptr) {}
};

// Your correct iterative solution
class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* originalNext = curr->next;

                Node* childTail = curr->child;
                while (childTail->next != nullptr) {
                    childTail = childTail->next;
                }

                curr->next = curr->child;
                curr->child->prev = curr;

                childTail->next = originalNext;
                if (originalNext != nullptr) {
                    originalNext->prev = childTail;
                }
                
                curr->child = nullptr;
            }
            
            curr = curr->next;
        }
        return head;
    }
};

// Helper function to print the flattened list
void printList(Node* head) {
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

// Main function for local testing
int main() {
    // Manually creating the complex multilevel list from the LeetCode example
    // Level 1: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    // Level 2:         |
    //                  7 <-> 8 <-> 9 <-> 10
    // Level 3:               |
    //                        11 <-> 12

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);
    Node* node11 = new Node(11);
    Node* node12 = new Node(12);

    // Link level 1
    node1->next = node2; node2->prev = node1;
    node2->next = node3; node3->prev = node2;
    node3->next = node4; node4->prev = node3;
    node4->next = node5; node5->prev = node4;
    node5->next = node6; node6->prev = node5;

    // Link level 2
    node7->next = node8; node8->prev = node7;
    node8->next = node9; node9->prev = node8;
    node9->next = node10; node10->prev = node9;

    // Link level 3
    node11->next = node12; node12->prev = node11;

    // Set child pointers
    node3->child = node7;
    node8->child = node11;

    Node* head = node1;

    cout << "--- Testing Flatten Multilevel DLL ---" << endl;
    
    Solution mySolution;
    head = mySolution.flatten(head);
    
    cout << "Flattened List: ";
    printList(head);

    return 0;
}