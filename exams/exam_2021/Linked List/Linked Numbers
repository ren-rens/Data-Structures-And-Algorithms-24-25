#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *next;
    Node *prev;
    
    int data;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node *temp;
        
        while (head != nullptr) {
            temp = head;
            head = head->next;
            
            delete temp;
        }
    }
    void add(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        temp->prev = nullptr;

        if (head == nullptr && tail == nullptr) {
            head = tail = temp;
        } 
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void printNumber() {
        Node* curr = tail;
        while (curr) {
            cout << curr->data;
            curr = curr->prev;
        }
        cout << endl;
    }

    Node *head, *tail;
};

void solve(LinkedList &num1, LinkedList &num2) {
    LinkedList result;

    Node *cur1 = num1.head;
    Node *cur2 = num2.head;
    
    int carry = 0;

    while (cur1 || cur2 || carry) {
        int sum = carry;
        if (cur1) {
            sum += cur1->data;
            cur1 = cur1->next;
        }
        if (cur2) {
            sum += cur2->data;
            cur2 = cur2->next;
        }

        result.add(sum % 10);
        carry = sum / 10;
    }

    result.printNumber();
}

int main() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}
