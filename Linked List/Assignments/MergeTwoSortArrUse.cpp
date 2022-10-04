#include <iostream>
using namespace std;
#include "MergeTwoSortArr.cpp"

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    // Write your code here
    Node *head = NULL, *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->next;
            }
            else
            {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }
    }
    while (head1 != NULL)
    {
        if (head == NULL)
        {
            head = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
    }
    while (head2 != NULL)
    {
        if (head == NULL)
        {
            head = head2;
            tail = head2;
            head2= head2->next;
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    return head;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
        print(head3);
    }
    return 0;
}