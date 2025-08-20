#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
       this->data=data;
       this->next=nullptr;
    }
};
Node *insertAtHead(Node *head, int x){
    Node *temp=new Node(x);
    temp->next=head;
    head=temp;
    return head;
}
Node *insertAtTail(Node *head, int x){
    Node *temp=new Node(x);
    if(head==NULL) return temp;
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=NULL;
    return head;
}
int search(Node *head, int x){
    int pos=1;
    Node *curr=head;
    while(curr!=NULL){
        if(curr->data==x){
            return pos;
        }
        else{
            pos++;
            curr=curr->next;
        }
    }
    return -1;
}
void print_list(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

}
Node *takeinput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *prev=NULL;
    while(data!=-1){
        Node *input=new Node(data);
        if(head==NULL){
            head=input;
            prev=input;
        }
        else{
            prev->next=input;
            prev=input;
        }
        cin>>data;
    }
    return head;

}
Node *insertAtPosition(Node *head, int value, int pos){
    Node* temp=new Node(value);
    if(pos<0){
        cout<<"Invalid Position"<<endl;
        delete temp;
        return head;
    }
    Node* curr=head;
    if(pos==1){
        temp->next=head;
        return temp;
    }
    for(int i=1;i<pos-1 && curr!= NULL;i++){
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<"Position out of bounds"<<endl;
        delete temp;
        return head;

    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
Node* deleteByValue(Node* head, int value){
    while(head!=NULL && head->data==value){
        Node* temp=head;
        head=head->next;
        delete(temp);
    }
    if(head==NULL)
    return NULL;
    Node* curr=head->next;
    Node* prev=head;
    while(curr!=NULL){
        if(curr->data==value){
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
        
        
    }
    return head;

}
int main(){
    Node* head = nullptr; 
    int choice;
    int data, position;

    do {
        cout << "\n--- Linked List Menu ---" << endl;
        cout << "1. Create a new list" << endl;
        cout << "2. Print the list" << endl;
        cout << "3. Insert at Head" << endl;
        cout << "4. Insert at Tail" << endl;
        cout << "5. Search for an element" << endl;
        cout << "6. Insert at any position" << endl;
        cout << "7. Delete by value" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice){
            case 1:
                head = takeinput();
                break;
            case 2:
                cout << "Current list: ";
                print_list(head);
                break;
            case 3:
                cout << "Enter data to insert at head: ";
                cin >> data;
                head = insertAtHead(head, data);
                cout << data << " inserted at the head." << endl;
                break;
            case 4:
                cout << "Enter data to insert at tail: ";
                cin >> data;
                head = insertAtTail(head, data);
                cout << data << " inserted at the tail." << endl;
                break;
            case 5:
                cout << "Enter element to search for: ";
                cin >> data;
                position = search(head, data);
                if (position != -1) {
                    cout << "Element " << data << " found at position " << position << "." << endl;
                } else {
                    cout << "Element " << data << " not found in the list." << endl;
                }
                break;
            case 6: 
                 cout<<"Enter the data to insert: "<<endl;
                 cin>>data;
                 cout<<"Enter the position to insert: "<<endl;
                 cin>>position;
                 head=insertAtPosition(head,data, position);
                 break;
            case 7:
                  cout<<"Enter value to delete: "<<endl;
                  cin>>data;
                  head=deleteByValue(head, data);
                  break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}


