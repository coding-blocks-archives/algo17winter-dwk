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

int main(){
    Node* head = createLL();
    printLL(head);
}