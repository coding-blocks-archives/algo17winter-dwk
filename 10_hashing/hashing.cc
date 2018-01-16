// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;
};

class Hashmap {
    Node * *table;
    int capacity;
    int sze;

    int hashFunction(const string& s) {
        int mul = 1;
        int code = 0;
        const int M = 31;
        const int MOD = capacity;

        for (int i = 0; i < s.size(); ++i) {
            int x = (s[i]  % capacity) * (mul % capacity) % capacity;
            code = (code % capacity + x % capacity) % capacity;
            mul = (mul % capacity) * (M % capacity) % capacity;
        }
        cout << "code against " << s << " is " << code << endl;
        return code;
    }

    void insertIntoTable(Node* tmp) {
        int hashCode = hashFunction(tmp->key);
        int idx = hashCode % capacity;

        Node* &head = table[idx];
        if (head == NULL) {
            head = tmp;
        } else {
            // insert at front
            tmp->next = head;
            head = tmp;
        }
        ++sze;
    }

    double loadFactor() {
        return (double)sze / capacity;
    }

    void rehash() {
        Node** oldTable = table;
        int oldCapacity = capacity;
        capacity = 2 * capacity;
        sze = 0;

        table = new Node*[capacity]();  // initialisation is MUST

        for (int i = 0; i < oldCapacity; ++i) {
            Node* head = oldTable[i];   // list
            while (head) {
                Node* ahead = head->next;
                head->next = NULL;
                insertIntoTable(head);
                head = ahead;
            }
        }
        delete [] oldTable;
    }

public:
    Hashmap() {
        cout << "Welcome...constructing your Hashmap\n";
        capacity = 7;
        sze = 0;
        table = new Node*[capacity]();  // initialisation
    }

    void insert(const string& s, int val) {
        if (loadFactor() > 0.7) {
            cout << "lf is " << loadFactor() << ". Rehashing...\n";
            rehash();
        }

        Node* tmp = new Node;
        tmp->key = s;
        tmp->val = val;
        tmp->next = NULL;

        insertIntoTable(tmp);
    }

    void remove(const string& s) {
        int idx = hashFunction(s) % capacity;
        Node * head = table[idx];
        // search s in the head and delete
        // --sze;
    }

    bool empty() {
        return sze == 0;
    }

    int valAt(const string& s) {
        int idx = hashFunction(s) % capacity;
        cout << "idx is " << idx << endl;
        Node* head = table[idx];
        // search if found return val
        // return -1

        while (head) {
            if (head->key == s) {
                return head->val;
            }
            head = head->next;
        }
        return -1;
    }

    ~Hashmap() {
        for (int i = 0; i < capacity; ++i) {
            Node* head = table[i];
            while (head) {
                Node* ahead = head->next;
                delete head;
                head = ahead;
            }
        }
        delete [] table;
        cout << "Dtor completed...Bye!!!\n";
    }

};


int main() {
    Hashmap h;
    h.insert("tina", 123);
    h.insert("meena", 456);
    h.insert("katrina", 678);
    h.insert("salman", 4567);
    cout << "==========" << endl;
    cout << h.valAt("salman") << endl;
    cout << h.valAt("katrina") << endl;
    cout << h.valAt("kareena") << endl;
    cout << "==========" << endl;
    h.insert("meena1", 456);
    h.insert("katrina1", 678);
    h.insert("salman1", 4567);
    h.insert("meena2", 456);
    // h.insert("katrina", 678);
    // h.insert("salman", 4567);

}