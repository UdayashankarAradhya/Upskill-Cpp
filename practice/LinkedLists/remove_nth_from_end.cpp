#include <iostream>
#include <vector>

using namespace std;


class Node{
public:
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {} 
}; 


Node* createList(const vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    Node* head = new Node(nums[0]);
    Node* tail = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        tail->next = new Node(nums[i]);
        tail = tail->next;
    }
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

class Solution{
public:
    Node* removeNthFromEnd(Node* head, int n){
        Node* temp = head;
        int count = 0; 

        while(temp != nullptr){
            temp = temp->next;
            count++;
        }
        
        
        if(n == count){
           Node* newHead = head->next; 
           delete head;
           return newHead;
        }

       
        else {
            
            Node* prev = head;
            for(int i = 0; i < count - n - 1; i++){
                prev = prev->next;
            }
            
           
            Node* nodeToDelete = prev->next; 
            prev->next = nodeToDelete->next; 
            delete nodeToDelete; 
            
            return head;
        }
    }
};

int main(){
    Solution mySolution;

    
    cout << "--- Test Case 1 ---" << endl;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    Node* list1 = createList(nums1);
    cout << "Original List: ";
    printList(list1);
    
    cout << "Removing 2nd node from end..." << endl;
    list1 = mySolution.removeNthFromEnd(list1, 2); 
    
    cout << "Modified List: ";
    printList(list1);

    
    cout << "\n--- Test Case 2 ---" << endl;
    vector<int> nums2 = {1, 2, 3};
    Node* list2 = createList(nums2);
    cout << "Original List: ";
    printList(list2);

    cout << "Removing 3rd node from end..." << endl;
    list2 = mySolution.removeNthFromEnd(list2, 3); // Should remove 1
    
    cout << "Modified List: ";
    printList(list2);

    return 0;
}