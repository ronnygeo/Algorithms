//
// Created by Ronny Mathew on 3/8/16.
//

int maxhash = 10000;

int hash[maxhash];

struct Node {
    int key;
    int count;
    Node* next;
};

Node* insertNode(int val, Node* tail){
    Node* cur;
    cur = new Node;
    cur->value = val;
    cur->next = NULL;
    tail->next = cur;
    tail = tail->next;
    return tail;
}

int hash_function(char[]) {
    int sum = 0, i = 0;

    while (char[i] > 0){
        sum += char[i] * (++i) * i;
    }
    return sum % MAXHASH;
}
void insert(key,value){}

int delete(key){}

int increase(key){}

int find(key){}


void listAllKeys(){}