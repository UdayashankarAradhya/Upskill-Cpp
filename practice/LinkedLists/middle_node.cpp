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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *temp = head;
        int n = 0;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        
        int mid = n / 2;
        ListNode* curr = head;
        for (int i = 0; i < mid; i++) {
            curr = curr->next;
        }
        
        return curr;
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

    ListNode* middle1 = mySolution.middleNode(list1);
    cout << "Middle starts at: ";
    printList(middle1);

    
    cout << "\n--- Test Case 2 ---" << endl;
    vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    ListNode* list2 = createList(nums2);

    cout << "Original List: ";
    printList(list2);

    ListNode* middle2 = mySolution.middleNode(list2);
    cout << "Middle starts at: ";
    printList(middle2);

    return 0;
}