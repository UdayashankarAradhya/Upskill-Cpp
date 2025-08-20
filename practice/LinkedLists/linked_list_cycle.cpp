#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // Move slow pointer by one
            fast = fast->next->next;   // Move fast pointer by two

            // If the pointers meet, there is a cycle
            if (fast == slow) {
                return true;
            }
        }

        
        return false;
    }
};


int main() {
    Solution mySolution;

    
    cout << "--- Test Case 1: No Cycle ---" << endl;
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    
    cout << "List: 1 -> 2 -> 3 -> 4 -> NULL" << endl;
    cout << "Has cycle? " << (mySolution.hasCycle(list1) ? "true" : "false") << endl;

    
    cout << "\n--- Test Case 2: Has a Cycle ---" << endl;
    ListNode* list2 = new ListNode(1);
    ListNode* cycleNode = new ListNode(2); 
    list2->next = cycleNode;
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(4);
    ListNode* tail = list2->next->next->next; 
    
    
    tail->next = cycleNode;

    cout << "List: 1 -> 2 -> 3 -> 4 -> (points back to 2)" << endl;
    cout << "Has cycle? " << (mySolution.hasCycle(list2) ? "true" : "false") << endl;

    return 0;
}