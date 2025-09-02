#include <iostream>
#include <climits> // Required for INT_MIN

using namespace std;

class myStack{
private:
    int *arr;
    int capacity;
    int top;

public:
    myStack(int n) {
        capacity = n;
        top = -1;
        arr = new int[n];
    }

    ~myStack() {
        delete[] arr;
    }
 
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow: Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " pushed to the stack." << endl;
    }
 
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow: Stack is empty" << endl;
            return INT_MIN;
        }
        int res = arr[top];
        top--;
        return res;
    }
 
    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return arr[top];
    }
 
    int size() {
        return (top + 1);
    }
 
    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    myStack s(capacity);
    int choice;
    int value;

    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek (Top)" << endl;
        cout << "4. Get Size" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2: {
                int poppedValue = s.pop();
                if (poppedValue != INT_MIN) {
                    cout << "Popped value: " << poppedValue << endl;
                }
                break;
            }
            case 3: {
                int topValue = s.peek();
                if (topValue != INT_MIN) {
                    cout << "Top element is: " << topValue << endl;
                }
                break;
            }
            case 4:
                cout << "Current stack size: " << s.size() << endl;
                break;
            case 5:
                cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
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