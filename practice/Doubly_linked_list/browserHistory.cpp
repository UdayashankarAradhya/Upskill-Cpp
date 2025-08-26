#include <iostream>
#include <string>

using namespace std;

class BrowserHistory {
private:
    struct Node {
        string url;
        Node* next;
        Node* prev;
        Node(string text): url(text), next(nullptr), prev(nullptr) {}
    };
    Node* currPage;

public:
    BrowserHistory(string homepage) {
        currPage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        currPage->next = newNode;
        newNode->prev = currPage;
        currPage = newNode;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (currPage->prev != nullptr) {
                currPage = currPage->prev;
            } else {
                break; // Stop if we hit the beginning
            }
        }
        return currPage->url;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (currPage->next != nullptr) {
                currPage = currPage->next;
            } else {
                break; // Stop if we hit the end
            }
        }
        return currPage->url;
    }
};

int main() {
    cout << "Simulating LeetCode test case..." << endl;

    // ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
    // [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]

    BrowserHistory* history = new BrowserHistory("leetcode.com");
    history->visit("google.com");
    history->visit("facebook.com");
    history->visit("youtube.com");
    cout << "back(1): " << history->back(1) << endl;         // Expected: "facebook.com"
    cout << "back(1): " << history->back(1) << endl;         // Expected: "google.com"
    cout << "forward(1): " << history->forward(1) << endl;   // Expected: "facebook.com"
    history->visit("linkedin.com");
    cout << "forward(2): " << history->forward(2) << endl;   // Expected: "linkedin.com"
    cout << "back(2): " << history->back(2) << endl;         // Expected: "google.com"
    cout << "back(7): " << history->back(7) << endl;         // Expected: "leetcode.com"

    delete history; // Clean up memory
    return 0;
}