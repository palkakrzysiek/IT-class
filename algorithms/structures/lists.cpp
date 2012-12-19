#include <cstdio>
using namespace std;
struct Node{
    int value;
    Node *next;
};

Node* addFront(Node *head, int x){
    Node *n = new Node;
    n->value = x;
    n -> next = head;
    head = n;
    return n;
}

Node* createNode(int x){ // x - initial value
    Node *n = new Node;
    n -> value = x;
    n -> next = NULL;
    return n;
}

Node* findNode(Node *head, int x){
    Node *current = head;
    while(current != NULL){
        if(current -> value == x)
            return current;
        current = current -> next;
    }
    return NULL;
}

Node* removeNode(Node *head, Node *element){
    if(head == element){
        Node *temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    if(element -> next == NULL){
        delete element;
        return head;
    }
    Node *current = head -> next;
    Node *prev = head;
    while(current != NULL){
        if(current == element){
            prev = element -> next;
            delete element;
        }
        prev = current;
    }
    return head;
}

int readNode(Node *head, int n){
    int counter = 0;
    while(counter++ != n){
        if(head -> next == NULL){
            fprintf(stderr, "index outside the offset\n");
        }
        else{
        head = head -> next;
        }
    }
    return head -> value;
}


int main(int argc, char const* argv[])
{
    Node *P = createNode(3);
    P = addFront(P, 4);
    P = addFront(P, 7);
    printf("%d", readNode(P, 0));
    
    return 0;
}
