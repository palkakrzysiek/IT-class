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


int main(int argc, char const* argv[])
{
    Node *P = new Node;
    P -> next = NULL;
    return 0;
}
