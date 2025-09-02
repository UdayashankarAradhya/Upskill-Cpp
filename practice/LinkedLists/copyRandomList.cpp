#include <iostream>
#include <vector>

using namespace std;

// The Node class definition
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Your correct solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* curr = head;
        while (curr != nullptr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* oldListPtr = head;
        Node* newListHead = head->next;
        Node* newListPtr = newListHead;

        while (oldListPtr != nullptr) {
            oldListPtr->next = oldListPtr->next->next;
            newListPtr->next = (newListPtr->next != nullptr) ? newListPtr->next->next : nullptr;
            oldListPtr = oldListPtr->next;
            newListPtr = newListPtr->next;
        }
        
        return newListHead;
    }
};

// Helper function to print the list and its random pointers
void printList(Node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    Node* curr = head;
    while (curr != nullptr) {
        cout << "[val: " << curr->val << ", random: ";
        if (curr->random != nullptr) {
            cout << curr->random->val;
        } else {
            cout << "null";
        }
        cout << "] -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// Helper function to delete a list to prevent memory leaks
void deleteList(Node* head) {
    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function for local testing
int main() {
    // Manually create a test case: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* node0 = new Node(7);
    Node* node1 = new Node(13);
    Node* node2 = new Node(11);
    Node* node3 = new Node(10);
    Node* node4 = new Node(1);

    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node1->random = node0;
    node2->random = node4;
    node3->random = node2;
    node4->random = node0;

    Node* head = node0;
    
    cout << "--- Testing Copy List with Random Pointer ---" << endl;
    cout << "Original List:" << endl;
    printList(head);

    Solution mySolution;
    Node* copiedHead = mySolution.copyRandomList(head);

    cout << "\nCopied List:" << endl;
    printList(copiedHead);

    cout << "\nOriginal List (after decoupling):" << endl;
    printList(head);

    
    deleteList(copiedHead);

    return 0;
}