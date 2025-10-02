#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node *head);
Node* addToFront(Node *head, float value);
Node* addToTail(Node *head, float value);
Node* deleteNode(Node *head, int position);
Node* insertNode(Node *head, int position, float value);
void deleteList(Node *&head);

int main() {
    Node *head = nullptr;
    srand(time(0));

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addToFront(head, tmp_val);
    }
    output(head);
        
    // delete node
    cout << "Which node to delete?" << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    head = deleteNode(head, entry);
    output(head);

    // insert node
    cout << "After which node to insert 10000" << endl;
    output(head);
    cin >> entry;
    head = insertNode(head, entry, 10000);
    output(head);

    // add to tail
    head = addToTail(head, 500);
    cout << "After adding 500 to the tail:" << endl;
    output(head);

    // delete entire list
    deleteList(head);
    output(head);

    return 0;
}

void output(Node * head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// adds node at head
Node* addToFront(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode; // new head
}

// add node to tail
Node* addToTail(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if(!head) return newNode;

    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// delete node at position
Node* deleteNode(Node *head, int position) {
    if (!head) return nullptr;

    Node *current = head;
    if (position == 1) { //delete head
        head = head->next;
        delete current;
        return head;
    }

    Node *prev = head;
    for (int i = 1; i < position -1 && prev->next; i++) {
        prev = prev->next;
    }

    current = prev->next;
    if (current) {
        prev->next = current->next;
        delete current;
    }
    return head;
}

// insert node after given position
Node* insertNode(Node *head, int position, float value) {
    Node* newNode = new Node;
    newNode->value = value;

    int length = 0;
    Node *temp = head;
    while (temp) {
        length++;
        temp = temp->next;
    }

    if (position < 0 || position > length) {
        cout << "Invalid position!\n";
        delete newNode;
        return head;
    }

    if (position == 0) { // insert at front
        newNode->next = head;
        return newNode;
    }

    Node *current = head;
    for (int i = 1; i < position && current; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// deleting the linked list
void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}