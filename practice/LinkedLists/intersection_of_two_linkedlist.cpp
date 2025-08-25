#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        int lenA = 0;
        ListNode* pA = headA;
        while (pA != nullptr) {
            lenA++;
            pA = pA->next;
        }

        int lenB = 0;
        ListNode* pB = headB;
        while (pB != nullptr) {
            lenB++;
            pB = pB->next;
        }

        pA = headA;
        pB = headB;

        if (lenA > lenB) {
            int diff = lenA - lenB;
            for (int i = 0; i < diff; i++) {
                pA = pA->next;
            }
        } else {
            int diff = lenB - lenA;
            for (int i = 0; i < diff; i++) {
                pB = pB->next;
            }
        }

        while (pA != pB) {
            if (pA == nullptr || pB == nullptr) {
                return nullptr;
            }
            pA = pA->next;
            pB = pB->next;
        }
        
        return pA;
    }
};

int main() {
    Solution mySolution;

    cout << "--- Test Case 1: Intersection ---" << endl;
    
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode* intersection = mySolution.getIntersectionNode(headA, headB);

    if (intersection != nullptr) {
        cout << "Intersection found at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    cout << "\n--- Test Case 2: No Intersection ---" << endl;
    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(6);
    
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(5);

    ListNode* noIntersection = mySolution.getIntersectionNode(list1, list2);
    
    if (noIntersection != nullptr) {
        cout << "Intersection found at node with value: " << noIntersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}