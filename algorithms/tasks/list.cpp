// Let the following structure definitions be given:

struct Node{
    Node *next;
    double w;
}

struct List{
    Node *head;
    Node *wart;
}

// Initial conditions:
// Empty list has head == NULL
// Field next of the last node in the list is set NULL

// Problem 1:
// Write a function adding new element to an existing list at its beginning:

