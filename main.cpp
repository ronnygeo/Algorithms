/* Two linked lists (simple link, not double link) heads are given: headA, and headB;
it is also given that the two lists intersect, thus after the intersection they have
the same elements to the end. Find the first common element, without modifying the
lists elements or using additional datastructures. */

#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

int countList(Node* head);
void printList(Node* head);
Node* insertNodeOneList(int val, Node*& tail,  Node*& head);
Node* insertNodeBothLists(int val, Node*& tail, Node*& head, Node*& otherTail, Node*& headB);
Node* findIntersection(Node* head1, Node* head2);


int main() {
    Node* headA = NULL;
    Node* headB = NULL;
    Node* tailA = NULL;
    Node* tailB = NULL;

    insertNodeOneList(5, tailA, headA);
    insertNodeOneList(6, tailA, headA);
    insertNodeOneList(7, tailA, headA);

    insertNodeOneList(10, tailB, headB);
    insertNodeOneList(11, tailB, headB);
    insertNodeOneList(12, tailB, headB);

    insertNodeBothLists(20, tailA, headA, tailB, headB);
    insertNodeBothLists(30, tailA, headA, tailB, headB);


    cout<<tailA<<headA<<"\n";
    cout<<tailB<<headB<<"\n";

    cout << "List 1 "<< endl;
    printList(headA);
    cout << endl;

    cout << "List 2" <<endl;
    printList(headB);
    cout << endl;

    findIntersection(headA, headB);

    return 0;
}

Node* insertNodeOneList(int val, Node*& tail,  Node*& head) {
    Node* current;
    current = new Node;
    current->value = val;
    current->next = NULL;
    if (head == NULL) {
        head = current;
    }
    if (tail == NULL) {
        tail = current;
    } else {
        tail->next = current;
        tail = tail->next;
    }
}

Node* insertNodeBothLists(int val, Node*& tail, Node*& head, Node*& tailB, Node*& headB) {
    Node* current;
    current = new Node;
    current->value = val;
    current->next = NULL;
    if (head == NULL) {
        head = current;
    }
    if (headB == NULL) {
        headB = current;
    }
    if (tail == NULL) {
        tail = current;
    } else {
        tail->next = current;
        tail = tail->next;
    }
    if (tailB == NULL) {
        tailB = current;
    } else {
        tailB->next = current;
        tailB = tailB->next;
    }


}


int countList(Node* head){
    int count = 1;
    Node* cursor;

    cursor = head;

    while (cursor->next != NULL){
        count++;
        cursor = cursor->next;
    }
    return count;
}

void printList(Node* head){
    Node* cursor;
    cursor = head;

    while (cursor != NULL){
        cout << cursor->value << endl;
        cursor = cursor->next;
    }
}

Node* findIntersection(Node* head1, Node* head2){
    int m = countList(head1);
    int n = countList(head2);
    int d, i;
    Node* cursorA = head1;
    Node* cursorB = head2;
    cout << "Length of first list: " << m << " second list: " << n << endl;

    if (m > n){
        d = m-n;
        while (d!=0){
            cursorA = cursorA->next;
            d--;
        }
    }

    else if (m < n){
        d = n-m;
        while (d!= 0){
            cursorB = cursorB->next;
            d--;
        }
    }
    i = min(m,n);
    cout<<"Simultaneous Traversal"<< endl;
    while (i != 0){
        if (cursorA == cursorB){
            cout<<"Intersection Node: "<<cursorA->value;
            return cursorA;
        }

        cout<< cursorA->value << " " << cursorB->value<< endl;
        cursorA = cursorA->next;
        cursorB = cursorB->next;
        i--;
    }
    return NULL;
}
