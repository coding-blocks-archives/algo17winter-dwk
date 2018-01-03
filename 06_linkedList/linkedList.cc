// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

/*Node createLL(){ // WRONG
    Node n1;
    Node n2;
    n1.data = 10;
    n2.data = 20;
    n1.next = &n2;
    return n1;
}
*/

Node* createLL(){
    Node* head = NULL;
    Node* tail = NULL;
    int x;
    while(true){
        cin >> x;
        if (x == -1) break;

        Node* curNode = new Node;
        // curNode.data = x;
        (*curNode).data = x;
        curNode->next = NULL;   // same 

        if (head == NULL){
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


void printLL(Node* head){
    Node* cur = head;

    // while(cur != NULL){
    while(cur){
        cout << cur->data << "-->";
        cur = cur->next;
    }
}

int length(Node* head){
    Node* cur = head;
    int cnt = 0;
    while(cur){
        ++cnt;
        cur = cur->next;
    }
    return cnt;
}

Node* mergeSortedLL(Node* a, Node* b){
    if (!a && !b) return NULL;
    
    if (!a) return b;
    if (!b) return a;

    // both a && b are there
    if (a->data < b->data){
        a->next = mergeSortedLL(a->next, b);
        return a;
    } else {
        b->next = mergeSortedLL(a, b->next);
        return b;
    }
}


Node* midPoint(Node* head){

    //Get, set
    Node* slow = head;
    Node* fast = head;

    // Go
    while(slow && fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printNode(Node* mid){
    cout << mid  << " ";
    if (mid) cout << mid->data;
    cout << endl;
}

int main(){
    // Node* head = createLL();
    // printLL(head);

    // Node* a = createLL();
    // Node* b = createLL();
    // Node* ans = mergeSortedLL(a, b);
    // printLL(ans);

    // Node* head = createLL();
    // Node* mid = midPoint(head);
    // printNode(mid);
}