#include<iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=nullptr;
    }

};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* tail=&dummy;
        
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
    

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<list2->val){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
                }
                tail=tail->next;
                
            }
        if(list1!=nullptr){
                tail->next=list1;
            }
        else{
                tail->next=list2;
            }
            return dummy.next;

        }
        
    };
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
}
int main() {
    
    Solution mySolution;
    
    
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    
    ListNode* result = mySolution.mergeTwoLists(list1, list2);
    
    cout << "Merged List: ";
    printList(result); 

    cout << "Test complete." << endl;
    return 0;
}
