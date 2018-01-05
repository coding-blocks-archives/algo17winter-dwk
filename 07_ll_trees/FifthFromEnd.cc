#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* createLL() {
    Node* head = NULL;
    Node* tail = NULL;
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;

        Node* curNode = new Node;
        // curNode.data = x;
        (*curNode).data = x;
        curNode->next = NULL;   // same

        if (head == NULL) {
            // this is the first node of the LL
            head = curNode;
            tail = curNode;
        } else {
            tail->next = curNode;
            tail = curNode;
        }
    }
    return head;
}


void printLL(Node* head) {
    Node* cur = head;

    // while(cur != NULL){
    while (cur) {
        cout << cur->data << "-->";
        cur = cur->next;
    }
}

void printNode(Node* mid) {
    cout << mid  << " ";
    if (mid) cout << mid->data;
    cout << endl;
}

Node* fifthLast(Node* head) {
    Node* cur = head;
    int i = 1;
    while (i < 5 && cur) {
        cur = cur->next;
        ++i;
    }

    if (i < 5 || !cur) return NULL;

    Node* start = head;
    while (cur->next) {
        start = start->next;
        cur = cur->next;
    }
    return start;
}


int lengthLL(Node* head) {
    Node* cur = head;
    int cnt = 0;
    while (cur) {
        ++cnt;
        cur = cur->next;
    }
    return cnt;
}

Node* bubbleSort(Node* head) {
    int len = lengthLL(head);

    for (int i = 0; i < len; ++i) {
        Node* cur = head;
        Node* previousNode = NULL;
        
        // if we have 2 nodes
        while (cur && cur->next) {
            // either swap or does not swap
            Node* ahead = cur->next;
            if (cur->data > ahead->data) {
                // swapping
                // swapping with head
                if (cur == head) {
                    cur->next = ahead->next;
                    ahead->next = cur;
                    head = ahead;
                    previousNode = ahead;
                } else {
                    // head remains constant
                    cur->next = ahead->next;
                    ahead->next = cur;
                    previousNode->next = ahead;
                    previousNode = previousNode->next;
                }
            } else {
                // no swapping
                previousNode = cur;
                cur = cur->next;
            }
        }
    }
    return head;
}

int main() {
    Node* head = createLL();
    
    // Node* fifth = fifthLast(head);
    // printNode(fifth);

    head = bubbleSort(head);
    printLL(head);


}