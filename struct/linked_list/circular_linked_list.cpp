// C++ program to implement
// the above approach
#include <iostream>
using namespace std;

/* structure for a node */
class Node
{
public:
    int data;
    Node *next;
};

/* Function to insert a node at the beginning
of a Circular linked list */
void push(Node **head_ref, int data)
{
    Node *ptr1 = new Node();
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    /* If linked list is not NULL then
    set the next of last node */
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */

    *head_ref = ptr1;
}

/* Function to split a list (starting with head)
into two lists. head1_ref and head2_ref are
references to head nodes of the two resultant
linked lists */
void splitList(Node *head, Node **head1_ref,
               Node **head2_ref)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if (head == NULL)
        return;

    /* If there are odd nodes in the circular list then
       fast_ptr->next becomes head and for even nodes
       fast_ptr->next->next becomes head */
    while (fast_ptr->next != head &&
           fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    /* If there are even elements in list
       then move fast_ptr */
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    /* Set the head pointer of first half */
    *head1_ref = head;

    /* Set the head pointer of second half */
    if (head->next != head)
        *head2_ref = slow_ptr->next;

    /* Make second half circular */
    fast_ptr->next = slow_ptr->next;

    /* Make first half circular */
    slow_ptr->next = head;
}

/* Function to delete a given node from the list */
void deleteNode(Node **head, int key)
{

    // If linked list is empty
    if (*head == NULL)
        return;

    // If the list contains only a single node
    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *last = *head, *d;

    // If head is to be deleted
    if ((*head)->data == key)
    {

        // Find the last node of the list
        while (last->next != *head)
            last = last->next;

        // Point last node to the next of head i.e.
        // the second node of the list
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
        return;
    }

    // Either the node to be deleted is not found
    // or the end of list is not reached
    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }

    // If node to be deleted was found
    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else
        cout << "no such keyfound";
}

/* Function to print nodes in
a given Circular linked list */
void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

/* Driver program to test above functions */
int main()
{
    int list_size, i;

    /* Initialize lists as empty */
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;

    /* Created linked list will be 12->56->2->11 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 7);
    push(&head, 2);
    push(&head, 11);

    deleteNode(&head, 2);

    cout << "Original Circular Linked List";
    printList(head);

    /* Split the list */
    splitList(head, &head1, &head2);

    cout << "\nFirst Circular Linked List";
    printList(head1);

    cout << "\nSecond Circular Linked List";
    printList(head2);
    return 0;
}

// This is code is contributed by rathbhupendra
