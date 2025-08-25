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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* firstNode = curr;
            ListNode* secondNode = curr->next;

            prev->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            prev = firstNode;
            curr = firstNode->next;
        }
        
        return dummy.next;
    }
};

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(nums[0]);
    ListNode* tail = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        tail->next = new ListNode(nums[i]);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution mySolution;

    cout << "--- Test Case 1 ---" << endl;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* list1 = createList(nums1);
    
    cout << "Original List: ";
    printList(list1);

    ListNode* swappedList1 = mySolution.swapPairs(list1);
    
    cout << "Swapped List:  ";
    printList(swappedList1);

    cout << "\n--- Test Case 2 ---" << endl;
    vector<int> nums2 = {1, 2, 3, 4};
    ListNode* list2 = createList(nums2);

    cout << "Original List: ";
    printList(list2);

    ListNode* swappedList2 = mySolution.swapPairs(list2);
    
    cout << "Swapped List:  ";
    printList(swappedList2);

    return 0;
}